#ifndef RGBDIALOG_H
#define RGBDIALOG_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class RGBDialog;
}

class RGBDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RGBDialog(QWidget *parent = 0);
    ~RGBDialog();

private:
    Ui::RGBDialog *ui;
};

#endif // RGBDIALOG_H

