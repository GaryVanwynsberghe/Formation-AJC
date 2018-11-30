#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButtonValider, SIGNAL(clicked(bool)), this, SLOT(Valider()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Valider()
{
    int i = 4;

    ui->spinBox->setValue(i);

}
