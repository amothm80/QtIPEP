#ifndef RGBDIALOG_H
#define RGBDIALOG_H

#include <QDialog>
#include "mainwindow.h"
#include "ui_rgbdialog.h"

namespace Ui {
class RGBDialog;
}

class RGBDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RGBDialog(QWidget *parent = 0);
    ~RGBDialog();

signals:
    void RGBValues(int,int,int);

private:
    void accept();
    Ui::RGBDialog *ui;

};

#endif // RGBDIALOG_H

