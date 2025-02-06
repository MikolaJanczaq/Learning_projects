#include "addbookdialog.h"
#include "ui_addbookdialog.h"

AddBookDialog::AddBookDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBookDialog)
{
    ui->setupUi(this);
}

AddBookDialog::~AddBookDialog()
{
    delete ui;
}

QString AddBookDialog::getTitle() const
{
    return ui->lineEdit_title->text();
}

QString AddBookDialog::getAuthor() const
{
    return ui->lineEdit_author->text();
}
