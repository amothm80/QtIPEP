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
}

MdiChild::~MdiChild()
{

}

bool MdiChild::loadFile(const QString &fileName){
    image = ImageManip(fileName);
    QSize mdiAreaSize = parentWidget()->parentWidget()->parentWidget()->size();
    if (image.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                             tr("Cannot load %1.").arg(QDir::toNativeSeparators(fileName)));
        setWindowFilePath(QString());
        imageLabel->setPixmap(QPixmap());
        imageLabel->adjustSize();
        return false;
    }
    scaleFactor = 1.0;

    imageLabel->setPixmap(QPixmap::fromImage(image));


    if (image.width() > mdiAreaSize.width() ||
            image.height() > mdiAreaSize.height()){
        image = image.scaled(mdiAreaSize.width() * 4/5,mdiAreaSize.height()*4/5, Qt::KeepAspectRatio);
        //imageLabel->resize(mdiAreaSize * 4/5);
    }
    imageLabel->resize(image.size());
    resize(imageLabel->size());
    parentWidget()->setMaximumSize(size().width()+18,size().height()+40);
    parentWidget()->resize(size().width()+18,size().height()+40);
    setWindowFilePath(fileName);
    setWindowTitle(fileName);
    setWindowIcon(QIcon(":/icons/image.ico"));
    return true;
}

//void MdiChild::closeEvent(QCloseEvent *event)
//{

//}

void MdiChild::RGBSwap(){
    image = image.rgbSwapped();
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void MdiChild::increaseBrightness(){
    image = image.increaseBrightness(1);
    imageLabel->setPixmap(QPixmap::fromImage(image));
}
void MdiChild::decreaseBrightness(){
    image = image.decreaseBrightness(1);
    imageLabel->setPixmap(QPixmap::fromImage(image));
}
void MdiChild::horizontalEdges(){
    image = image.horizontalEdgeDetection();
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void MdiChild::verticalEdges(){
    image = image.verticalEdgeDetection();
    imageLabel->setPixmap(QPixmap::fromImage(image));
}
void MdiChild::sobel(){
    image = image.sobelTransformation();
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void MdiChild::heavyBlur(){
    image = image.heavyBlur();
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void MdiChild::laplacian(){
    image = image.laplacianTransformation();
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void MdiChild::grayScale(){
    image = image.convertGrayScale();
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void MdiChild::zoomIn(){
    if (currentScaleFactor < 3){
        currentScaleFactor *= 1.1;
        imageLabel->resize(currentScaleFactor * imageLabel->pixmap()->size());
    }
}

void MdiChild::negative(){
    image = image.negative();
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

void MdiChild::zoomOut(){
    if (currentScaleFactor > 0.3){
        currentScaleFactor *= 0.9;
        imageLabel->resize(currentScaleFactor * imageLabel->pixmap()->size());
    }
}

