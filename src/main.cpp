/*

  Qt IPEP


  Icons are freeware downloaded from
  http://www.iconarchive.com/show/my-seven-icons-by-itzikgur/Graphics-Painting-icon.html

*/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication::addLibraryPath(".");
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
