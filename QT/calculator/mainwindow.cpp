#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

double firstNum;
bool userIsTypingSecondNumber = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton_0, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_1, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_2, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_3, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_4, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_5, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_6, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_7, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_8, SIGNAL(released()), this, SLOT(digit_pressed()));
    connect(ui->pushButton_9, SIGNAL(released()), this, SLOT(digit_pressed()));

    connect(ui->pushButton_plusMinus, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_percent, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_absolute, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_clear, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_inverse, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_root, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_factorial, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_log, SIGNAL(released()), this, SLOT(unary_operation_pressed()));
    connect(ui->pushButton_ln, SIGNAL(released()), this, SLOT(unary_operation_pressed()));


    connect(ui->pushButton_addition, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_substract, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_division, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_multiply, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_power, SIGNAL(released()), this, SLOT(binary_operation_pressed()));
    connect(ui->pushButton_modulo, SIGNAL(released()), this, SLOT(binary_operation_pressed()));



    ui->pushButton_addition->setCheckable(true);
    ui->pushButton_substract->setCheckable(true);
    ui->pushButton_division->setCheckable(true);
    ui->pushButton_multiply->setCheckable(true);
    ui->pushButton_power->setCheckable(true);
    ui->pushButton_modulo->setCheckable(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::digit_pressed() {
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if((ui->pushButton_addition->isChecked() || ui->pushButton_substract->isChecked() || ui->pushButton_division->isChecked() || ui->pushButton_multiply->isChecked() || ui->pushButton_power->isChecked() || ui->pushButton_modulo->isChecked())
        && (!userIsTypingSecondNumber)) {
        labelNumber =button->text().toDouble();
        userIsTypingSecondNumber = true;
        newLabel = QString::number(labelNumber, 'g', 15);
    }
    else {
        if(ui->label->text().contains('.') && button->text()=="0"){
            newLabel = ui->label->text() + button->text();
        }
        else {
            labelNumber = (ui->label->text() + button->text()).toDouble();
            newLabel = QString::number(labelNumber, 'g', 15);
        }
    }

    ui->label->setText(newLabel);
}

void MainWindow::on_pushButton_dot_released()
{
    ui->label->setText(ui->label->text() + ".");
}

void MainWindow::unary_operation_pressed(){
    QPushButton * button = (QPushButton*) sender();
    double labelNumber;
    QString newLabel;

    if(button->text() == "+/-") {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * -1;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if(button->text() == "%") {
        labelNumber = ui->label->text().toDouble();
        labelNumber = labelNumber * 0.01;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if(button->text() == "|x|") {
        labelNumber = ui->label->text().toDouble();
        labelNumber = fabs(labelNumber);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
    }
    else if(button->text() == "√x") {
        labelNumber = ui->label->text().toDouble();
        if (labelNumber < 0) {
            ui->label->setText("Error: Negative root");
        } else {
            labelNumber = sqrt(labelNumber);
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->label->setText(newLabel);
        }
    }
    else if(button->text() == "1/x") {
        labelNumber = ui->label->text().toDouble();
        if (labelNumber == 0) {
            ui->label->setText("Error: Division by zero");
        } else {
            labelNumber = 1 / labelNumber;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->label->setText(newLabel);
        }
    }
    else if(button->text() == "ln") {
        labelNumber = ui->label->text().toDouble();
        if (labelNumber <= 0) {
            ui->label->setText("Error: ln undefined");
        } else {
            labelNumber = log(labelNumber);
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->label->setText(newLabel);
        }
    } else if(button->text() == "log") {
        labelNumber = ui->label->text().toDouble();
        if (labelNumber <= 0) {
            ui->label->setText("Error: log undefined");
        } else {
            labelNumber = log10(labelNumber);
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->label->setText(newLabel);
        }
    } else if(button->text() == "n!") {
        labelNumber = ui->label->text().toDouble();
        if (labelNumber < 0 || floor(labelNumber) != labelNumber) {
            ui->label->setText("Error: Factorial undefined");
        } else {
            unsigned long long result = 1;
            for (int i = 1; i <= static_cast<int>(labelNumber); ++i) {
                result *= i;
            }
            newLabel = QString::number(result, 'g', 15);
            ui->label->setText(newLabel);
        }
    }
}


void MainWindow::on_pushButton_clear_released()
{
    ui->pushButton_addition->setChecked(false);
    ui->pushButton_substract->setChecked(false);
    ui->pushButton_division->setChecked(false);
    ui->pushButton_multiply->setChecked(false);
    ui->pushButton_modulo->setChecked(false);


    userIsTypingSecondNumber = false;

    ui->label->setText("0");


}


void MainWindow::on_pushButton_result_released()
{
    double labelNumber, secondNum;
    QString newLabel;

    secondNum = ui->label->text().toDouble();

    if (ui->pushButton_addition->isChecked()) {
        labelNumber = firstNum + secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_addition->setChecked(false);
    }
    else if (ui->pushButton_substract->isChecked()) {
        labelNumber = firstNum - secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_substract->setChecked(false);
    }
    else if (ui->pushButton_division->isChecked()) {
        if (secondNum == 0) {
            ui->label->setText("Division by zero");
        } else {
            labelNumber = firstNum / secondNum;
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->label->setText(newLabel);
        }
        ui->pushButton_division->setChecked(false);
    }
    else if (ui->pushButton_multiply->isChecked()) {
        labelNumber = firstNum * secondNum;
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_multiply->setChecked(false);
    }
    else if (ui->pushButton_power->isChecked()) {
        labelNumber = pow(firstNum, secondNum);
        newLabel = QString::number(labelNumber, 'g', 15);
        ui->label->setText(newLabel);
        ui->pushButton_power->setChecked(false);
    }
    else if (ui->pushButton_modulo->isChecked()) {
        if (secondNum == 0) {
            ui->label->setText("Modulo by zero");
        } else {
            labelNumber = static_cast<int>(firstNum) % static_cast<int>(secondNum);
            newLabel = QString::number(labelNumber, 'g', 15);
            ui->label->setText(newLabel);
        }
        ui->pushButton_modulo->setChecked(false);
    }

    userIsTypingSecondNumber = false;
}

void MainWindow::binary_operation_pressed() {
    QPushButton * button = (QPushButton*) sender();

    firstNum = ui->label->text().toDouble();

    button->setChecked(true);
}

void MainWindow::on_pushButton_backspace_released()
{
    QString currentText = ui->label->text();
    if (!currentText.isEmpty()) {
        currentText = currentText.left(currentText.length() - 1);
        if (currentText.isEmpty()) {
            ui->label->setText("0");
        } else {
            ui->label->setText(currentText);
        }
    }
}



void MainWindow::on_pushButton_euler_released() {
    ui->label->setText(QString::number(M_E, 'g', 15));
}

void MainWindow::on_pushButton_pi_released() {
    ui->label->setText(QString::number(M_PI, 'g', 15));
}
