#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlQueryModel>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlQueryModel *model;
    QSqlTableModel *comsimp;

private:
    Ui::MainWindow *ui;

private slots:
    void AfficheDepartement();
};

#endif // MAINWINDOW_H
