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
    void paintEvent(QPaintEvent *ev);

private:
    Ui::MainWindow *ui;
    QPixmap *pixmap;
    QPainter *painter;
};

#endif // MAINWINDOW_H
