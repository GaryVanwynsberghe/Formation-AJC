#include <QCoreApplication>

#include <QDir>
#include <QDebug>



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QDir fichier (QDir::homePath());
    QRegExp exp (".\\.\\w{3}$");

    QStringList liste= fichier.entryList(QDir::Files);

    QString str;
    foreach (str, liste) {
        if (str.contains(exp))

        qDebug()<<str;

    }

    //qDebug()<<liste;


    return a.exec();
}
