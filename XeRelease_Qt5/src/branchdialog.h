#ifndef BRANCHDIALOG_H
#define BRANCHDIALOG_H

#include <QDialog>
#include "xerelease.hh"

namespace Ui {
class BranchDialog;
}

class BranchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit BranchDialog(QWidget *parent = nullptr);
    void setup_config(json &json_data);
    ~BranchDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::BranchDialog *ui;

    // Json object
    json json_data1;

    // string to save custom path configs
    std::string unix_path_str, win32_path_str, darwin_path_str;
};

#endif // BRANCHDIALOG_H
