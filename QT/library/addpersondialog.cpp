#include "addpersondialog.h"
#include "ui_addpersondialog.h"

AddPersonDialog::AddPersonDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonDialog)
{
    ui->setupUi(this);
}

AddPersonDialog::~AddPersonDialog()
{
    delete ui;
}

QString AddPersonDialog::getName() const
{
    return ui->lineEdit_name->text();
}
