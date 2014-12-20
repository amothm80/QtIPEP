#ifndef GAMMADIALOG_H
#define GAMMADIALOG_H

#include <QDialog>

namespace Ui {
class GammaDialog;
}

class GammaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GammaDialog(QWidget *parent = 0);
    ~GammaDialog();

signals:
    void gammaValue(double);
    void doubleValueChanged(double value);

public slots:
    void notifyValueChanged(int value);

private:
    void accept();
    Ui::GammaDialog *ui;
};

#endif // GAMMADIALOG_H
