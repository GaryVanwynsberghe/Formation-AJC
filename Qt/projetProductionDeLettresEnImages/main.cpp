#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    /*for(int i = 33; i <= 126; i++)
    {
        QChar maValeur(i);
        QString maLettre(maValeur);

        QPixmap *pixmap;
        QPainter *painter;

        QPainter painter(this);
        pixmap->fill(Qt::transparent);
        //QPainter painter (pixmap);

        /*QPen pen;
        pen.setStyle(Qt::DashDotLine);
        pen.setWidth(3);
        pen.setBrush(Qt::red);
        pen.setCapStyle(Qt::RoundCap);
        pen.setJoinStyle(Qt::RoundJoin);*/

        /*QColor black(Qt::black);
        QColor couleur(Qt::white);
        QPen pen(black);
        QBrush brush(couleur);

        painter.setPen(pen);
        painter.setBrush(brush);

        QRectF rectangle (100, 80, 250, 150);
        painter.setFont(QFont("Arial",50));
        painter.drawRoundRect(rectangle, 15, 15);
        painter.drawText(rectangle, Qt::AlignCenter, maLettre);

        painter.end();
        pixmap->save(QString("fichier %1.png").arg(maLettre));
    };*/



    MainWindow w;
    w.show();

    return a.exec();
}
