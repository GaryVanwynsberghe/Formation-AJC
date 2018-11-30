#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private:
    Ui::MainWindow *ui;
    QString chemin;


private slots:
    void Propos();
    void Ouvrir();
    void Sauvegarder();
    void Parametre();
};

#endif // MAINWINDOW_H
