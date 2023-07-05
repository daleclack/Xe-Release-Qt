#include "branchdialog.h"
#include "ui_branchdialog.h"

BranchDialog::BranchDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BranchDialog)
{
    ui->setupUi(this);
}

BranchDialog::~BranchDialog()
{
    delete ui;
}

void BranchDialog::on_buttonBox_accepted()
{

}


void BranchDialog::on_buttonBox_rejected()
{

}

