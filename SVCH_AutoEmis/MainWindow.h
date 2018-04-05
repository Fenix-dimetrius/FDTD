#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//#ifndef MainWindow_H
//#define MainWindow_H

#include <QMainWindow>
//#include "ui_mainwindow.h"
#include "qcustomplot.h"
#include "bodycls.h"
#include <QThread>
#include "settings.h"
#include "funcplot.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int nx = 1024;
    int ny = 1024;
    double  y0  = 0;
    float i1;

    QCPColorMap *colorMap;

    QCPColorScale *colorScale;

    QCPMarginGroup *marginGroup;

    Settings SettingsWin;

    // Создание потока
    BodyCls * worker;
    QThread* thread;

    void Plot();
    void FuncPlot();

private slots:
    void slotTimerAlarm();
     void releasePlot(double *x, double *y, int size);//double  **CoordZ1344, int size, int ny);

    // void on_pushButton_Settings_clicked();

     //void on_pushButton_clicked();


   //  void on_pushButton_clicked();

     //void on_pushButton_2_clicked();

    // void on_pushButton_2_clicked();

    // void on_pushButton_2_clicked();

    // void on_pushButton_clicked();


    // void on_pushButton_clicked();
    // void on_pushButton_3_clicked();
   //  void on_pushButton_clicked();
};

#endif // MAINWINDOW_H
