#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
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

private:
    Ui::MainWindow *ui;
    // Ui::BranchDialog dialog;

    // Release names
    std::string longterm_ver, stable_ver, devel_ver;
    void get_config();
};
#endif // MAINWINDOW_H
