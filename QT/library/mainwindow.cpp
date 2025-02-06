#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "addbookdialog.h"
#include "addpersondialog.h"
#include "rentbookdialog.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setupDatabase();
    setupModels();

    connect(ui->pushButton_addBook, &QPushButton::clicked, this, &MainWindow::addBook);
    connect(ui->pushButton_delBook, &QPushButton::clicked, this, &MainWindow::deleteBook);
    connect(ui->pushButton_rent, &QPushButton::clicked, this, &MainWindow::rentBook);
    connect(ui->pushButton_return, &QPushButton::clicked, this, &MainWindow::returnBook);
    connect(ui->pushButton_addPerson, &QPushButton::clicked, this, &MainWindow::addPerson);
    connect(ui->pushButton_delPerso, &QPushButton::clicked, this, &MainWindow::deletePerson);

}

MainWindow::~MainWindow()
{
    delete ui;
    db.close();
}

void MainWindow::setupDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(":memory:");
    if (!db.open()) {
        QMessageBox::critical(this, "Database Error", db.lastError().text());
        return;
    }

    QSqlQuery query;

    query.exec("CREATE TABLE books ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "title TEXT NOT NULL, "
               "author TEXT NOT NULL)");

    query.exec("CREATE TABLE people ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "name TEXT NOT NULL)");

    query.exec("CREATE TABLE rents ("
               "id INTEGER PRIMARY KEY AUTOINCREMENT, "
               "book_id INTEGER NOT NULL, "
               "person_id INTEGER NOT NULL, "
               "return_date TEXT NOT NULL, "
               "FOREIGN KEY(book_id) REFERENCES books(id), "
               "FOREIGN KEY(person_id) REFERENCES people(id))");

    query.exec("INSERT INTO books (title, author) VALUES ('The Great Gatsby', 'F. Scott Fitzgerald')");
    query.exec("INSERT INTO books (title, author) VALUES ('1984', 'George Orwell')");
    query.exec("INSERT INTO books (title, author) VALUES ('To Kill a Mockingbird', 'Harper Lee')");

    query.exec("INSERT INTO people (name) VALUES ('John Doe')");
    query.exec("INSERT INTO people (name) VALUES ('Jane Smith')");
    query.exec("INSERT INTO people (name) VALUES ('Alice Johnson')");

    query.exec("INSERT INTO rents (book_id, person_id, return_date) VALUES (1, 1, '2025-01-01')");
    query.exec("INSERT INTO rents (book_id, person_id, return_date) VALUES (2, 2, '2025-02-01')");
    query.exec("INSERT INTO rents (book_id, person_id, return_date) VALUES (3, 3, '2025-03-01')");
}

void MainWindow::setupModels()
{
    booksModel = new QSqlTableModel(this, db);
    booksModel->setTable("books");
    booksModel->select();
    ui->tableView_books->setModel(booksModel);

    peopleModel = new QSqlTableModel(this, db);
    peopleModel->setTable("people");
    peopleModel->select();
    ui->tableView_people->setModel(peopleModel);

    rentsModel = new QSqlTableModel(this, db);
    rentsModel->setTable("rents");
    rentsModel->select();
    ui->tableView_rents->setModel(rentsModel);
    loadBooks();
    loadPeople();
    loadRents();
}

void MainWindow::addBook()
{
    AddBookDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString title = dialog.getTitle();
        QString author = dialog.getAuthor();

        QSqlQuery query;
        query.prepare("INSERT INTO books (title, author) VALUES (?, ?)");
        query.addBindValue(title);
        query.addBindValue(author);
        if (!query.exec()) {
            QMessageBox::critical(this, "Error", query.lastError().text());
        }
        booksModel->select();
    }

    loadBooks();
}

void MainWindow::deleteBook()
{
    QItemSelectionModel *selection = ui->tableView_books->selectionModel();
    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "No Selection", "Please select a book to delete.");
        return;
    }

    QModelIndex index = selection->currentIndex();
    int bookId = index.sibling(index.row(), 0).data().toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM books WHERE id = ?");
    query.addBindValue(bookId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    query.prepare("DELETE FROM rents WHERE book_id = ?");
    query.addBindValue(bookId);
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Book deleted successfully.");

    loadBooks();
    loadRents();
}


