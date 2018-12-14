#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QNetworkAccessManager>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    t1 = QDateTime::currentMSecsSinceEpoch();

    ui->setupUi(this);

    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT(close()));

    connect(ui->pushButtonRechercher, SIGNAL(clicked(bool)), this, SLOT(recherche()));


    manager = new QNetworkAccessManager(this);

    //QNetworkRequest request;
        request.setUrl(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=finess-etablissements&q=Pharmacie+d%27Officine&geofilter.distance="+latitude+"%2C+"+longitude+"%2C+"+rayon));
        //request.setUrl(QUrl("https://public.opendatasoft.com/api/records/1.0/search/?dataset=finess-etablissements&q=Pharmacie+d%27Officine&geofilter.distance=49.747214%2C+%200.935522%2C+10000"));

        //request.setRawHeader("adresse", "libelle_commune");



        reply = manager->get(request);

        connect(reply, SIGNAL(readyRead()), this, SLOT(slotReadyRead()));
        connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(slotError(QNetworkReply::NetworkError)));
        connect(reply, SIGNAL(sslErrors(QList<QSslError>)),this, SLOT(slotSslErrors(QList<QSslError>)));
        connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(replyFinished(QNetworkReply*)));

        t4 = QDateTime::currentMSecsSinceEpoch();
        int temps1 =t4-t1;
        qDebug() << temps1;

        qDebug() << t1;




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{     
    t2 = QDateTime::currentMSecsSinceEpoch();


    //qDebug() << "Coucou";
    //QFile file("test.json");
    //file.open(QIODevice::ReadWrite);
    QByteArray tab = reply->readAll();
    //ui->textEdit->append(tab);


    QJsonDocument doc = QJsonDocument::fromJson(tab);
    //qDebug() <<"alors"<< doc.object().toVariantMap().keys();

   // QString adresse = doc.toVariant().toMap()["records"].toMap()["0"].toJsonArray().at(2);

    QJsonArray tableau = doc.object().value("records").toArray();

    for(int i= 0; i < tableau.count(); i++)
    {
    QString nom = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["rs"].toString();
    QString adresse = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["adresse"].toString();
    QString distance = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["dist"].toString();
    QString codePostal = doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["ligneacheminement"].toString();

    ui->textEdit->insertPlainText(nom + "\n" + adresse + "\n" + codePostal + "\nà " + distance + " mètres\n\n");

    //ui->textEdit->append(doc.object().toVariantMap()["records"].toJsonArray().at(i)["fields"].toObject()["ligneacheminement"].toString());

    /*qDebug() << nom;
    qDebug() << adresse;
    qDebug() << codePostal;
    qDebug() << distance << "métres";*/
    }



    t3 = QDateTime::currentMSecsSinceEpoch();

    int temps = t3-t2;
    qDebug() << t2;
    qDebug() << t3;



    qDebug() << temps;

    int temps2 = t3-t1;
    qDebug() << "temps" << temps2;
}

void MainWindow::slotReadyRead()
{
    qDebug() << "SlotReadyRead";


    /*QFile file("test.json");
    file.open(QIODevice::ReadWrite);
    QByteArray tab = reply->readAll();
    ui->textEdit->append(tab);*/
}

void MainWindow::slotError(QNetworkReply::NetworkError rt)
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

