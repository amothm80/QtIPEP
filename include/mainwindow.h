#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QMdiSubWindow>
#include <QSignalMapper>
#include "imagemanip.h"
#include "mdichild.h"
#include "ui_mainwindow.h"
#include "brightnessdialog.h"
#include "rgbdialog.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;


private slots:
    MdiChild *createMdiChild();
    void setActiveSubWindow(QWidget *window);   
    bool loadFile(const QString &);
    bool saveFile(const QString &, MdiChild *mdi);

    void on_actionOpenImage_triggered();
    void on_actionSaveImage_triggered();

    void on_actionRGBSwap_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionNegative_triggered();
    void on_actionIncreaseBrightness_triggered();
    void on_actionDecreaseBrightness_triggered();
    void on_actionBrightness_triggered();
    void on_actionHorizontalEdges_triggered();
    void on_actionVerticalEdges_triggered();
    void on_actionSobel_triggered();
    void on_actionLaplacian_triggered();
    void on_actionHeavyBlur_triggered();
    void on_actionGrayScale_triggered();
    void on_actionRGB_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    // on_XXX slots are only used for auto-connect and cannot be used
    // in normal connect fucntions
    //void on_actionRGB_accepted(int r,int g,int b);
    void actionRGB_accepted(int r,int g,int b);
    void actionBrightness_accepted(int v);

private:
    MdiChild *activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);
    QSignalMapper *windowMapper;
    void resizeEvent( QResizeEvent *e );
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
