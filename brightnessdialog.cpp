#include "brightnessdialog.h"
#include "ui_brightnessdialog.h"

BrightnessDialog::BrightnessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessDialog)
{
    ui->setupUi(this);
}

void BrightnessDialog::accept(){
    emit brightnessValue(ui->horizontalSliderBrightness->value());
    QDialog::accept();
}


BrightnessDialog::~BrightnessDialog()
{
    delete ui;
}

