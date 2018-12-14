#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork>
#include <QString>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    QString latitude ="48.871671";
    QString longitude = "2.346106";
    QString rayon = "500";

    QNetworkRequest request;
    QNetworkReply *reply;
    QNetworkAccessManager *manager;


    qint64 t1;
    qint64 t2;
    qint64 t3;
    qint64 t4;

private:
    Ui::MainWindow *ui;


private slots:
    void replyFinished(QNetworkReply* reply);
    void slotReadyRead();
    void slotError(QNetworkReply::NetworkError);
    void slotSslErrors(QList<QSslError>);
    void recherche();


};

#endif // MAINWINDOW_H
