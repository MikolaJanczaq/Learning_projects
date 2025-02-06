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
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *pushButton_clear;
    QPushButton *pushButton_percent;
    QPushButton *pushButton_plusMinus;
    QPushButton *pushButton_division;
    QPushButton *pushButton_8;
    QPushButton *pushButton_7;
    QPushButton *pushButton_multiply;
    QPushButton *pushButton_9;
    QPushButton *pushButton_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_substract;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QPushButton *pushButton_1;
    QPushButton *pushButton_addition;
    QPushButton *pushButton_3;
    QPushButton *pushButton_0;
    QPushButton *pushButton_result;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_inverse;
    QPushButton *pushButton_power;
    QPushButton *pushButton_root;
    QPushButton *pushButton_backspace;
    QPushButton *pushButton_absolute;
    QPushButton *pushButton_euler;
    QPushButton *pushButton_pi;
    QPushButton *pushButton_factorial;
    QPushButton *pushButton_modulo;
    QPushButton *pushButton_log;
    QPushButton *pushButton_ln;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(302, 432);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"    background-color: #2e2e2e;\n"
"}\n"
"QWidget {\n"
"    background-color: #2e2e2e;\n"
"}\n"
"QLabel {\n"
"    color: #ffffff;\n"
"    font-family: 'Roboto', sans-serif;\n"
"    font-size: 25px;\n"
"}\n"
"QPushButton {\n"
"    background-color: #444444;\n"
"    color: #e0e0e0;\n"
"    border: 1px solid #333333;\n"
"    border-radius: 5px;\n"
"    font-family: 'Roboto', sans-serif;\n"
"    font-size: 18px;\n"
"}\n"
"QPushButton:hover {\n"
"    background-color: #555555;\n"
"}\n"
"QPushButton:pressed {\n"
"    background-color: #666666;\n"
"}\n"
"QPushButton:disabled {\n"
"    background-color: #2e2e2e;\n"
"    color: #8a8a8a;\n"
"}\n"
"\n"
"/* Przycisk liczb */\n"
"QPushButton#pushButton_0,\n"
"QPushButton#pushButton_1,\n"
"QPushButton#pushButton_2,\n"
"QPushButton#pushButton_3,\n"
"QPushButton#pushButton_4,\n"
"QPushButton#pushButton_5,\n"
"QPushButton#pushButton_6,\n"
"QPushButton#pushButton_7,\n"
"QPushButton#pushButton_8,\n"
"QPushButton#pushButton_9 {\n"
"    background-color: #3a3a3a;\n"
""
                        "}\n"
"QPushButton#pushButton_0:hover,\n"
"QPushButton#pushButton_1:hover,\n"
"QPushButton#pushButton_2:hover,\n"
"QPushButton#pushButton_3:hover,\n"
"QPushButton#pushButton_4:hover,\n"
"QPushButton#pushButton_5:hover,\n"
"QPushButton#pushButton_6:hover,\n"
"QPushButton#pushButton_7:hover,\n"
"QPushButton#pushButton_8:hover,\n"
"QPushButton#pushButton_9:hover {\n"
"    background-color: #4a4a4a;\n"
"}\n"
"QPushButton#pushButton_0:pressed,\n"
"QPushButton#pushButton_1:pressed,\n"
"QPushButton#pushButton_2:pressed,\n"
"QPushButton#pushButton_3:pressed,\n"
"QPushButton#pushButton_4:pressed,\n"
"QPushButton#pushButton_5:pressed,\n"
"QPushButton#pushButton_6:pressed,\n"
"QPushButton#pushButton_7:pressed,\n"
"QPushButton#pushButton_8:pressed,\n"
"QPushButton#pushButton_9:pressed {\n"
"    background-color: #5a5a5a;\n"
"}\n"
"\n"
"/* Przycisk CLEAR */\n"
"QPushButton#pushButton_clear {\n"
"    background-color: #5a5a5a;\n"
"}\n"
"QPushButton#pushButton_clear:hover {\n"
"    background-color: #6a6a6a;\n"
"}\n"
"QPushBu"
                        "tton#pushButton_clear:pressed {\n"
