#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "dialog.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*m_fenetre = new Dialog(this);
    m_fenetre.hide();
    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(show()));*/


    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionA_propos, SIGNAL(triggered()), this, SLOT(APropos()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::APropos()
{
    Dialog *fenetre= new Dialog(this);
    //fenetre->exec() ;// pour un dialogue bloquant
    fenetre->show() ;// pour un dialogue non bloquant
}
