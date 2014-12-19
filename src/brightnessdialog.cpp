#include "brightnessdialog.h"
#include "ui_brightnessdialog.h"

BrightnessDialog::BrightnessDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrightnessDialog)
{
    ui->setupUi(this);
    setWindowTitle("Brightness");
    setWindowIcon(QIcon(":/icons/image.ico"));
}

void BrightnessDialog::accept(){
    emit brightnessValue(ui->horizontalSliderBrightness->value());
    QDialog::accept();
}


BrightnessDialog::~BrightnessDialog()
{
    delete ui;
}

