#ifndef BASEDONNEE_H
#define BASEDONNEE_H

#include <QString>
#include <QSqlQuery>
#include <QSqlRecord>

class BaseDonnee
{
public:
    BaseDonnee();

    static QMap<QString,QString>get(QString table, QString temps, QString api);
    static void putHeures (QString api, QString value);
    static void putJours (QString api, QString value);
    static void effacer(QString table);
    static void transfertHeuresJours();
//private:
    //int requete;
};

#endif // BASEDONNEE_H
