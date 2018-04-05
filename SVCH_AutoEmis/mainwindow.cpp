#include "MainWindow.h"
#include "ui_mainwindow.h"
#include <omp.h>


//double funcplot(int Y3, int X3, double i1, double a);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    timer = new QTimer();

    // Соединяем сигнал timeout таймера, со слотом slotTimerAlarm
    connect(timer,SIGNAL(timeout()),this, SLOT(slotTimerAlarm()));


    // поток


    thread = new QThread;

    worker = new BodyCls();


    worker->moveToThread(thread);

        // Связываем сигнал об ошибки со слотом обработки ошибок(не показан).

    connect(worker, SIGNAL(error(QString)), this, SLOT(errorHandler(QString)));

        // Соединяем сигнал started потока, со слотом process "рабочего" класса, т.е. начинается выполнение нужной работы.
      //  connect(thread, SIGNAL(started()), worker, SLOT(process()));

    connect(thread, SIGNAL(started()), worker, SLOT(process()));

        // По завершению выходим из потока, и удаляем рабочий класс

    connect(worker, SIGNAL(finished()), thread, SLOT(quit()));

   // connect(worker, SIGNAL(finished()), worker, SLOT(deleteLater()));

        // Удаляем поток, после выполнения операции

    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    //connect(worker,SIGNAL(rePlot(double **,int, int)), this, SLOT(releasePlot(double **,int,int)),  Qt::BlockingQueuedConnection);
    connect(worker,SIGNAL(rePlot(double *,double *,int)), this, SLOT(releasePlot(double *,double *,int)),  Qt::BlockingQueuedConnection);


    Plot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

 void MainWindow::Plot()
 {

     ui->widget->clearGraphs();//Если нужно, но очищаем все графики

     ui->widget->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/
    // ui->widget->setInteractions(QCP::iRangeDrag); // this will also allow rescaling the color scale by dragging/zooming

     ui->widget->axisRect()->setupFullAxesBox(true);

     ui->widget->xAxis->setLabel("x");

     ui->widget->yAxis->setLabel("y");


     // set up the QCPColorMap:

     colorMap = new QCPColorMap( ui->widget->xAxis,  ui->widget->yAxis);

     ui->widget->addPlottable(colorMap);


     //colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points

     colorMap->data()->setRange(QCPRange(-4, 4), QCPRange(-4, 4)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions





//     for (int xIndex=0; xIndex<nx; ++xIndex)
//     {
//         double r = 0;
//         for (int yIndex=0; yIndex<ny; ++yIndex)
//               {
//         //
//                  r+=0.01;
//                 z =  (qCos(r));
//                 colorMap->data()->setCell(xIndex, yIndex, z);
//               }
//    }
//int xIndex=250;


   //  colorMap->data()->setCell(0, 1,0.115);
    //  colorMap->data()->setCell(0, 0,-0.015);
    FuncPlot();
//     colorMap->data()->fill(0); // заполняем нулями, т.е. очистка


//     colorMap->data()->setSize(512, 512); // we want the color map to have nx * ny data points

//     colorMap->data()->setCell(0, 1,0.115);
//     colorMap->data()->setCell(0, 0,-0.015);
    //  ui->widget->replot();



     colorScale= new QCPColorScale( ui->widget);

     ui->widget->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect

     colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
    // colorScale->setType(QCPAxis::atLeft);

     colorMap->setColorScale(colorScale); // associate the color map with the color scale

     colorScale->axis()->setLabel("Electric Field Strength");




     // set the color gradient of the color map to one of the presets:

    // colorMap->setGradient(QCPColorGradient::gpPolar);//gpThermal
      colorMap->setGradient(QCPColorGradient::gpPolar);//gpJet


     // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:

     colorMap->rescaleDataRange();


     // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):

     marginGroup= new QCPMarginGroup( ui->widget);



     ui->widget->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

     colorScale->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);


     // rescale the key (x) and value (y) axes so the whole color map is visible:

     ui->widget->rescaleAxes();


ui->widget->replot();

     //Говорим, что отрисовать нужно график по нашим двум массивам x и y
        //ui->widget->addGraph();
 //thread->start();
     // thread->start();
    // timer->start(5);
 }



