#ifndef DIALOGPARAMETRE_H
#define DIALOGPARAMETRE_H

#include <QDialog>
#include <QSettings>

namespace Ui {
class DialogParametre;
}

class DialogParametre : public QDialog
{
    Q_OBJECT

public:
    explicit DialogParametre(QWidget *parent = nullptr);
    ~DialogParametre();

private:
    Ui::DialogParametre *ui;
    QSettings s;

private slots:
    void Save();
};

#endif // DIALOGPARAMETRE_H
