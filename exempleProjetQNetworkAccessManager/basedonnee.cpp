#include "basedonnee.h"

#include "mainwindow.h"


BaseDonnee::BaseDonnee()
{

}

QMap<QString, QString> BaseDonnee::get(QString table, QString temps, QString api)
{
    QMap<QString,QString> map;
    QSqlQuery requete;
    QString demande = QString("SELECT %1, %2 FROM %3").arg(temps).arg(api).arg(table);
    requete.prepare(demande);

    if(requete.exec())
    {
        while(requete.next())
        {
            //map[requete.value(0).toString()] = requete.value(1).toString();
            map.insert(requete.value(0).toString(), requete.value(1).toString());

        }
    }
    return map;
}

void BaseDonnee::putHeures(QString api, QString value)
{
    int time = QTime::currentTime().hour();
    int newTime = time-1;


    QSqlQuery requete;
    QString demande = QString("Select %1 from Heures where heure_id = %2").arg(api).arg(newTime);
    requete.prepare(demande);
    qDebug() << demande;
    if(requete.exec())
    {
        requete.next();
        qDebug() << requete.value(0);
        if (requete.value(0).isNull())
        {
            QString demande2 = QString("UPDATE Heures SET %1 = %2 WHERE heure_id = %3").arg(api).arg(value).arg(newTime);
            qDebug() << demande2;
            requete.prepare(demande2);
            requete.exec();

        }
        else
        {
            QString oldValue = requete.value(0).toString();
            int newValeur = oldValue.toInt()+ value.toInt();
            QString newValue = QString::number(newValeur);

            QString demande3 = QString("UPDATE Heures SET %1 = %2 WHERE heure_id = %3").arg(api).arg(newValue).arg(newTime);
            requete.prepare(demande3);
            requete.exec();

        }

    }
}



   /* void putJours(QString api, QString value)
    {
        QDate day = QDate::currentDate();

        QSqlQuery requete;
        requete.prepare("Select :api from Jours where jour_id = :day-1");
        requete.bindValue(":api", api);
        requete.bindValue(":day", day);
        if(requete.exec())
        {
            requete.nextResult();
            if (requete.value(0).isNull())
            {
                requete.prepare("INSERT INTO Heures(:api) VALUES (:value) where :id = :time");
                requete.bindValue(":api", api);
                requete.bindValue(":Value",value);
            }
            else
            {
                QString newValue = requete.value(0).toString() + value;

                requete.prepare("INSERT INTO Heures(:api) VALUES (:newValue) where :id = :time");
                requete.bindValue(":api", api);
                requete.bindValue(":newValue",newValue);

            }

        }
    }*/

/*void BaseDonnee::put(QString api, QString table, QString id, QString value)
{
    QTime time = QTime::currentTime();

    QSqlQuery requete;
    requete.prepare("Select :api from :table where :id = :time-1");
    requete.bindValue(":api", api);
    requete.bindValue(":table", table);
    requete.bindValue(":id",id);
    requete.bindValue(":time", time);
    if(requete.exec())
    {
        requete.nextResult();
        QString valeur = requete.value(0).toString();


        requete.prepare("INSERT INTO :table(:api) VALUES (:newValue) where :id = :time");
        requete.bindValue(":table", table);
        requete.bindValue(":api", api);
        requete.bindValue(":newValue",newValue);
    }

}*/

void BaseDonnee::effacer(QString table)
{
    QSqlQuery requete;
    QString demande = QString("DELETE FROM %1").arg(table);
    requete.prepare(demande);
    requete.exec();
}

void BaseDonnee::transfertHeuresJours()
{
    QSqlQuery requete;
    QString demande = QString("INSERT INTO Jours (pollution) select avg(pollution) as Moy from Heures where heure_id > 0 and heure_id < 25 ");
    requete.exec(demande);

    QSqlQuery requete2;
    QString demande2 = QString("DELETE FROM Heures");
    requete2.exec(demande2);

    QSqlQuery requete3;
    for(int i =0; i <24; i++)
    {
        QString demande3 = QString("INSERT INTO Heures(heure_id) VALUES (%1)").arg(i);
        requete3.exec(demande3);
    }
}
