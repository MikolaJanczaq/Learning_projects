#include "rentbookdialog.h"
#include "ui_rentbookdialog.h"

RentBookDialog::RentBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RentBookDialog)
{
    ui->setupUi(this);
    ui->dateEdit_returnDate->setDate(QDate::currentDate().addDays(14)); // Domyślna data: za 14 dni
}

RentBookDialog::~RentBookDialog()
{
    delete ui;
}

void RentBookDialog::setBookDetails(const QString &title, const QString &author)
{
    ui->label_bookTitle->setText(title);
    ui->label_bookAuthor->setText(author);
}

void RentBookDialog::setPersonName(const QString &name)
{
    ui->label_personName->setText(name);
}

QDate RentBookDialog::getReturnDate() const
{
    return ui->dateEdit_returnDate->date();
}
