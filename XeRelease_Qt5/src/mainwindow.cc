#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "branchdialog.h"
#include <QMessageBox>
#include <fstream>

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

    // Update time for versions generation
    local = new tm;
    update_time();
    get_config();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete local;
    // delete dialog;
}

void MainWindow::get_config()
{
    // Read config from json file
    std::fstream infile;
    infile.open("xe_config.json", std::ios_base::in);

    // Read json data from file
    if(infile.is_open()){
        json_data = json::parse(infile);
        longterm_ver = json_data["Longterm"];
        stable_ver = json_data["Stable"];
        devel_ver = json_data["Develop"];

        switch(get_os_type()){
        case OS_Type::Darwin:
            break;
        case OS_Type::Linux:
            break;
        case OS_Type::Windows:
            break;
        }

        dark_mode = json_data["dark_mode"];
    }else{
        // Show a error messagebox
        QMessageBox msgbox;
        msgbox.setIcon(QMessageBox::Critical);
        msgbox.setText(QString("No vaild config file found!\nPlease create a config by the \"Preferences\" Menu"));
        msgbox.addButton(QMessageBox::Ok);
        msgbox.exec();

        // Initalize default config
        longterm_ver = "";
        stable_ver = "";
        devel_ver = "";
        path = "./";
        dark_mode = false;
    }
    infile.close();
}

void MainWindow::update_time(){
    // Get local time
    time_t t;
    t = time(NULL);
    localtime_s(local, &t);
    year.setNum(local->tm_year + 1900);
}

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
    dialog.setup_config(json_data);
    dialog.exec();
}


void MainWindow::on_actionAbout_XeRelease_Qt_triggered()
{
    // Create icon
    QPixmap pixmap = QPixmap(":/xe_res/res/Xe-Release.png");
    QMessageBox msgbox;
    QString detailed_text, version = "17.0 The Flying Dream\n";
    detailed_text = version;
    detailed_text += "Build With Qt ";
    detailed_text += QT_VERSION_STR;
    detailed_text += "\n\nA tool to get versions by date and user settings\n";
    detailed_text +="\n© 2019—";
    detailed_text += year;
    detailed_text += " The Xe Project";

    // Text of message box
    msgbox.setText(QString("### About Xe Release Qt Version"));
    msgbox.setInformativeText(detailed_text);
    msgbox.setTextFormat(Qt::TextFormat::MarkdownText);

    // Icons
    msgbox.setIconPixmap(pixmap);
    msgbox.setWindowIcon(QIcon(pixmap));

    // Only a Button
    msgbox.setStandardButtons(QMessageBox::Ok);
    msgbox.setDefaultButton(QMessageBox::Ok);
    msgbox.exec();
}

