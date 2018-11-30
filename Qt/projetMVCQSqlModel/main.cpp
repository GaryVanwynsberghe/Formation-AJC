#include "mainwindow.h"
#include <QApplication>

#include <QSqlDatabase>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("/home/ajc98/Documents/Formation-AJC/Qt/comsimp.db");
    db.open();

    MainWindow w;
    w.show();




    return a.exec();
}
