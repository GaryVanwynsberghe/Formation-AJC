#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{        
    ui->setupUi(this);
    connect(ui->pushButtonSortir2,SIGNAL(clicked()),
            this,SLOT(Close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Action()
{
    close();
    //std::cout << "Test" << std::endl;
}

