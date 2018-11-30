#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->spinBox->setRange(-10000,10000);

    connect(ui->spinBox, SIGNAL(valueChanged(int)),this, SLOT(newDate(int)));

    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(close()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newDate(int)
{
    QDate dates;
    QDate nouvelleDate;

    dates = ui->dateEdit->date();
    nouvelleDate = dates.addDays(ui->spinBox->value());
    /*
     * En mettant i dans newDate(int i), on peut ecrire :
     * nouvelleDate = dates.addDays(i);
     */

    //ou
    //QDate date=ui->dateEdit->date().addDays(ui->spinBox->value());

    QString dateCalculee = nouvelleDate.toString("'La date calculée est : ' dd/MM/yyyy");

    ui->label_3->setText(dateCalculee);

    //qDebug()<<dateCalculee;

}
