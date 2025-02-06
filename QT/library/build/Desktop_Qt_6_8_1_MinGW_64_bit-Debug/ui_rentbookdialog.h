/********************************************************************************
** Form generated from reading UI file 'rentbookdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENTBOOKDIALOG_H
#define UI_RENTBOOKDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_RentBookDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label_personName;
    QLabel *label_bookAuthor;
    QLabel *label_bookTitle;
    QDateEdit *dateEdit_returnDate;
    QLabel *label_returnDate;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *RentBookDialog)
    {
        if (RentBookDialog->objectName().isEmpty())
            RentBookDialog->setObjectName("RentBookDialog");
        RentBookDialog->resize(220, 200);
        buttonBox = new QDialogButtonBox(RentBookDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(20, 150, 171, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        label_personName = new QLabel(RentBookDialog);
        label_personName->setObjectName("label_personName");
        label_personName->setGeometry(QRect(70, 75, 151, 20));
        label_bookAuthor = new QLabel(RentBookDialog);
        label_bookAuthor->setObjectName("label_bookAuthor");
        label_bookAuthor->setGeometry(QRect(60, 10, 131, 20));
        label_bookTitle = new QLabel(RentBookDialog);
        label_bookTitle->setObjectName("label_bookTitle");
        label_bookTitle->setGeometry(QRect(60, 40, 131, 20));
        dateEdit_returnDate = new QDateEdit(RentBookDialog);
        dateEdit_returnDate->setObjectName("dateEdit_returnDate");
        dateEdit_returnDate->setGeometry(QRect(100, 115, 110, 25));
        label_returnDate = new QLabel(RentBookDialog);
        label_returnDate->setObjectName("label_returnDate");
        label_returnDate->setGeometry(QRect(10, 120, 71, 16));
        label = new QLabel(RentBookDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 25, 41, 20));
        label_2 = new QLabel(RentBookDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 75, 41, 20));

        retranslateUi(RentBookDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, RentBookDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, RentBookDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(RentBookDialog);
    } // setupUi

    void retranslateUi(QDialog *RentBookDialog)
    {
        RentBookDialog->setWindowTitle(QCoreApplication::translate("RentBookDialog", "Dialog", nullptr));
        label_personName->setText(QCoreApplication::translate("RentBookDialog", "Name", nullptr));
        label_bookAuthor->setText(QCoreApplication::translate("RentBookDialog", "Author", nullptr));
        label_bookTitle->setText(QCoreApplication::translate("RentBookDialog", "Title", nullptr));
        label_returnDate->setText(QCoreApplication::translate("RentBookDialog", "Return date", nullptr));
        label->setText(QCoreApplication::translate("RentBookDialog", "Book:", nullptr));
        label_2->setText(QCoreApplication::translate("RentBookDialog", "Person:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RentBookDialog: public Ui_RentBookDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENTBOOKDIALOG_H