"    background-color: #7a7a7a;\n"
"}\n"
"\n"
"/* Przycisk wynikowy */\n"
"QPushButton#pushButton_result {\n"
"    background-color: #4e5f4e;\n"
"}\n"
"QPushButton#pushButton_result:hover {\n"
"    background-color: #5e6f5e;\n"
"}\n"
"QPushButton#pushButton_result:pressed {\n"
"    background-color: #6e7f6e;\n"
"}\n"
"\n"
"/* Przycisk BACKSPACE */\n"
"QPushButton#pushButton_backspace {\n"
"    background-color: #5e4f4f;\n"
"    color: #ffffff;\n"
"}\n"
"QPushButton#pushButton_backspace:hover {\n"
"    background-color: #6e5f5f;\n"
"}\n"
"QPushButton#pushButton_backspace:pressed {\n"
"    background-color: #4e3f3f;\n"
"}\n"
"\n"
"/* Operacje matematyczne */\n"
"QPushButton#pushButton_addition, \n"
"QPushButton#pushButton_substract, \n"
"QPushButton#pushButton_multiply, \n"
"QPushButton#pushButton_division,\n"
"QPushButton#pushButton_percent,\n"
"QPushButton#pushButton_absolute, \n"
"QPushButton#pushButton_power, \n"
"QPushButton#pushButton_root,\n"
"QPushButton#pushButton_modu"
                        "lo,\n"
"QPushButton#pushButton_log,\n"
"QPushButton#pushButton_ln,\n"
"QPushButton#pushButton_euler,\n"
"QPushButton#pushButton_pi,\n"
"QPushButton#pushButton_factorial   {\n"
"    background-color: #484848;\n"
"}\n"
"QPushButton#pushButton_addition:hover,\n"
"QPushButton#pushButton_substract:hover,\n"
"QPushButton#pushButton_multiply:hover,\n"
"QPushButton#pushButton_division:hover,\n"
"QPushButton#pushButton_percent:hover,\n"
"QPushButton#pushButton_absolute:hover,\n"
"QPushButton#pushButton_power:hover,\n"
"QPushButton#pushButton_root:hover,\n"
"QPushButton#pushButton_modulo:hover,\n"
"QPushButton#pushButton_log:hover,\n"
"QPushButton#pushButton_ln:hover,\n"
"QPushButton#pushButton_eule:hover,\n"
"QPushButton#pushButton_pi:hover,\n"
"QPushButton#pushButton_factorial:hover  {\n"
"    background-color: #585858;\n"
"}\n"
"QPushButton#pushButton_addition:pressed,\n"
"QPushButton#pushButton_substract:pressed,\n"
"QPushButton#pushButton_multiply:pressed,\n"
"QPushButton#pushButton_division:pressed,\n"
"QPushButto"
                        "n#pushButton_percent:pressed,\n"
