#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlError>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    comsimp = new QSqlTableModel();
    ui->tableView->setModel(comsimp);
    comsimp->setTable("comsimp2016");
    comsimp->select();


    connect(ui->tableView,SIGNAL(clicked(QModelIndex)), this, SLOT(AfficheInfo(QModelIndex)));

    //Permet de voir où est l'erreur
    //qDebug()<<comsimp->lastError().text();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::AfficheInfo(QModelIndex ind)
{
    QString val;
    val = ind.data().toString();
    ui->lineEdit->setText(val);
}