void MainWindow::FuncPlot()
{

   double x1, y1, z;


   double a = -4; //Начало интервала, где рисуем график по оси Ox

   double b =  4; //Конец интервала, где рисуем график по оси Ox

   //double h = 0.01; //Шаг, с которым будем пробегать по

   //int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем

  // QVector<double> x(N), y(N); //Массивы координат точек

   //int i=0;
   a*=64;
   b*=64;

   int size1 = 512;
   colorMap->data()->setSize(size1, size1);

   double * nxy = new double [size1*size1];
   double * onel=  new double [1];

    //double x1;
//  #pragma omp parallel for private(x1,y1,z)


   for (int X3=0; X3<size1; X3++)//Пробегаем по всем точкам
   {
       x1 = (X3 + a)/64.0;
       for (int Y3=0; Y3<=size1; Y3++)//Пробегаем по всем точкам
       {

                   y1 = (Y3+ a)/64.0;

           //colorMap->data()->cellToCoord(X3, Y3,  &x1, &y1);
                    double r = 25*qSqrt(x1*x1+y1*y1)+1e-0;//qSqrt(x*x+y*y)
                              //  double r = 5*qSqrt(xIndex*xIndex+yIndex*yIndex);//qSqrt(x*x+y*y)
                   z =  (qCos(r+2-i1)/r-qSin(r+2-i1)/r)/5.0;
                  // x1 = X/1000.0;
//                   x[i] = x1;
//                   y[i] = qSin(x1+i1);//Формула нашей функции

//                  colorMap->data()->setData(x[i],y[i],6);
                   //colorMap->data()->setData(x1,y1,z);

                 nxy[size1*X3 + Y3] = z;//funcplot(Y3,X3, 1, a);

                  // colorMap->data()->setCell(X3, Y3, z);
                   // colorMap->data()->d

       }
                   //i++;
    }

   releasePlot(nxy, onel,size1) ;
    i1+=0.1;
   if (i1 >= 6.28318530718) i1 = 0;

}




 void MainWindow::slotTimerAlarm()
 {

 //
//ui->widget->clearItems();
     //colorMap->data()->
    //ui->widget->repaint();
     colorMap->data()->fill(0); // заполняем нулями, т.е. очистка
  FuncPlot();
 ui->widget->replot();



 }






 void  MainWindow::releasePlot(double *x,double *y, int size)//double **CoordZ1344, int size, int ny)//(double x1, double y1, double z1, int xIndex1, int yIndex1)
 {




 //MessageBeep(-1);

       colorMap->data()->fill(0); // заполняем нулями, т.е. очистка

// int sizePlot = size;
// colorMap->data()->setSize(sizePlot, sizePlot); // we want the color map to have nx * ny data points
  int x1, y1;
  //double x, y;

colorMap->data()->setSize(size, size); // we want the color map to have nx * ny data points



for (int X3=0; X3<size; X3++)//Пробегаем по всем точкам
{
   // x1 = (X3 + a)/64.0;
    for (int Y3=0; Y3<size; Y3++)//Пробегаем по всем точкам
    {
        colorMap->data()->setCell(X3, Y3, x[size*X3 + Y3]);

    }
}
































// //#pragma omp parallel for private(x1,y1)
////  const int DATA_SIZE = 1024;
////  double *pInputVector1;
////  double *pInputVector2;
////  pInputVector1 = new double[DATA_SIZE];
////  pInputVector2 = new double[DATA_SIZE];
////QVector<double> qx(DATA_SIZE), qy(DATA_SIZE); //Массивы координат точек
//#pragma omp parallel for private(x1,y1)
//  for (int X3=0; X3<size; X3++)//Пробегаем по всем точкам
//  {
////      x[X3] = X3/float(2*sizePlot);

////      y[X3] = - 30*x[X3]*x[X3];

////      pInputVector1[X3]= X3/double(3*DATA_SIZE);
////      pInputVector2[X3] = -30*pInputVector1[X3]* pInputVector1[X3] ;

//      colorMap->data()->coordToCell(x[X3],y[X3],&x1,&y1);
//      colorMap->data()->setCell(x1,y1-100,-2.0);


//      colorMap->data()->coordToCell(-x[X3],y[X3],&x1,&y1);
//      //colorMap->data()->setCell(x1,y1,5.0);
//      colorMap->data()->setCell(x1,y1-100,-2.0);


//      colorMap->data()->setCell(X3-1,size-5,2.0);
//      colorMap->data()->setCell(X3-1,size-6,2.0);
////      //x1 = (X3 + nx)/512.0;
////      for (int Y3=0; Y3<sizePlot; Y3++)//Пробегаем по всем точка мs
////      {

////                // y1 = (Y3+ nx)/512.0;
////                  // colorMap->data()->setCell(X3, Y3, CoordZ1344[X3][Y3]);


////     }

//  }

// // ui->widget->graph(0)->setData(x, y);
       ui->widget->replot();
       // double  n1 = funcplot();
      // double * n = funcplot1();
      // QString s1;
      // s1.setNum(n1);
   //  ui->lineEdit->setText(s1);

 }

//void MainWindow::on_pushButton_Settings_clicked()
//{

//    SettingsWin.show();
//}
//void MainWindow::on_pushButton_2_clicked()
//{
//   // thread->start();
//    SettingsWin.show();
//}

//void MainWindow::on_pushButton_clicked()
//{
//    SettingsWin.show();
//}
