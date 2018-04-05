#ifndef MAINWIN_H
#define MAINWIN_H

#include <QMainWindow>
#include "settings.h"
#include "qcustomplot.h"
#include "bodycls.h"
#include <QThread>

#define SIZE_ARR (512)

namespace Ui {
class MainWin;
}

class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();

private slots:
    void on_pushButton_clicked();
    void releasePlot(double *x, double *y, int size);//double  **CoordZ1344, int size, int ny);
    //void releasePlotHx(double *x, double *y, int size);//double  **CoordZ1344, int size, int ny);
    //void releasePlotHy(double *x, double *y, int size);//double  **CoordZ1344, int size, int ny);

    void on_pushButton_2_clicked();

    void on_pushButton_Settings_clicked();

private:
    Ui::MainWin *ui;
    Settings sUi;

    // Создание потока
    BodyCls * worker;
    QThread* thread;

    float i1;
    //static int SIZE_ARR = 512;
    //для полотна

    QCPColorMap *colorMap;
     QCPColorMap *colorMapHx;
      QCPColorMap *colorMapHy;

    QCPColorScale *colorScale;

    QCPColorScale *colorScaleHx;
    QCPColorScale *colorScaleHy;

    QCPMarginGroup *marginGroup;

    float radius = 8;
    float epsilon = 10;//1.5;//34.5;
    float sigma = 0.02;//10000000;//59500000;
    float height = 4.0;

    double m_dx = 0.0000003;
    float m_frequency = 30.e9;

    int m_heightRec = 5;
    int m_widthRec = 10;

    void testFunc(int size);//(double * x, int size);
    void Plot();
    //void PlotHx();
   // void PlotHy();
    void FuncPlot();
    void FDTD();

};

#endif // MAINWIN_H
