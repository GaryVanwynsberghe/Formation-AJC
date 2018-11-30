#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QCompleter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStringList liste;
    liste <<"robert"<<"roger"<<"roland"<<"julie"<<"juliette"<<"julien"<<"jorge";

    completer = new QCompleter(liste, this);
    completer->setCaseSensitivity(Qt::CaseInsensitive);
    ui->lineEdit->setCompleter(completer);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete completer;
}

