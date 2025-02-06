/********************************************************************************
** Form generated from reading UI file 'addpersondialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPERSONDIALOG_H
#define UI_ADDPERSONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddPersonDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_name;
    QLabel *label;

    void setupUi(QDialog *AddPersonDialog)
    {
        if (AddPersonDialog->objectName().isEmpty())
            AddPersonDialog->setObjectName("AddPersonDialog");
        AddPersonDialog->resize(200, 100);
        buttonBox = new QDialogButtonBox(AddPersonDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 70, 181, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        lineEdit_name = new QLineEdit(AddPersonDialog);
        lineEdit_name->setObjectName("lineEdit_name");
        lineEdit_name->setGeometry(QRect(10, 35, 180, 24));
        label = new QLabel(AddPersonDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 10, 49, 16));

        retranslateUi(AddPersonDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddPersonDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddPersonDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddPersonDialog);
    } // setupUi

    void retranslateUi(QDialog *AddPersonDialog)
    {
        AddPersonDialog->setWindowTitle(QCoreApplication::translate("AddPersonDialog", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("AddPersonDialog", "Name", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddPersonDialog: public Ui_AddPersonDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPERSONDIALOG_H
