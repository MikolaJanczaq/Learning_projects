/********************************************************************************
** Form generated from reading UI file 'addbookdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDBOOKDIALOG_H
#define UI_ADDBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_AddBookDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_author;
    QLineEdit *lineEdit_title;
    QLabel *label_title;
    QLabel *label_author;

    void setupUi(QDialog *AddBookDialog)
    {
        if (AddBookDialog->objectName().isEmpty())
            AddBookDialog->setObjectName("AddBookDialog");
        AddBookDialog->resize(200, 170);
        buttonBox = new QDialogButtonBox(AddBookDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(0, 130, 181, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        lineEdit_author = new QLineEdit(AddBookDialog);
        lineEdit_author->setObjectName("lineEdit_author");
        lineEdit_author->setGeometry(QRect(30, 100, 113, 24));
        lineEdit_title = new QLineEdit(AddBookDialog);
        lineEdit_title->setObjectName("lineEdit_title");
        lineEdit_title->setGeometry(QRect(30, 40, 113, 24));
        label_title = new QLabel(AddBookDialog);
        label_title->setObjectName("label_title");
        label_title->setGeometry(QRect(20, 10, 49, 16));
        label_author = new QLabel(AddBookDialog);
        label_author->setObjectName("label_author");
        label_author->setGeometry(QRect(20, 70, 49, 16));

        retranslateUi(AddBookDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, AddBookDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, AddBookDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(AddBookDialog);
    } // setupUi

    void retranslateUi(QDialog *AddBookDialog)
    {
        AddBookDialog->setWindowTitle(QCoreApplication::translate("AddBookDialog", "Dialog", nullptr));
        label_title->setText(QCoreApplication::translate("AddBookDialog", "Title", nullptr));
        label_author->setText(QCoreApplication::translate("AddBookDialog", "Author", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AddBookDialog: public Ui_AddBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDBOOKDIALOG_H
