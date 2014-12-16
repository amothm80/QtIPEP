#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mdiArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->mdiArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);

    //connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),this,SLOT());
    windowMapper = new QSignalMapper(this);
    connect(windowMapper,SIGNAL(mapped(QWidget*)),this,SLOT(setActiveSubWindow(QWidget*)));
    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);
    ui->mdiArea->resize(size());
    setWindowTitle("QtIPEP");
    setWindowIcon(QIcon(":/icons/image.ico"));
//    this->loadFile("D:/Users/Ahmed/Pictures/4 x 6 cm 1.jpg");

}

void MainWindow::resizeEvent( QResizeEvent *e )
{
  QMainWindow::resizeEvent(e);
  ui->mdiArea->resize(e->size());
}

void MainWindow::closeEvent(QCloseEvent *event){
    ui->mdiArea->closeAllSubWindows();
    if(ui->mdiArea->currentSubWindow()){
        event->ignore();
    }else{
        event->accept();
    }
}

MdiChild *MainWindow::createMdiChild()
{
    MdiChild *child = new MdiChild;
    ui->mdiArea->addSubWindow(child);
    return child;
}

void MainWindow::on_actionOpenImage_triggered()
{
    QStringList mimeTypeFilters;
    foreach (const QByteArray &mimeTypeName, QImageReader::supportedMimeTypes())
        mimeTypeFilters.append(mimeTypeName);
    mimeTypeFilters.sort();
    const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QFileDialog dialog(this, tr("Open File"),
                       picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.first());
    dialog.setAcceptMode(QFileDialog::AcceptOpen);
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().first())) {}
}

bool MainWindow::loadFile(const QString &fileName)
{
    MdiChild *child = createMdiChild();
    child->show();
    return child->loadFile(fileName);
}

void MainWindow::setActiveSubWindow(QWidget *window)
{
    if (!window)
        return;
    ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(window));
}

MdiChild *MainWindow::activeMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<MdiChild *>(activeSubWindow->widget());
    return 0;
}

void MainWindow::on_actionRGBSwap_triggered(){
    activeMdiChild()->RGBSwap();
}

void MainWindow::on_actionIncreaseBrightness_triggered(){
    activeMdiChild()->increaseBrightness();
}
void MainWindow::on_actionDecreaseBrightness_triggered(){
    activeMdiChild()->decreaseBrightness();
}

void MainWindow::on_actionRGB_triggered(){
    activeMdiChild()->modifyRGB();
}

void MainWindow::on_actionHorizontalEdges_triggered(){
    activeMdiChild()->horizontalEdges();
}

void MainWindow::on_actionVerticalEdges_triggered(){
    activeMdiChild()->verticalEdges();
}
void MainWindow::on_actionSobel_triggered(){
    activeMdiChild()->sobel();
}

void MainWindow::on_actionHeavyBlur_triggered(){
    activeMdiChild()->heavyBlur();
}

void MainWindow::on_actionLaplacian_triggered(){
    activeMdiChild()->laplacian();
}

void MainWindow::on_actionZoomIn_triggered(){
    activeMdiChild()->zoomIn();
}

void MainWindow::on_actionNegative_triggered(){
    activeMdiChild()->negative();
}

void MainWindow::on_actionZoomOut_triggered(){
    activeMdiChild()->zoomOut();
}

void MainWindow::on_actionGrayScale_triggered(){
    activeMdiChild()->grayScale();
}

MainWindow::~MainWindow()
{
    delete ui;
}
