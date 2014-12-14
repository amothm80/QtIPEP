#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QMdiSubWindow>
#include <QSignalMapper>
#include "imagemanip.h"
#include "mdichild.h"

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
    void on_actionOpenImage_triggered();
    void on_actionRGBSwap_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_actionNegative_triggered();
    void on_actionIncreaseBrightness_triggered();
    void on_actionDecreaseBrightness_triggered();
    void on_actionHorizontalEdges_triggered();
    void on_actionVerticalEdges_triggered();
    void on_actionSobel_triggered();
    void on_actionLaplacian_triggered();
    void on_actionHeavyBlur_triggered();

private:
    MdiChild *activeMdiChild();
    QMdiSubWindow *findMdiChild(const QString &fileName);
    QSignalMapper *windowMapper;
    void resizeEvent( QResizeEvent *e );

//    double currentScaleFactor = 1.0;
    Ui::MainWindow *ui;
//    ImageManip image;
//    QLabel *imageLabel;
//    QScrollArea *scrollArea;
//    double scaleFactor;
};

#endif // MAINWINDOW_H