"QPushButton#pushButton_absolute:pressed,\n"
"QPushButton#pushButton_power:pressed,\n"
"QPushButton#pushButton_root:pressed,\n"
"QPushButton#pushButton_modulo:pressed,\n"
"QPushButton#pushButton_log:pressed,\n"
"QPushButton#pushButton_ln:pressed,\n"
"QPushButton#pushButton_euler:pressed,\n"
"QPushButton#pushButton_pi:pressed,\n"
"QPushButton#pushButton_factorial:pressed  {\n"
"    background-color: #686868;\n"
"}\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 301, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("Roboto")});
        label->setFont(font);
        label->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        label->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);
        pushButton_clear = new QPushButton(centralwidget);
        pushButton_clear->setObjectName("pushButton_clear");
        pushButton_clear->setGeometry(QRect(180, 70, 61, 61));
        pushButton_percent = new QPushButton(centralwidget);
        pushButton_percent->setObjectName("pushButton_percent");
        pushButton_percent->setGeometry(QRect(0, 70, 61, 61));
        pushButton_plusMinus = new QPushButton(centralwidget);
        pushButton_plusMinus->setObjectName("pushButton_plusMinus");
        pushButton_plusMinus->setGeometry(QRect(60, 370, 61, 61));
        pushButton_division = new QPushButton(centralwidget);
        pushButton_division->setObjectName("pushButton_division");
        pushButton_division->setGeometry(QRect(240, 130, 61, 61));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(120, 190, 61, 61));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(60, 190, 61, 61));
        pushButton_multiply = new QPushButton(centralwidget);
        pushButton_multiply->setObjectName("pushButton_multiply");
        pushButton_multiply->setGeometry(QRect(240, 190, 61, 61));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(180, 190, 61, 61));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(120, 250, 61, 61));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(60, 250, 61, 61));
        pushButton_substract = new QPushButton(centralwidget);
        pushButton_substract->setObjectName("pushButton_substract");
        pushButton_substract->setGeometry(QRect(240, 250, 61, 61));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(180, 250, 61, 61));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(120, 310, 61, 61));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(60, 310, 61, 61));
        pushButton_addition = new QPushButton(centralwidget);
        pushButton_addition->setObjectName("pushButton_addition");
        pushButton_addition->setGeometry(QRect(240, 310, 61, 61));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(180, 310, 61, 61));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(120, 370, 61, 61));
        pushButton_result = new QPushButton(centralwidget);
        pushButton_result->setObjectName("pushButton_result");
        pushButton_result->setGeometry(QRect(240, 370, 61, 61));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(180, 370, 61, 61));
        pushButton_inverse = new QPushButton(centralwidget);
        pushButton_inverse->setObjectName("pushButton_inverse");
        pushButton_inverse->setGeometry(QRect(0, 130, 61, 61));
        pushButton_power = new QPushButton(centralwidget);
        pushButton_power->setObjectName("pushButton_power");
        pushButton_power->setGeometry(QRect(120, 130, 61, 61));
        pushButton_root = new QPushButton(centralwidget);
        pushButton_root->setObjectName("pushButton_root");
        pushButton_root->setGeometry(QRect(180, 130, 61, 61));
        pushButton_backspace = new QPushButton(centralwidget);
        pushButton_backspace->setObjectName("pushButton_backspace");
        pushButton_backspace->setGeometry(QRect(240, 70, 61, 61));
        pushButton_absolute = new QPushButton(centralwidget);
        pushButton_absolute->setObjectName("pushButton_absolute");
        pushButton_absolute->setGeometry(QRect(60, 130, 61, 61));
        pushButton_euler = new QPushButton(centralwidget);
        pushButton_euler->setObjectName("pushButton_euler");
        pushButton_euler->setGeometry(QRect(60, 70, 61, 61));
        pushButton_pi = new QPushButton(centralwidget);
        pushButton_pi->setObjectName("pushButton_pi");
        pushButton_pi->setGeometry(QRect(120, 70, 61, 61));
        pushButton_factorial = new QPushButton(centralwidget);
        pushButton_factorial->setObjectName("pushButton_factorial");
        pushButton_factorial->setGeometry(QRect(0, 190, 61, 61));
        pushButton_modulo = new QPushButton(centralwidget);
        pushButton_modulo->setObjectName("pushButton_modulo");
        pushButton_modulo->setGeometry(QRect(0, 250, 61, 61));
        pushButton_log = new QPushButton(centralwidget);
        pushButton_log->setObjectName("pushButton_log");
        pushButton_log->setGeometry(QRect(0, 310, 61, 61));
        pushButton_ln = new QPushButton(centralwidget);
        pushButton_ln->setObjectName("pushButton_ln");
        pushButton_ln->setGeometry(QRect(0, 370, 61, 61));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        pushButton_percent->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_plusMinus->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_division->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_multiply->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_substract->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_addition->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_inverse->setText(QCoreApplication::translate("MainWindow", "1/x", nullptr));
        pushButton_power->setText(QCoreApplication::translate("MainWindow", "x^n", nullptr));
        pushButton_root->setText(QCoreApplication::translate("MainWindow", "\342\210\232x", nullptr));
        pushButton_backspace->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        pushButton_absolute->setText(QCoreApplication::translate("MainWindow", "|x|", nullptr));
        pushButton_euler->setText(QCoreApplication::translate("MainWindow", "e", nullptr));
        pushButton_pi->setText(QCoreApplication::translate("MainWindow", "\317\200", nullptr));
        pushButton_factorial->setText(QCoreApplication::translate("MainWindow", "n!", nullptr));
        pushButton_modulo->setText(QCoreApplication::translate("MainWindow", "mod", nullptr));
        pushButton_log->setText(QCoreApplication::translate("MainWindow", "log", nullptr));
        pushButton_ln->setText(QCoreApplication::translate("MainWindow", "ln", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
