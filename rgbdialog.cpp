#include "rgbdialog.h"
#include "ui_rgbdialog.h"

RGBDialog::RGBDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RGBDialog)
{
    ui->setupUi(this);
}

RGBDialog::~RGBDialog()
{
    delete ui;
}

