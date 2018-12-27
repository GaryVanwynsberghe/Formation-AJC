#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "basedonnee.h"

#include <QNetworkAccessManager>
#include <QDateTime>

#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    connect(ui->pushButtonRechercher, SIGNAL(clicked(bool)), this, SLOT(recherche()));


    manager = new QNetworkAccessManager(this);

    //QNetworkRequest request;
        request.setUrl(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=finess-etablissements&q=Pharmacie+d%27Officine&geofilter.distance="+latitude+"%2C+"+longitude+"%2C+"+rayon));

        reply = manager->get(request);

        connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
        connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
        connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(slotSslErrors(QList<QSslError>)));
        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));



//        QString pollution;
//        QString Heures;
//        QMap<QString,QString> map;
//        QSqlQuery requete;
//        requete.prepare("SELECT heure, :api FROM :table");
//            requete.bindValue(":api", pollution);
//            requete.bindValue(":table", Heures);
//                if(requete.exec())
//                {
//                    while(requete.next())
//                    {
//                        //map[requete.value(0).toString()] = requete.value(1).toString();
//                        map.insert(requete.value(0).toString(), requete.value(1).toString());
//                        qDebug() << map;
//                    }
//                }




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::replyFinished(QNetworkReply *reply)
{
    QByteArray tab = reply->readAll();

    QJsonDocument doc = QJsonDocument::fromJson(tab);

    QJsonArray tableau = doc.object().value("records").toArray();

    QString nom;
    QString adresse;
    QString distance;
    QString codePostal;


    for(int i= 0; i < tableau.count(); i++)
    {
         nom = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["rs"].toString();
         adresse = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["adresse"].toString();
         distance = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["dist"].toString();
         codePostal = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["ligneacheminement"].toString();
         QString latitude = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toVariant().toMap()["coordonnees"].toList().at(0).toString();
         QString longitude = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toVariant().toMap()["coordonnees"].toList().at(1).toString();

         ui->textEdit->insertPlainText(nom + "\n" + adresse + "\n" + codePostal + "\nà " + distance + " mètres\n\n");

    qDebug() << nom <<"\n" << adresse << "\n" << codePostal << "\nà " <<  distance << " mètres\n\n" << latitude << longitude;

    }
//##########BasseDonnee::get###########################################################################################################
//
//    QString Heures = "Heures";
//    QString heure_id = "heure_id";
//    QString pollution = "pollution";
//    //BaseDonnee::get(Heures, heure_id, pollution);
//    QSqlQuery requete;

//    //requete.prepare("UPDATE Heures SET pollution = 520 WHERE heure_id = 2");
//    //requete.exec();
//    QMap<QString,QString> map;
//    QString demande = QString("SELECT %1, %2 FROM %3").arg(heure_id).arg(pollution).arg(Heures);
//    requete.prepare(demande);
//    if(requete.exec())
//    {
//        while(requete.next())
//        {
//            map.insert(requete.value(0).toString(), requete.value(1).toString());
//            //qDebug() << "valeur 1" << requete.value(0).toString() << "valeur 2" << requete.value(1).toString();

//        }
//    }


//#################################################################################################################


//###############BasseDonnee::put##################################################################################

//    QString api = "pollution";
//    QString value = "432";

//    int time = QTime::currentTime().hour();
//    int newTime = time-1;


//    QSqlQuery requete;
//    QString demande = QString("Select %1 from Heures where heure_id = %2").arg(api).arg(newTime);
//    requete.prepare(demande);
//    qDebug() << demande;
//    if(requete.exec())
//    {
//        requete.next();
//        qDebug() << requete.value(0);
//        if (requete.value(0).isNull())
//        {
//            QString demande2 = QString("UPDATE Heures SET %1 = %2 WHERE heure_id = %3").arg(api).arg(value).arg(newTime);
//            qDebug() << demande2;
//            requete.prepare(demande2);
//            requete.exec();

//        }
//        else
//        {
//            QString oldValue = requete.value(0).toString();
//            int newValeur = oldValue.toInt()+ value.toInt();
//            QString newValue = QString::number(newValeur);

//            QString demande3 = QString("UPDATE Heures SET %1 = %2 WHERE heure_id = %3").arg(api).arg(newValue).arg(newTime);
//            requete.prepare(demande3);
//            requete.exec();

//        }

//    }
//###################################################################################################################

//#######################BasseDonnee::effecer########################################################################
//    QString table = "Jours";
//    QSqlQuery requete2;
//    QString demande5 = QString("DELETE FROM %1").arg(table);
//    requete2.prepare(demande5);
//    requete2.exec();

//####################################################################################################################

//#####################BasseDonnee::transfert#########################################################################



//     QSqlQuery requete;
//     QString demande = QString("INSERT INTO Jours (pollution) select avg(pollution) as Moy from Heures where heure_id > 0 and heure_id < 25 ");
//     requete.exec(demande);

//     QSqlQuery requete2;
//     QString demande2 = QString("DELETE FROM Heures");
//     requete2.exec(demande2);

//     QSqlQuery requete3;
//     for(int i =1; i <25; i++)
//     {
//         QString demande3 = QString("INSERT INTO Heures(heure_id) VALUES (%1)").arg(i);
//         requete3.exec(demande3);
//     }

     /*QSqlQuery requete3;
     for(int i =1; i <32; i++)
     {
         QString demande3 = QString("INSERT INTO Jours(jour_id) VALUES (%1)").arg(i);
         requete3.exec(demande3);
     }*/

//####################################################################################################################

    //fonction public void
    /*BaseDonnee base;
    base.enregistrer(nom, adresse, codePostal, distance);*/



    //fonction public static void
    //BaseDonnee::enregistrer(nom, adresse, codePostal, distance);

    /*QSqlQuery requete;
    requete.prepare("SELECT :nom, :adresse FROM Heures");
        requete.bindValue(":nom", nom);
        requete.bindValue(":adresse", adresse);
        //requete.bindValue(":Heures", Heures);
    if(requete.exec())
    {*/
//        QString newAdresse;
//        QString newNom;
       /* while(requete.next())
        {
//            newNom = requete.value(0).toString();
//            newAdresse = requete.value(1).toString();
//            qDebug() << "AA" << newNom << "BB" << newAdresse;
            for(int i=0; i < requete.record().count(); i++)
            {
                QString list = requete.value(i).toString();
                qDebug() << list;
            }

        }
    }*/





    //QSqlQuery requete;
    //qDebug() << requete.exec("SELECT nom FROM Heures");

//    QSqlTableModel model;
//          model.setTable("Heures");
//          model.select();
//    for(int i = 0; i < model.rowCount(); ++i)
//        {
//                  QSqlRecord recorded = model.record(i);
//                  qDebug() << recorded.value(0).toString();
//                  qDebug() << recorded.value(1).toString();
//                  qDebug() << recorded.value(2).toString();
//                  qDebug() << recorded.value(3).toString();
//        }
//    QSqlQuery requete;
//    if(requete.exec("SELECT nom FROM Heures"))
//    {
//        while(requete.next())
//        {
//            for(int i=0; i < requete.record().count(); i++)
//            {
//                qDebug() << requete.value(i).toString();
//            }
//        }
//    }



//            for(int i=0; i < requete.record().count(); i++)
//            {
//                  qDebug() << requete.value(0).toString();
//                  qDebug() << requete.value(1).toString();
//                  qDebug() << requete.value(2).toString();
//                  qDebug() << requete.value(3).toString();


            //}




      //QSqlQuery requete;
      //requete.exec("DELETE FROM Heures");

    //BaseDonnee::supprimer();

//######Permet de faire une moyenne
//    QSqlQuery requete;
//    if(requete.exec("select min(distance) as Min, max(distance) as Max, avg(distance) as Moy from Heures where heure > '09:16:59.870' and heure < '09:55:44.440'"))
//    {
//        while(requete.next())
//                {
//                    //for(int i=0; i < requete.record().count(); i++)
//                    //{
//                        qDebug() << "Valeur" << requete.value(0).toInt();
//                        qDebug() << "Valeur" << requete.value(1).toInt();
//                        qDebug() << "Valeur" << requete.value(2).toInt();
//                    }
//    }


    //#####Permet de passer des valeurs d'une table à une autre
    //QSqlQuery jour("insert into Jours (Min, Max, Moy) select min(distance) as Min, max(distance) as Max, avg(distance) as Moy from Heures where heure > '09:16:59.870' and heure < '09:55:44.440'");



}

void MainWindow::slotReadyRead()
{
    qDebug() << "SlotReadyRead";

}

void MainWindow::slotError(QNetworkReply::NetworkError)
{
    qDebug() <<"slotError" ;
}

void MainWindow::slotSslErrors(QList<QSslError>)
{
    qDebug() << "slotSslError";
}

void MainWindow::recherche()
{

    ui->textEdit->clear();

    latitude = ui->lineEditLatitude->text() ;
    longitude = ui->lineEditLongitude->text();
    rayon = ui->lineEditRayon->text();

    request.setUrl(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=finess-etablissements&q=Pharmacie+d%27Officine&geofilter.distance="+latitude+"%2C+"+longitude+"%2C+"+rayon));

    reply = manager->get(request);

}

