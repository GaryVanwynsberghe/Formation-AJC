#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPainter>
#include <QRectF>
#include <QColor>

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

void MainWindow::paintEvent(QPaintEvent *ev)
{


    for(int i = 33; i <= 126; i++)
    {
        QChar maValeur(i);
        QString maLettre(maValeur);

        pixmap = new QPixmap(100,100);
        pixmap->fill(Qt::transparent);

        painter = new QPainter(pixmap);
        //QPainter painter (pixmap);

        /*QPen pen;
        pen.setStyle(Qt::DashDotLine);
        pen.setWidth(3);
        pen.setBrush(Qt::red);
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);*/

        QColor black(Qt::black);
        QColor couleur(Qt::white);
        QPen pen(black);
        QBrush brush(couleur);

        painter->setPen(pen);
        painter->setBrush(brush);

        QRectF rectangle (0, 0, 100, 100);
        painter->setFont(QFont("Arial",50));
        painter->drawRoundRect(rectangle, 5, 5);
        painter->drawText(rectangle, Qt::AlignCenter, maLettre);

        painter->end();
        pixmap->save(QString("fichier %1.png").arg(maLettre));
    }
}
