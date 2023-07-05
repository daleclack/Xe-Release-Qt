#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "branchdialog.h"
#include "./ui_branchdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Default background
    QPixmap pixmap = QPixmap(":/xe_res/res/fly.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
    // delete dialog;
}

void MainWindow::get_config()
{}

void MainWindow::on_btn_ver_clicked()
{
    // Get Index of selection
    int current_index = ui->combo_branch->currentIndex();
    switch(current_index)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    }
}


void MainWindow::on_actionExit_triggered()
{
    // Quit the application
    QCoreApplication::quit();
}

void MainWindow::on_actionFlos_2_0_triggered()
{
    // Background for flos 2.0
    QPixmap pixmap = QPixmap(":/xe_res/res/flos2.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}


void MainWindow::on_actionDefault_triggered()
{
    // Background since Xe Release 15
    QPixmap pixmap = QPixmap(":/xe_res/res/fly.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}


void MainWindow::on_actionXeRelease8_9_triggered()
{
    // Background since Xe Release 8
    QPixmap pixmap = QPixmap(":/xe_res/res/winpe.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}


void MainWindow::on_actionXeRelease_10_14_triggered()
{
    // Background since Xe Relase 10
    QPixmap pixmap = QPixmap(":/xe_res/res/img7.png").scaled(this->size());
    QPalette palette(this->palette());
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}


void MainWindow::on_actionRelease_branchs_triggered()
{
    BranchDialog dialog(this);
    dialog.exec();
}

