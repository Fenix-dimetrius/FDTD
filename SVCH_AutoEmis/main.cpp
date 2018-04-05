//#include "MainWindow.h"
#include "MainWin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
   // MainWindow w;
    MainWin w;
    w.show();

    return a.exec();
}
