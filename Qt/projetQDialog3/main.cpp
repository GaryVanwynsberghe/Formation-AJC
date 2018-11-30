#include "mainwindow.h"
#include <QApplication>
#include <QSettings>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QCoreApplication::setOrganizationDomain("Société");
    QCoreApplication::setApplicationName("Logiciel");

    QFont font2;
    QSettings s;
    font2.setFamily(s.value("police/family").toString());
    font2.setPointSize(s.value("police/taille").toInt());
    w.setFont(font2);


    return a.exec();
}
