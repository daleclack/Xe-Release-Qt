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


void MainWindow::on_btn_ver_clicked()
{

}


void MainWindow::on_actionExit_triggered()
{
    // Quit the application
    QCoreApplication::quit();
}

void MainWindow::on_actionFlos_2_0_triggered()
{
    this->setStyleSheet("QMainWindow {border-image:url(:/xe_res/res/flos2.png)}");
}


void MainWindow::on_actionDefault_triggered()
{
    this->setStyleSheet("QMainWindow {border-image:url(:/xe_res/res/fly.png)}");
}


void MainWindow::on_actionXeRelease8_9_triggered()
{
    this->setStyleSheet("QMainWindow {border-image:url(:/xe_res/res/winpe.png)}");
}


void MainWindow::on_actionXeRelease_10_14_triggered()
{
    this->setStyleSheet("QMainWindow {border-image:url(:/xe_res/res/img7.png)}");
}

