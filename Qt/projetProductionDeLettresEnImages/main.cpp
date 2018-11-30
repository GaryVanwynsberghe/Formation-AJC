#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Création du pixmap
    QPixmap *pixmap = new QPixmap(30,30);
    pixmap->fill(Qt::transparent);
    QPainter *painter= new QPainter(pixmap);
    // Définition du stylo et de la brosse
    QColor black(Qt::black);
    QColor red(Qt::red);
    QPen pen(black);
    QBrush brush(red);
    // C'est sur le painter qu'on applique une ligne
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->drawLine(10,10,150,150);
    painter->end();
    // Une fois la painter fermé on sauve le pixmap dans un fichier
    pixmap->save("fichier.png");






    MainWindow w;
    w.show();

    return a.exec();
}
