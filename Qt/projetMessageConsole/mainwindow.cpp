#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit,SIGNAL(returnPressed()),this,SLOT(Afficher()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Afficher()
{
    qDebug()<<"Saisi :"<<ui->lineEdit->text().toUpper();
}
