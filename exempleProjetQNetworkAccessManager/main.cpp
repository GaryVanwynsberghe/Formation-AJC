#include "mainwindow.h"
#include <QApplication>

#include <QSqlDatabase>
#include <QSqlError>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;


    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("/home/ajc98/Documents/BaseDonnee/GeoStation.db");

        if(!db.open())
        {
            QMessageBox::critical(0, QObject::tr("Database Error"), db.lastError().text());
        }


    w.show();

    return a.exec();
}
