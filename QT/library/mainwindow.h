#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addBook();
    void deleteBook();
    void rentBook();
    void returnBook();
    void addPerson();
    void deletePerson();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel *booksModel;
    QSqlTableModel *peopleModel;
    QSqlTableModel *rentsModel;

    void setupDatabase();
    void setupModels();
    void loadBooks();
    void loadRents();
    void loadPeople();
};
#endif // MAINWINDOW_H
