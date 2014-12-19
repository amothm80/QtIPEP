/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
**     of its contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef MDICHILD_H
#define MDICHILD_H

#include <QWidget>
#include <QLabel>
#include <QScrollArea>
#include "imagemanip.h"

//#ifndef NULL
//#define NULL 0
//#define NULL nullptr
//#endif

struct imageNode
{
    ImageManip image;
    imageNode *next;
    imageNode *prev;
};

class MdiChild : public QScrollArea
{
    Q_OBJECT

public:
    MdiChild();
    ~MdiChild();

    bool loadFile(const QString &);
    bool saveFile(const QString &);
    void undoAction();
    void redoAction();
    void RGBSwap();
    void increaseBrightness(int v);
    void decreaseBrightness(int v);
    void horizontalEdges();
    void verticalEdges();
    void sobel();
    void heavyBlur();
    void laplacian();
    void zoomIn();
    void negative();
    void zoomOut();
    void grayScale();
    void modifyRGB(const int r, const int g, const int b);
    void horizontalFlip();
    void verticalFlip();
    void rotateClockwise();
    void rotateAntiClockwise();
//private slots:


private:

    void addImage(ImageManip img);
    void addImage(QImage img);
    void createImagesList(ImageManip img);


    double currentScaleFactor = 1.0;
    //ImageManip image;
    imageNode *images;
    QLabel *imageLabel;
    double scaleFactor;
};

#endif
