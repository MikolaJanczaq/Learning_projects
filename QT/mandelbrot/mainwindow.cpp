#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>

MandelbrotWidget::MandelbrotWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(800, 800);
}

void MandelbrotWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    int width = this->width();
    int height = this->height();
    double minRe = -2.0, maxRe = 2.0, minIm = -2.0, maxIm = 2.0;
    int maxIter = 1000;

    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            double re = minRe + (maxRe - minRe) * x / width;
            double im = minIm + (maxIm - minIm) * y / height;
            int iter = 0;
            double r = 0.0, i = 0.0;

            while (r * r + i * i <= 4.0 && iter < maxIter) {
                double rTemp = r * r - i * i + re;
                i = 2.0 * r * i + im;
                r = rTemp;
                ++iter;
            }

            QColor color;
            if (iter == maxIter) {
                color = QColor(0, 0, 0);
            } else {
                double t = (double)iter / maxIter;
                int r = (int)(9 * (1 - t) * t * t * t * 255);
                int g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
                int b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
                color = QColor(r, g, b);
            }

            painter.setPen(color);
            painter.drawPoint(x, y);
        }
    }
}


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    mandelbrotWidget = new MandelbrotWidget(this);
    setCentralWidget(mandelbrotWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
