/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableView *tableView_books;
    QTableView *tableView_rents;
    QTableView *tableView_people;
    QLabel *label_books;
    QLabel *label_rents;
    QLabel *label_people;
    QPushButton *pushButton_addBook;
    QPushButton *pushButton_delBook;
    QPushButton *pushButton_rent;
    QPushButton *pushButton_return;
    QPushButton *pushButton_addPerson;
    QPushButton *pushButton_delPerso;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(602, 550);
        MainWindow->setStyleSheet(QString::fromUtf8("/* Ustawienia og\303\263lne */\n"
"QWidget {\n"
"    background-color: #f0f0f0; /* T\305\202o okna */\n"
"    color: #2d2d2d; /* Kolor tekstu */\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 12pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"/* Przycisk */\n"
"QPushButton {\n"
"    background-color: #4CAF50; /* Zielony przycisk */\n"
"    color: white; /* Bia\305\202y tekst */\n"
"    border: 1px solid #388E3C; /* Obramowanie */\n"
"    border-radius: 4px;\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 10pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #45a049; /* Ja\305\233niejszy zielony przy najechaniu */\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #2e7d32; /* Ciemniejszy zielony przy klikni\304\231ciu */\n"
"}\n"
"\n"
"/* Przycisk Delete (czerwony) */\n"
"QPushButton#pushButton_delBook, QPushButton#pushButton_delPerson {\n"
"    background-color: #e74c3c; /* Czerwony przycisk */\n"
""
                        "    color: white; /* Bia\305\202y tekst */\n"
"    border: 1px solid #c0392b; /* Ciemniejsze czerwone obramowanie */\n"
"    border-radius: 4px;\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 10pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"QPushButton#pushButton_delBook:hover, QPushButton#pushButton_delPerson:hover {\n"
"    background-color: #c0392b; /* Ciemniejszy czerwony przy najechaniu */\n"
"}\n"
"\n"
"QPushButton#pushButton_delBook:pressed, QPushButton#pushButton_delPerson:pressed {\n"
"    background-color: #e74c3c; /* Ja\305\233niejszy czerwony przy klikni\304\231ciu */\n"
"}\n"
"\n"
"/* Przycisk Return (czerwony) */\n"
"QPushButton#pushButton_return {\n"
"    background-color: #e74c3c; /* Czerwony przycisk */\n"
"    color: white; /* Bia\305\202y tekst */\n"
"    border: 1px solid #c0392b; /* Ciemniejsze czerwone obramowanie */\n"
"    border-radius: 4px;\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 10pt; /* Rozmiar czcionki */"
                        "\n"
"}\n"
"\n"
"QPushButton#pushButton_return:hover {\n"
"    background-color: #c0392b; /* Ciemniejszy czerwony przy najechaniu */\n"
"}\n"
"\n"
"QPushButton#pushButton_return:pressed {\n"
"    background-color: #e74c3c; /* Ja\305\233niejszy czerwony przy klikni\304\231ciu */\n"
"}\n"
"\n"
"/* Tabela */\n"
"QTableView {\n"
"    background-color: #ffffff; /* Bia\305\202e t\305\202o tabeli */\n"
"    alternate-background-color: #f9f9f9; /* Naprzemienny kolor wierszy */\n"
"    gridline-color: #dcdcdc; /* Kolor siatki */\n"
"    color: #2d2d2d; /* Kolor tekstu */\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 11pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #d3d3d3; /* T\305\202o nag\305\202\303\263wk\303\263w tabeli */\n"
"    color: #2d2d2d; /* Tekst nag\305\202\303\263wk\303\263w */\n"
"    border: 1px solid #b0b0b0; /* Obramowanie nag\305\202\303\263wk\303\263w */\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki *"
                        "/\n"
"    font-size: 12pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"/* Pole tekstowe */\n"
"QLineEdit {\n"
"    background-color: #ffffff; /* Bia\305\202e t\305\202o pola tekstowego */\n"
"    color: #2d2d2d; /* Tekst pola */\n"
"    border: 1px solid #b0b0b0; /* Obramowanie */\n"
"    border-radius: 4px;\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 11pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"/* Lista */\n"
"QListView, QTreeView {\n"
"    background-color: #ffffff; /* Bia\305\202e t\305\202o listy/drzewa */\n"
"    color: #2d2d2d; /* Kolor tekstu */\n"
"    alternate-background-color: #f9f9f9; /* Naprzemienny kolor wierszy */\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 11pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"QListView::item:hover, QTreeView::item:hover {\n"
"    background-color: #e0e0e0; /* Szare t\305\202o przy najechaniu */\n"
"}\n"
"\n"
"/* Menu */\n"
"QMenuBar {\n"
"    background-color: #eaeaea; /* T\305\202o menu */\n"
"  "
                        "  color: #2d2d2d; /* Kolor tekstu */\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 12pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"QMenu {\n"
"    background-color: #ffffff; /* T\305\202o rozwijanego menu */\n"
"    color: #2d2d2d; /* Tekst menu */\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 11pt; /* Rozmiar czcionki */\n"
"}\n"
"\n"
"QMenu::item:selected {\n"
"    background-color: #dcdcdc; /* Szary kolor zaznaczenia */\n"
"}\n"
"\n"
"/* Pasek stanu */\n"
"QStatusBar {\n"
"    background-color: #eaeaea; /* T\305\202o paska stanu */\n"
"    color: #2d2d2d; /* Tekst paska stanu */\n"
"    font-family: \"Arial\", sans-serif; /* Rodzaj czcionki */\n"
"    font-size: 10pt; /* Rozmiar czcionki */\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tableView_books = new QTableView(centralwidget);
        tableView_books->setObjectName("tableView_books");
        tableView_books->setGeometry(QRect(0, 20, 390, 200));
        tableView_rents = new QTableView(centralwidget);
        tableView_rents->setObjectName("tableView_rents");
        tableView_rents->setGeometry(QRect(0, 280, 600, 192));
        tableView_people = new QTableView(centralwidget);
        tableView_people->setObjectName("tableView_people");
        tableView_people->setGeometry(QRect(392, 20, 208, 200));
        label_books = new QLabel(centralwidget);
        label_books->setObjectName("label_books");
        label_books->setGeometry(QRect(0, 0, 49, 16));
        label_rents = new QLabel(centralwidget);
        label_rents->setObjectName("label_rents");
        label_rents->setGeometry(QRect(0, 260, 49, 16));
        label_people = new QLabel(centralwidget);
        label_people->setObjectName("label_people");
        label_people->setGeometry(QRect(450, 0, 49, 16));
        pushButton_addBook = new QPushButton(centralwidget);
        pushButton_addBook->setObjectName("pushButton_addBook");
        pushButton_addBook->setGeometry(QRect(10, 225, 80, 24));
        pushButton_delBook = new QPushButton(centralwidget);
        pushButton_delBook->setObjectName("pushButton_delBook");
        pushButton_delBook->setGeometry(QRect(300, 225, 80, 24));
        pushButton_rent = new QPushButton(centralwidget);
        pushButton_rent->setObjectName("pushButton_rent");
        pushButton_rent->setGeometry(QRect(10, 475, 80, 24));
        pushButton_return = new QPushButton(centralwidget);
        pushButton_return->setObjectName("pushButton_return");
        pushButton_return->setGeometry(QRect(510, 475, 80, 24));
        pushButton_addPerson = new QPushButton(centralwidget);
        pushButton_addPerson->setObjectName("pushButton_addPerson");
        pushButton_addPerson->setGeometry(QRect(400, 225, 80, 24));
        pushButton_delPerso = new QPushButton(centralwidget);
        pushButton_delPerso->setObjectName("pushButton_delPerso");
        pushButton_delPerso->setGeometry(QRect(510, 225, 80, 24));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 602, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_books->setText(QCoreApplication::translate("MainWindow", "Books", nullptr));
        label_rents->setText(QCoreApplication::translate("MainWindow", "Rents", nullptr));
        label_people->setText(QCoreApplication::translate("MainWindow", "People", nullptr));
        pushButton_addBook->setText(QCoreApplication::translate("MainWindow", "Add book", nullptr));
        pushButton_delBook->setText(QCoreApplication::translate("MainWindow", "Delete book", nullptr));
        pushButton_rent->setText(QCoreApplication::translate("MainWindow", "Rent", nullptr));
        pushButton_return->setText(QCoreApplication::translate("MainWindow", "Return", nullptr));
        pushButton_addPerson->setText(QCoreApplication::translate("MainWindow", "Add person", nullptr));
        pushButton_delPerso->setText(QCoreApplication::translate("MainWindow", "Delete person", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
