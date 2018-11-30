#include <QCoreApplication>

#include <QDir>
#include<QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //QDir d;
    //d.homePath();
    //qDebug()<<d.homePath();

    //ou

   qDebug()<< QDir::homePath();


    return a.exec();
}
