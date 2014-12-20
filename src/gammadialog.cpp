#include "gammadialog.h"
#include "ui_gammadialog.h"

GammaDialog::GammaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GammaDialog)
{
    ui->setupUi(this);
    setWindowTitle("Gamma");
    setWindowIcon(QIcon(":/icons/image.ico"));
    connect(this->ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(notifyValueChanged(int)));
    connect(this,SIGNAL(doubleValueChanged(double)),this->ui->labelGammaValue,SLOT(setNum(double)));

}

void GammaDialog::notifyValueChanged(int value){
    emit doubleValueChanged(value/10.0);
}

void GammaDialog::accept(){
    emit gammaValue(ui->horizontalSlider->value()/10.0);
    QDialog::accept();
}

GammaDialog::~GammaDialog()
{
    delete ui;
}
