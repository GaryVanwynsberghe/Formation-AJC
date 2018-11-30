#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QDir>
#include "dialogparametre.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionQuitter, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui->actionA_Propos, SIGNAL(triggered()), this, SLOT(Propos()));
    connect(ui->actionOuvrir, SIGNAL(triggered()), this, SLOT(Ouvrir()));
    connect(ui->actionSauvegarder, SIGNAL(triggered()), this, SLOT(Sauvegarder()));
    connect(ui->actionParam_tres, SIGNAL(triggered()), this, SLOT(Parametre()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Propos()
{
    Dialog *fenetre = new Dialog(this);

    //fenetre->exec();
    fenetre->show();

}

void MainWindow::Ouvrir()
{
    chemin = QFileDialog::getOpenFileName(this,
                                          QString("Ouvrir un fichier"), QDir::homePath());

    QFile fichier(chemin);

    fichier.open(QIODevice::ReadOnly | QIODevice::Text);

    QString text = fichier.readAll();

    fichier.close();
    ui->textEdit->setText(text);


    /* ou en metttant des message d'erreur avec un if...
    if (!fichier.open(QIODevice::ReadOnly | QIODevice::Text)){

        QMessageBox msgBox(this);
        msgBox.setInformativeText(QString("NNNNNNN"));
        return;
    }

    while (!fichier.atEnd()) {
    QString text = fichier.readAll();

    fichier.close();
    ui->textEdit->setText(text);
    }
    */
}

void MainWindow::Sauvegarder()
{

    /*QFile fichier (chemin);
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&fichier);
    out << ui->textEdit->toPlainText();*/

    //ou (permet de sauvegarder un nouveau fichier)


    QFile fichier (chemin);
    if(!fichier.exists()){
        chemin = QFileDialog::getSaveFileName(this,
                                              QString("Sauvegarde un fichier"), QDir::homePath(),
                                              "Text Files (*);;Image Files (*.png *.jpg *.bmp *.pdf)");
        fichier.setFileName(chemin);
    }
    fichier.open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(&fichier);
    out << ui->textEdit->toPlainText();
}

void MainWindow::Parametre()
{
    DialogParametre *fenetre = new DialogParametre(this);

    fenetre->show();

}
