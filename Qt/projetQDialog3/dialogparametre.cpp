#include "dialogparametre.h"
#include "ui_dialogparametre.h"

//#include <QSettings>
#include <QFont>



DialogParametre::DialogParametre(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogParametre)
{
    ui->setupUi(this);

    QFont font;
    QSettings s;
    font.setFamily(s.value("police/family").toString());
    font.setPointSize(s.value("police/taille").toInt());
    this->setFont(font);

    connect(ui->pushButtonEnregistrer, SIGNAL(clicked()), this, SLOT(Save()));


}

DialogParametre::~DialogParametre()
{
    delete ui;
}

void DialogParametre::Save()
{


    QFont f;
    f.setFamily(ui->fontComboBox->currentText());
    f.setPointSize(ui->spinBox->value());
    setFont(f);

    s.setValue("police/family",ui->fontComboBox->currentText());
    s.setValue("police/taille", ui->spinBox->value());

}
