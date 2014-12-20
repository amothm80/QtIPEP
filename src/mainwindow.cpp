#include "mainwindow.h"

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

void MainWindow::on_actionSaveImage_triggered(){
    if (activeMdiChild()){
    MdiChild *mdi = activeMdiChild();
    QStringList mimeTypeFilters;
    foreach (const QByteArray &mimeTypeName, QImageReader::supportedMimeTypes())
        mimeTypeFilters.append(mimeTypeName);
    const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QFileDialog dialog(this,tr("Save Image"),
                picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.first());
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");

    while (dialog.exec() == QDialog::Accepted && !saveFile(dialog.selectedFiles().first(), mdi)) {}
    }
}

bool MainWindow::loadFile(const QString &fileName)
{
    MdiChild *child = createMdiChild();
    child->show();
    return child->loadFile(fileName);
}


bool MainWindow::saveFile(const QString &fileName, MdiChild *mdi)
{
    return mdi->saveFile(fileName);
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
    if (activeMdiChild())
    activeMdiChild()->RGBSwap();
}

void MainWindow::on_actionUndo_triggered(){
    if (activeMdiChild())
    activeMdiChild()->undoAction();
}

void MainWindow::on_actionRedo_triggered(){
    if (activeMdiChild())
    activeMdiChild()->redoAction();
}

void MainWindow::on_actionIncreaseBrightness_triggered(){
    if (activeMdiChild())
    activeMdiChild()->increaseBrightness(1);
}
void MainWindow::on_actionDecreaseBrightness_triggered(){
    if (activeMdiChild())
    activeMdiChild()->decreaseBrightness(1);
}

void MainWindow::actionBrightness_accepted(int v){
    if (activeMdiChild()){
    if (v > 0)
        activeMdiChild()->increaseBrightness(v);
    else if (v < 0)
        activeMdiChild()->decreaseBrightness(abs(v));
    }
}

void MainWindow::on_actionBrightness_triggered(){
    if (activeMdiChild()){
    BrightnessDialog d;
    connect(&d,SIGNAL(brightnessValue(int)),this,SLOT(actionBrightness_accepted(int)));
    d.exec();
    }
}

void MainWindow::on_actionGammaCorrection_triggered(){
    if (activeMdiChild()){
    GammaDialog d;
    connect(&d,SIGNAL(gammaValue(double)),this,SLOT(actionGammaCorrection_accepted(double)));
    d.exec();
    }
}

void MainWindow::on_actionRGB_triggered(){
    if (activeMdiChild()){
    RGBDialog d;
    connect(&d,SIGNAL(RGBValues(int,int,int)),this,SLOT(actionRGB_accepted(int,int,int)));
    d.exec();
    }
}

void MainWindow::actionRGB_accepted(int r, int g, int b){
    if (activeMdiChild())
    activeMdiChild()->modifyRGB(r,g,b);
}

void MainWindow::actionGammaCorrection_accepted(double v){
    if (activeMdiChild())
    activeMdiChild()->gammaCorrection(v);
}

void MainWindow::on_actionHorizontalEdges_triggered(){
    if (activeMdiChild())
    activeMdiChild()->horizontalEdges();
}

void MainWindow::on_actionVerticalEdges_triggered(){
    if (activeMdiChild())
    activeMdiChild()->verticalEdges();
}
void MainWindow::on_actionSobel_triggered(){
    if (activeMdiChild())
    activeMdiChild()->sobel();
}

void MainWindow::on_actionHeavyBlur_triggered(){
    if (activeMdiChild())
    activeMdiChild()->heavyBlur();
}

void MainWindow::on_actionLightBlur_triggered(){
    if (activeMdiChild())
    activeMdiChild()->lightBlur();
}

void MainWindow::on_actionHighPass_triggered(){
    if (activeMdiChild())
    activeMdiChild()->highPass();
}

void MainWindow::on_actionLowPass_triggered(){
    if (activeMdiChild())
    activeMdiChild()->lowPass();
}

void MainWindow::on_actionLaplacian_triggered(){
    activeMdiChild()->laplacian();
}

void MainWindow::on_actionZoomIn_triggered(){
    if (activeMdiChild())
    activeMdiChild()->zoomIn();
}

void MainWindow::on_actionNegative_triggered(){
    if (activeMdiChild())
    activeMdiChild()->negative();
}

void MainWindow::on_actionZoomOut_triggered(){
    if (activeMdiChild())
    activeMdiChild()->zoomOut();
}

void MainWindow::on_actionGrayScale_triggered(){
    if (activeMdiChild())
        activeMdiChild()->grayScale();
}

void MainWindow::on_actionHorizontalFlip_triggered(){
    if (activeMdiChild())
        activeMdiChild()->horizontalFlip();
}

void MainWindow::on_actionVerticalFlip_triggered(){
    if (activeMdiChild())
        activeMdiChild()->verticalFlip();
}

void MainWindow::on_actionRotateClockwise_triggered(){
    if (activeMdiChild())
        activeMdiChild()->rotateClockwise();
}

void MainWindow::on_actionRotateAnticlockwise_triggered(){
    if (activeMdiChild())
        activeMdiChild()->rotateAntiClockwise();
}

MainWindow::~MainWindow()
{
    delete ui;
}
