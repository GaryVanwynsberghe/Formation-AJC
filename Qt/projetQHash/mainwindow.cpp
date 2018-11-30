#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    hash["Charles"] = 30;
    hash["Ghania"] = 25;
    hash["William"] = 28;
    hash["Mourad"] = 27;
    hash["Gary"] = 33;
    hash["Cyrille"] = 34;
    hash["Théva"] = 29;
    hash["Sémir"] = 30;
    hash["David"] = 28;
    hash["Soheib"] = 23;
    hash["Paul"] = 29;
    hash["Marc"] = 35;

    ui->comboBox->addItems(hash.keys());
    connect(ui->comboBox, SIGNAL(currentIndexChanged(QString )), this, SLOT(AfficheAge(QString)));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AfficheAge(QString v)
{
    QString age (QString("%1 ans").arg(hash[v]));
  //age.setNum(hash[v]);
  //ou
  //age.setNum(hash.value(v));

    ui->lineEdit->setText(age);

    //qDebug()<<age;


}
