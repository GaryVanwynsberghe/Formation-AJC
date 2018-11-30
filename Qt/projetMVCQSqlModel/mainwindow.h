#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlTableModel *comsimp;

private:
    Ui::MainWindow *ui;

private slots:
    void QueryAfficheInfo(QModelIndex);
};

#endif // MAINWINDOW_H
