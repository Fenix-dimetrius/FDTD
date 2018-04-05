#ifndef BODYCLS_H
#define BODYCLS_H

#include <QObject>
//#include "ui_MainWindow.h"
class BodyCls : public QObject
{
    Q_OBJECT
public:
  //  explicit BodyCls(QObject *parent = 0);
    BodyCls();
    virtual ~BodyCls();


signals:
    void rePlot(double *x,double *y,int size);//double **CoordZ1, int size, int ny );
   // void rePlotHx(double *x,double *y,int size);
    //void rePlotHy(double *x,double *y,int size);
    void finished();
    void error(QString err);
public slots:
    void process();
private:
    void createMassiveFields();

    double  **CoordZWork;
    double  **materialCoord;
    void electrodCoord(int sizePlot);
   // void
    double  funcplot( int Y3, int X3, double i1, double a);

    bool isWork;

    void FDTD();

    float radius;
    float epsilon;
    float sigma;
    float height;
    double ddx;
    int    IE = 64;        // Number of cells in x
    int JE = 64;//384;
    float freq[3];

    int fieldChouse = 0;

    int heightRec;
    int widthRec;



    void fdtdPML();
public:
    void reset();
    void setParam(float sig, float eps,float m_radius, float m_height, int m_heightRec,int m_widthRec, double m_dx,float m_freq);
    void fieldPlotSet(int numField);





};

#endif // BODYCLS_H
