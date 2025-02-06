#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MandelbrotWidget : public QWidget {
    Q_OBJECT
public:
    MandelbrotWidget(QWidget *parent = nullptr);
protected:
    void paintEvent(QPaintEvent *event) override;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    MandelbrotWidget *mandelbrotWidget;  // Widget do rysowania Mandelbrota
};
#endif // MAINWINDOW_H
