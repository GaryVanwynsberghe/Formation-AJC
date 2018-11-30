#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPlainTextEdit>
#include <QDebug>
#include <QPainter>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::paintEvent (QPaintEvent *event)
{
    qDebug()<<this->width()<<this->height();
}*/

/*void MainWindow::mousePressEvent(QMouseEvent *event)
{
    event->pos().y() > this->height()-30;
    qDebug()<<"On est en bas de l'écran";
}*/

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug()<<event->pos().x();
}
void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button()==Qt::RightButton)
    {
        qDebug()<<"Vous avez effectué un click droit !!!";
    }
}


void MainWindow::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<<"Vous avez double clicker";
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawLine(0,0,400,400);
}
