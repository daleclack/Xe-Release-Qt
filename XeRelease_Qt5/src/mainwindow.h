#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include "xerelease.hh"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btn_ver_clicked();

    void on_actionExit_triggered();

    void on_actionDefault_triggered();

    void on_actionFlos_2_0_triggered();

    void on_actionXeRelease8_9_triggered();

    void on_actionXeRelease_10_14_triggered();

    void on_actionRelease_branchs_triggered();

    void on_actionAbout_XeRelease_Qt_triggered();

private:
    Ui::MainWindow *ui;
    // struct for time
    struct tm *local;
    QString year;


    // Release names
    json json_data;
    // Version string of branchs
    std::string longterm_ver, stable_ver, devel_ver;

    // Path to save the file
    std::string path;

    // Mode string, will be enable soon
    // This config item is for compatibility
    // with the Xe Release Gtkmm4 Version
    bool dark_mode;

    void get_config();
    void update_time();
};
#endif // MAINWINDOW_H
