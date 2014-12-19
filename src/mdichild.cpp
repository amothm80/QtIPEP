#include "mdichild.h"
#include <QMessageBox>
#include <QGuiApplication>
#include <QDir>
#include <QIcon>

// mdi child windows to display images
MdiChild::MdiChild()
{
    setAttribute(Qt::WA_DeleteOnClose);

    imageLabel = new QLabel;
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    setBackgroundRole(QPalette::Dark);
    setWidget(imageLabel);
    images = new imageNode;

}

void MdiChild::createImagesList(ImageManip img){
    images->image = img;
    images->next = NULL;
    images->prev = NULL;
}

void MdiChild::addImage(ImageManip img){
    imageNode * temp = new imageNode;
    temp->image = img;
    temp->prev = images;
    temp->next = NULL;
    images->next = temp;
    images = temp;
}


void MdiChild::addImage(QImage img){
    imageNode * temp = new imageNode;
    temp->image = img;
    temp->prev = images;
    temp->next = NULL;
    images->next = temp;
    images = temp;
}

void MdiChild::undoAction(){
    if (images->prev != NULL)
        images = images->prev;
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::redoAction(){
    if (images->next != NULL)
        images = images->next;
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

MdiChild::~MdiChild()
{

}

bool MdiChild::loadFile(const QString &fileName){
    //image = ImageManip(fileName);//
    createImagesList(ImageManip(fileName));
    QSize mdiAreaSize = parentWidget()->parentWidget()->parentWidget()->size();
    if (images->image.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                             tr("Cannot load %1.").arg(QDir::toNativeSeparators(fileName)));
        setWindowFilePath(QString());
        imageLabel->setPixmap(QPixmap());
        imageLabel->adjustSize();
        return false;
    }
    scaleFactor = 1.0;

    imageLabel->setPixmap(QPixmap::fromImage(images->image/*image*/));


    if (images->image.width() > mdiAreaSize.width() ||
            images->image.height() > mdiAreaSize.height()){
        images->image = images->image.scaled(mdiAreaSize.width() * 4/5,mdiAreaSize.height()*4/5, Qt::KeepAspectRatio);
        //imageLabel->resize(mdiAreaSize * 4/5);
    }
    imageLabel->resize(images->image.size());
    resize(imageLabel->size());
    parentWidget()->setMaximumSize(size().width()+18,size().height()+40);
    parentWidget()->resize(size().width()+18,size().height()+40);
    setWindowFilePath(fileName);
    setWindowTitle(fileName);
    setWindowIcon(QIcon(":/icons/image.ico"));
    return true;
}

bool MdiChild::saveFile(const QString &fileName){
    if (!images->image.save(fileName)) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                             tr("Cannot save %1.").arg(QDir::toNativeSeparators(fileName)));
        return false;
    };
    return true;
}

//void MdiChild::closeEvent(QCloseEvent *event)
//{

//}

void MdiChild::RGBSwap(){
    //image = image.rgbSwapped();
    addImage(images->image.rgbSwapped());
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::horizontalFlip(){
    addImage(images->image.mirrored(true,false));
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::verticalFlip(){
    addImage(images->image.mirrored(false,true));
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::increaseBrightness(int v){
    addImage(images->image.increaseBrightness(v));
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}
void MdiChild::decreaseBrightness(int v){
    addImage(images->image.decreaseBrightness(v));
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::modifyRGB(const int r, const int g, const int b){
    addImage(images->image.modifyRGB(r,g,b));
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::horizontalEdges(){
    addImage(images->image.horizontalEdgeDetection());
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::verticalEdges(){
    addImage(images->image.verticalEdgeDetection());
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}
void MdiChild::sobel(){
    addImage(images->image.sobelTransformation());
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::heavyBlur(){
    addImage(images->image.heavyBlur());
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::laplacian(){
    addImage(images->image.laplacianTransformation());
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::grayScale(){
    addImage(images->image.convertGrayScale());
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::negative(){
    addImage(images->image.negative());
    imageLabel->setPixmap(QPixmap::fromImage(images->image));
}

void MdiChild::zoomIn(){
    if (currentScaleFactor < 3){
        currentScaleFactor *= 1.1;
        imageLabel->resize(currentScaleFactor * imageLabel->pixmap()->size());
    }
}

void MdiChild::zoomOut(){
    if (currentScaleFactor > 0.3){
        currentScaleFactor *= 0.9;
        imageLabel->resize(currentScaleFactor * imageLabel->pixmap()->size());
    }
}

