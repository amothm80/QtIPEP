#include "rgbdialog.h"
#include "ui_rgbdialog.h"

RGBDialog::RGBDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RGBDialog)
{
    ui->setupUi(this);

}

void RGBDialog::accept(){
    emit RGBValues(ui->horizontalSliderRed->value(),
                 ui->horizontalSliderGreen->value(),
                 ui->horizontalSliderBlue->value());
    QDialog::accept();
}

RGBDialog::~RGBDialog()
{
    delete ui;
}

