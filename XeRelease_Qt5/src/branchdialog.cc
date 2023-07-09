#include "branchdialog.h"
#include "ui_branchdialog.h"
#include <fstream>

BranchDialog::BranchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BranchDialog)
{
    ui->setupUi(this);
}

void BranchDialog::setup_config(json &json_data)
{
    std::string longterm_str, stable_str, devel_str, path_str;
    // Get configs from json data
    if(!json_data.empty()){
        longterm_str = json_data["Longterm"];
        stable_str = json_data["Stable"];
        devel_str = json_data["Develop"];
        switch(get_os_type()){
        case OS_Type::Darwin:
            darwin_path_str = json_data["Release_Path_Darwin"];
            path_str = darwin_path_str;
            break;
        case OS_Type::Linux:
            unix_path_str = json_data["Release_Path_Unix"];
            path_str = unix_path_str;
            break;
        case OS_Type::Windows:
            win32_path_str = json_data["Release_Path_Win32"];
            path_str = win32_path_str;
            break;
        }
        // Set the config to the lineedit widget
        ui->line_longterm->setText(QString(longterm_str.c_str()));
        ui->line_devel->setText(QString(devel_str.c_str()));
        ui->line_stable->setText(QString(stable_str.c_str()));
        ui->line_path->setText(QString(path_str.c_str()));
    }else{
        // Default configs
        ui->line_longterm->setText(QString("default config"));
        ui->line_stable->setText(QString("default config"));
        ui->line_devel->setText(QString("default config"));
        ui->line_path->setText(QString("./"));
    }
}

BranchDialog::~BranchDialog()
{
    delete ui;
}

void BranchDialog::on_buttonBox_accepted()
{
    // Get config values
    std::string longterm_str, stable_str, devel_str;
    longterm_str = ui->line_longterm->text().toStdString();
    stable_str = ui->line_stable->text().toStdString();
    devel_str = ui->line_devel->text().toStdString();
    switch(get_os_type()){
    case OS_Type::Darwin:
        darwin_path_str = ui->line_path->text().toStdString();
        break;
    case OS_Type::Linux:
        unix_path_str = ui->line_path->text().toStdString();
        break;
    case OS_Type::Windows:
        win32_path_str = ui->line_path->text().toStdString();
        break;
    }

    // Create json object to save data
    json data = json::parse(R"(
    {
        "Develop": "",
        "Longterm": "",
        "Release_Path_Darwin": "",
        "Release_Path_Unix": "",
        "Release_Path_Win32": "",
        "Stable": "",
        "background": 3,
        "dark_mode": false
    })");

    // Update json config values
    data["Longterm"] = longterm_str;
    data["Stable"] = stable_str;
    data["Develop"] = devel_str;
    data["Release_Path_Unix"] = unix_path_str;
    data["Release_Path_Darwin"] = darwin_path_str;
    data["Release_Path_Win32"] = win32_path_str;

    // Save json data to the file
    std::fstream outfile;
    outfile.open("xe_config.json", std::ios::out);
    if(outfile.is_open()){
        outfile << data;
    }
    outfile.close();
}


void BranchDialog::on_buttonBox_rejected()
{
}

