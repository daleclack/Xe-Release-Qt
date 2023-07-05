#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setStyleSheet("QMainWindow {border-image:url(:/xe_res/res/fly.png)}");
}

MainWindow::~MainWindow()
{
    delete ui;
}

