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
    ~BranchDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::BranchDialog *ui;
};

#endif // BRANCHDIALOG_H
