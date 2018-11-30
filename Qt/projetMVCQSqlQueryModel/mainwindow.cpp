#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlQuery>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Première méthode pour afficher le tableau à l'ouverture de la fenêtre
    model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM comsimp2016");
    ui->tableView->setModel(model);

    //Seconde méthode pour afficher le tableau
    /*comsimp = new QSqlTableModel();
    ui->tableView->setModel(comsimp);
    comsimp->setTable("comsimp2016");
    comsimp->select();*/

    connect(ui->lineEditDpartement, SIGNAL(textEdited(QString)), this, SLOT(AfficheDepartement()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::AfficheDepartement()
{
    /*if (ui->lineEditDpartement->text().isEmpty())
    {

    }*/



    //QSqlQuery requete("SELECT * FROM comsimp2016 where DEP = '"+ui->lineEditDpartement->text()+"'");

    QSqlQuery requete(QString("SELECT * FROM comsimp2016 where DEP = '%1'").arg(ui->lineEditDpartement->text()));



    //Permet de filtrer et de trier des données
    model = new QSqlQueryModel();
    model->setQuery(requete);
    ui->tableView->setModel(model);

    if (ui->lineEditDpartement->text().isEmpty())
    {
        ui->tableView->setModel(comsimp);
    }

}
