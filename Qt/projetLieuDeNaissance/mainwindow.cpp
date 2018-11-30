#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    connect(ui->pushButton, SIGNAL(clicked(bool)), this, SLOT (Recherche()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Recherche()
{





    QString ville = ui->lineEditVille->text();

    QSqlQuery query("SELECT COM, CHEFLIEU, REG, DEP FROM comsimp2016 where NCCENR = '"+ville+"'");
    while (query.next()) {


    //Première méthode :
    QString com = query.value(0).toString();
    QString cheflieu = query.value(1).toString();
    QString reg = query.value(2).toString();
    QString dep = query.value(3).toString();
    ui->lineEditCodeCommune->setText(com);
    ui->lineEditChefLieu->setText(cheflieu);
    ui->lineEditRegion->setText(reg);
    ui->lineEditCodePostal->setText(dep);


    //Deuxième méthode :
    /*ui->lineEditCodeCommune->setText(query.value(0).toString());
    ui->lineEditChefLieu->setText(query.value(1).toString());
    ui->lineEditRegion->setText(query.value(2).toString());
    ui->lineEditCodePostal->setText(query.value(3).toString());*/
    }

}