void MainWindow::rentBook()
{
    QModelIndex bookIndex = ui->tableView_books->currentIndex();
    QModelIndex personIndex = ui->tableView_people->currentIndex();

    if (!bookIndex.isValid() || !personIndex.isValid()) {
        QMessageBox::warning(this, "Warning", "Please select a book and a person.");
        return;
    }

    QString bookTitle = booksModel->data(booksModel->index(bookIndex.row(), 1)).toString();
    QString bookAuthor = booksModel->data(booksModel->index(bookIndex.row(), 2)).toString();
    QString personName = peopleModel->data(peopleModel->index(personIndex.row(), 1)).toString();

    int bookId = booksModel->data(booksModel->index(bookIndex.row(), 0)).toInt();
    int personId = peopleModel->data(peopleModel->index(personIndex.row(), 0)).toInt();

    RentBookDialog dialog(this);
    dialog.setBookDetails(bookTitle, bookAuthor);
    dialog.setPersonName(personName);

    if (dialog.exec() == QDialog::Accepted) {
        QDate returnDate = dialog.getReturnDate();

        QSqlQuery query;
        QString sql = QString("INSERT INTO rents (book_id, person_id, return_date) VALUES (%1, %2, '%3')")
                          .arg(bookId)
                          .arg(personId)
                          .arg(returnDate.toString("yyyy-MM-dd"));

        if (!query.exec(sql)) {
            QMessageBox::critical(this, "Error", query.lastError().text());
            return;
        }

        rentsModel->select();
    }

    loadRents();
}

void MainWindow::returnBook()
{
    QModelIndex rentIndex = ui->tableView_rents->currentIndex();

    if (!rentIndex.isValid()) {
        QMessageBox::warning(this, "Warning", "Please select a rent record.");
        return;
    }

    int rentId = rentsModel->data(rentsModel->index(rentIndex.row(), 0)).toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM rents WHERE id = ?");
    query.addBindValue(rentId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    rentsModel->select();

    loadRents();
}

void MainWindow::addPerson()
{
    AddPersonDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {
        QString name = dialog.getName();

        QSqlQuery query;
        query.prepare("INSERT INTO people (name) VALUES (?)");
        query.addBindValue(name);
        if (!query.exec()) {
            QMessageBox::critical(this, "Error", query.lastError().text());
        }
        peopleModel->select();
    }

    loadPeople();
}

void MainWindow::deletePerson()
{
    QItemSelectionModel *selection = ui->tableView_people->selectionModel();
    if (!selection->hasSelection()) {
        QMessageBox::warning(this, "No Selection", "Please select a person to delete.");
        return;
    }

    QModelIndex index = selection->currentIndex();
    int personId = index.sibling(index.row(), 0).data().toInt();

    QSqlQuery query;
    query.prepare("DELETE FROM people WHERE id = ?");
    query.addBindValue(personId);

    if (!query.exec()) {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    query.prepare("DELETE FROM rents WHERE person_id = ?");
    query.addBindValue(personId);
    if (!query.exec()) {
        QMessageBox::critical(this, "Error", query.lastError().text());
        return;
    }

    QMessageBox::information(this, "Success", "Person deleted successfully.");

    loadPeople();
    loadRents();
}

void MainWindow::loadBooks()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT id, title, author FROM books");
    ui->tableView_books->setModel(model);
    ui->tableView_books->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::loadPeople()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);
    model->setQuery("SELECT id, name FROM people");
    ui->tableView_people->setModel(model);
    ui->tableView_people->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}

void MainWindow::loadRents()
{
    QSqlQueryModel *model = new QSqlQueryModel(this);

    model->setQuery("SELECT rents.id, books.title, books.author, people.name, rents.return_date "
                    "FROM rents "
                    "JOIN books ON rents.book_id = books.id "
                    "JOIN people ON rents.person_id = people.id");

    ui->tableView_rents->setModel(model);
    ui->tableView_rents->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
}
