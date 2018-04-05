#include "MainWin.h"
#include "ui_MainWin.h"
#include "physconst.h"


#define COLOR_BOUND (1)

MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWin)
{
    ui->setupUi(this);

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

   // connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    //connect(worker,SIGNAL(rePlot(double **,int, int)), this, SLOT(releasePlot(double **,int,int)),  Qt::BlockingQueuedConnection);
    connect(worker,SIGNAL(rePlot(double *,double *,int)), this, SLOT(releasePlot(double *,double *,int)),  Qt::BlockingQueuedConnection);
    //connect(worker,SIGNAL(rePlotHx(double *,double *,int)), this, SLOT(releasePlotHx(double *,double *,int)),  Qt::BlockingQueuedConnection);
     //connect(worker,SIGNAL(rePlotHy(double *,double *,int)), this, SLOT(releasePlotHy(double *,double *,int)),  Qt::BlockingQueuedConnection);

     // устанавливаем значения проводимости, проницаемости и радиуса цилиндра


     QString str;

     str.setNum(radius);

     ui->lineEdit_Radius->setText(str);

     str.setNum(epsilon);

     ui->lineEdit_Epsilon->setText(str);

     str.setNum(sigma);

     ui->lineEdit_Sigma->setText(str);

     str.setNum(height);

     ui->lineEdit_Height->setText(str);

     str.setNum(m_dx);

     ui->lineEdit_Step->setText(str);

     str.setNum(m_heightRec);

     ui->lineEdit_HeightRec->setText(str);

     str.setNum(m_widthRec);

     ui->lineEdit_WidthRec->setText(str);

     str.setNum(m_frequency);

     ui->lineEdit_Frequency->setText(str);


    Plot();
   // PlotHx();
   // PlotHy();
}

MainWin::~MainWin()
{
    delete ui;
    thread->deleteLater(); // удаляем поток
}

void MainWin::Plot()
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

   // FuncPlot();
    //FDTD();
    // устанавливаем границы цветности полотна(костыль)
    colorMap->data()->setSize(5,5);
    //colorMap->data()->setCell(2,3,-COLOR_BOUND);
   // colorMap->data()->setCell(2,1,COLOR_BOUND);

    colorScale= new QCPColorScale( ui->widget);

    ui->widget->plotLayout()->addElement(0, 1, colorScale); // add it to the right of the main axis rect

    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
   // colorScale->setType(QCPAxis::atLeft);

    colorMap->setColorScale(colorScale); // associate the color map with the color scale

    //colorScale->axis()->setLabel("Electric Field Strength");




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

}

//void MainWin::PlotHx()
//{
//    ui->widget_hx->clearGraphs();//Если нужно, но очищаем все графики

//    ui->widget_hx->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/
//   // ui->widget->setInteractions(QCP::iRangeDrag); // this will also allow rescaling the color scale by dragging/zooming

//    ui->widget_hx->axisRect()->setupFullAxesBox(true);

//    ui->widget_hx->xAxis->setLabel("x");

//    ui->widget_hx->yAxis->setLabel("y");


//    // set up the QCPColorMap:

//    colorMapHx = new QCPColorMap( ui->widget_hx->xAxis,  ui->widget_hx->yAxis);

//    ui->widget_hx->addPlottable(colorMapHx);


//    //colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points

//    colorMapHx->data()->setRange(QCPRange(-4, 4), QCPRange(-4, 4)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions

//   // FuncPlot();
//    //FDTD();
//    // устанавливаем границы цветности полотна(костыль)
//    colorMapHx->data()->setSize(5,5);
//    colorMapHx->data()->setCell(2,3,-COLOR_BOUND);
//    colorMapHx->data()->setCell(2,1,COLOR_BOUND);

//    colorScaleHx= new QCPColorScale( ui->widget_hx);

//    ui->widget_hx->plotLayout()->addElement(0, 1, colorScaleHx); // add it to the right of the main axis rect

//    colorScaleHx->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
//   // colorScale->setType(QCPAxis::atLeft);

//    colorMapHx->setColorScale(colorScaleHx); // associate the color map with the color scale

//    colorScaleHx->axis()->setLabel("Hx");




//    // set the color gradient of the color map to one of the presets:

//   // colorMap->setGradient(QCPColorGradient::gpPolar);//gpThermal
//     colorMapHx->setGradient(QCPColorGradient::gpPolar);//gpJet


//    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:

//    colorMapHx->rescaleDataRange();


//    // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):

//    marginGroup= new QCPMarginGroup( ui->widget_hx);



//    ui->widget_hx->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

//    colorScaleHx->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);


//    // rescale the key (x) and value (y) axes so the whole color map is visible:

//    ui->widget_hx->rescaleAxes();


//    ui->widget_hx->replot();

//}

//void MainWin::PlotHy()
//{
//    ui->widget_hy->clearGraphs();//Если нужно, но очищаем все графики

//    ui->widget_hy->setInteractions(QCP::iRangeDrag|QCP::iRangeZoom); // this will also allow rescaling the color scale by dragging/
//   // ui->widget->setInteractions(QCP::iRangeDrag); // this will also allow rescaling the color scale by dragging/zooming

//    ui->widget_hy->axisRect()->setupFullAxesBox(true);

//    ui->widget_hy->xAxis->setLabel("x");

//    ui->widget_hy->yAxis->setLabel("y");


//    // set up the QCPColorMap:

//    colorMapHy = new QCPColorMap( ui->widget_hy->xAxis,  ui->widget_hy->yAxis);

//    ui->widget_hy->addPlottable(colorMapHy);


//    //colorMap->data()->setSize(nx, ny); // we want the color map to have nx * ny data points

//    colorMapHy->data()->setRange(QCPRange(-4, 4), QCPRange(-4, 4)); // and span the coordinate range -4..4 in both key (x) and value (y) dimensions

//   // FuncPlot();
//    //FDTD();
//    // устанавливаем границы цветности полотна(костыль)
//    colorMapHy->data()->setSize(5,5);
//    colorMapHy->data()->setCell(2,3,-COLOR_BOUND);
//    colorMapHy->data()->setCell(2,1,COLOR_BOUND);

//    colorScaleHy= new QCPColorScale( ui->widget_hy);

//    ui->widget_hy->plotLayout()->addElement(0, 1, colorScaleHy); // add it to the right of the main axis rect

//    colorScale->setType(QCPAxis::atRight); // scale shall be vertical bar with tick/axis labels right (actually atRight is already the default)
//   // colorScale->setType(QCPAxis::atLeft);

//    colorMapHy->setColorScale(colorScaleHy); // associate the color map with the color scale

//    colorScaleHy->axis()->setLabel("Hy");




//    // set the color gradient of the color map to one of the presets:

//   // colorMap->setGradient(QCPColorGradient::gpPolar);//gpThermal
//     colorMapHy->setGradient(QCPColorGradient::gpPolar);//gpJet


//    // rescale the data dimension (color) such that all data points lie in the span visualized by the color gradient:

//    colorMapHy->rescaleDataRange();


//    // make sure the axis rect and color scale synchronize their bottom and top margins (so they line up):

//    marginGroup= new QCPMarginGroup( ui->widget_hy);



//    ui->widget_hy->axisRect()->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);

//    colorScaleHy->setMarginGroup(QCP::msBottom|QCP::msTop, marginGroup);


//    // rescale the key (x) and value (y) axes so the whole color map is visible:

//    ui->widget_hy->rescaleAxes();


//    ui->widget_hy->replot();

//}

void MainWin::FuncPlot()
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

   int size1 = 60;
//   colorMap->data()->setSize(size1, size1);
//    colorMap->data()->setCell(1, 1, 0.01);
 //  worker->process();

//   double * nxy = new double [size1*size1];
//   double * onel=  new double [1];

//    //double x1;
////  #pragma omp parallel for private(x1,y1,z)


//   for (int X3=0; X3<size1; X3++)//Пробегаем по всем точкам
//   {
//       x1 = (X3 + a)/64.0;
//       for (int Y3=0; Y3<=size1; Y3++)//Пробегаем по всем точкам
//       {

//                   y1 = (Y3+ a)/64.0;

//           //colorMap->data()->cellToCoord(X3, Y3,  &x1, &y1);
//                    double r = 25*qSqrt(x1*x1+y1*y1)+1e-0;//qSqrt(x*x+y*y)
//                              //  double r = 5*qSqrt(xIndex*xIndex+yIndex*yIndex);//qSqrt(x*x+y*y)
//                   z =  (qCos(r+2-i1)/r-qSin(r+2-i1)/r)/5.0;
//                  // x1 = X/1000.0;
////                   x[i] = x1;
////                   y[i] = qSin(x1+i1);//Формула нашей функции

////                  colorMap->data()->setData(x[i],y[i],6);
//                   //colorMap->data()->setData(x1,y1,z);

//                 nxy[size1*X3 + Y3] = z;//funcplot(Y3,X3, 1, a);

//                  // colorMap->data()->setCell(X3, Y3, z);
//                   // colorMap->data()->d

//       }
//                   //i++;
//    }

//   releasePlot(nxy, onel,size1) ;
//    i1+=0.1;
//   if (i1 >= 6.28318530718) i1 = 0;

}



void  MainWin::releasePlot(double *x,double *y, int size)//double **CoordZ1344, int size, int ny)//(double x1, double y1, double z1, int xIndex1, int yIndex1)
{





//MessageBeep(-1);

     colorMap->data()->fill(0); // заполняем нулями, т.е. очистка

//// int sizePlot = size;
//// colorMap->data()->setSize(sizePlot, sizePlot); // we want the color map to have nx * ny data points
 //int x1, y1;
 //double x, y;

colorMap->data()->setSize(size, size); // we want the color map to have nx * ny data points



//for ( j = ja; j < jb; j++ ) {
//   for ( i=ia; i < ib; i++ ) {
//   xdist = (ic-i);
//   ydist = (jc-j);
//   dist = sqrt(pow(xdist,2.) + pow(ydist,2.));
// if( dist <= radius) {
//    ga[JE*i + j] = 1./(epsilon + (sigma*dt/epsz));
//    gb[JE*i + j] = sigma*dt/epsz;
//         }
//    }
// }
//int ic1 =size/2;
//int jc1 =size/2;
//float xdist,ydist,dist;
//float radius = 80;

#pragma omp parallel for
for (int X3=0; X3<size; X3++)//Пробегаем по всем точкам
{
  // x1 = (X3 + a)/64.0;
   for (int Y3=0; Y3<size; Y3++)//Пробегаем по всем точкам
   {
       //colorMap->data()->setCell(X3, size/2, 0.7);

      // colorMap->data()->setCell(X3, Y3, x[size*X3 + Y3]);
       if( y[size*X3 + Y3] != 1)
       {
       //colorMap->data()->setCell(X3, Y3, x[size*X3 + Y3] +y[size*X3 + Y3] );
        colorMap->data()->setCell(X3, Y3, x[size*X3 + Y3] +0.5);
       }
       else
       {
           colorMap->data()->setCell(X3, Y3, x[size*X3 + Y3]  );
       }

//       xdist = (ic1-X3);
//          ydist = (jc1-Y3);
//          dist = sqrt(pow(xdist,2.) + pow(ydist,2.));
//        if( dist <= radius && dist > radius-1 ) {
//            colorMap->data()->setCell(X3, Y3, 0.2);
//            //x[size*X3 + Y3] = 2;
//           //ga[JE*i + j] = 1./(epsilon + (sigma*dt/epsz));
//           //gb[JE*i + j] = sigma*dt/epsz;
//                }

      // colorMap->data()->setCell(X3, Y3, x[size*X3 + Y3]);
      // colorMap->data()->s

   }
}

ui->widget->replot();

QString str;

str.setNum(*y);

ui->lineEdit->setText(str);



// выбор поля для отрисовки

worker->fieldPlotSet(ui->radioButton_Ez->isChecked() ? 0 :
                     ui->radioButton_Hy->isChecked() ? 1 :
                     ui->radioButton_Hx->isChecked() ? 2 :
                     ui->radioButton_Ja->isChecked() ? 3 :0);


}

//void  MainWin::releasePlotHx(double *x,double *y, int size)//double **CoordZ1344, int size, int ny)//(double x1, double y1, double z1, int xIndex1, int yIndex1)
//{




////MessageBeep(-1);

//     colorMapHx->data()->fill(0); // заполняем нулями, т.е. очистка

////// int sizePlot = size;
////// colorMap->data()->setSize(sizePlot, sizePlot); // we want the color map to have nx * ny data points
// //int x1, y1;
// //double x, y;

//colorMapHx->data()->setSize(size, size); // we want the color map to have nx * ny data points

////int ic1 =size/2;
////int jc1 =size/2;
////float xdist,ydist,dist;
//#pragma omp parallel for
//for (int X3=0; X3<size; X3++)//Пробегаем по всем точкам
//{
//  // x1 = (X3 + a)/64.0;
//   for (int Y3=0; Y3<size; Y3++)//Пробегаем по всем точкам
//   {
//        // colorMapHx->data()->setCell(X3, Y3, x[size*X3 + Y3]);

//       if( y[size*X3 + Y3] != 1)
//       {
//       //colorMapHx->data()->setCell(X3, Y3, x[size*X3 + Y3] +y[size*X3 + Y3] );
//           colorMapHx->data()->setCell(X3, Y3, x[size*X3 + Y3] +0.1 );
//       }
//       else
//       {
//           colorMapHx->data()->setCell(X3, Y3, x[size*X3 + Y3]  );
//       }
////       xdist = (ic1-X3);
////          ydist = (jc1-Y3);
////          dist = sqrt(pow(xdist,2.) + pow(ydist,2.));
////        if( dist <= radius && dist > radius-1 ) {
////            colorMapHx->data()->setCell(X3, Y3, 0.2);
////            //x[size*X3 + Y3] = 2;
////        }

//      // colorMap->data()->s

//   }
//}

//ui->widget_hx->replot();

////QString str;

////str.setNum(*y);

////ui->lineEdit->setText(str);


//}
//void  MainWin::releasePlotHy(double *x,double *y, int size)//double **CoordZ1344, int size, int ny)//(double x1, double y1, double z1, int xIndex1, int yIndex1)
//{




////MessageBeep(-1);

//     colorMapHy->data()->fill(0); // заполняем нулями, т.е. очистка

////// int sizePlot = size;
////// colorMap->data()->setSize(sizePlot, sizePlot); // we want the color map to have nx * ny data points
// //int x1, y1;
// //double x, y;

//colorMapHy->data()->setSize(size, size); // we want the color map to have nx * ny data points

////int ic1 =size/2;
////int jc1 =size/2;
////float xdist,ydist, dist;
////#pragma omp parallel for private (xdist)


//for (int Y3=0; Y3<size; Y3++)
////for (int X3=0; X3<size; X3++)//Пробегаем по всем точкам
//{
//  // x1 = (X3 + a)/64.0;
// for (int X3=0; X3<size; X3++)
//    //  for (int Y3=0; Y3<size; Y3++)//Пробегаем по всем точкам
//   {

//       // colorMapHy->data()->setCell(X3, Y3, x[size*X3 + Y3] +y[size*X3 + Y3] );
//        if( y[size*X3 + Y3] != 1)
//        {
//       // colorMapHy->data()->setCell(X3, Y3, x[size*X3 + Y3] +y[size*X3 + Y3] );
//          colorMapHy->data()->setCell(X3, Y3, x[size*X3 + Y3] + 0.1 );
//        }
//        else
//        {
//            colorMapHy->data()->setCell(X3, Y3, x[size*X3 + Y3]  );
//        }
////       xdist = abs(ic1-X3);
////         // ydist = abs(jc1-Y3);
////          //dist = sqrt(pow(ic1-X3,2.) + pow(jc1-Y3,2.));
////       // if( dist <= radius && dist > radius-1 )
////           if (xdist <=radius-(Y3/2) && xdist <=radius-1-(Y3/2) && xdist >= 0){
////            colorMapHy->data()->setCell(X3, size - Y3, 0.2);
////            //x[size*X3 + Y3] = 2;
////        }

//      // colorMap->data()->s

//   }
//}

//ui->widget_hy->replot();

////QString str;

////str.setNum(*y);

////ui->lineEdit->setText(str);


//}

void MainWin::on_pushButton_clicked()
{
 //   sUi.show();
    //sUi.close();
   // sUi.c
}





void MainWin::FDTD()
{




     int    IE =128,//32,        // Number of cells in x
        JE = 128,//32,        // Number of cells in y
        ic = IE / 2,      // Middle of the grid in x
        jc = JE / 2;      // Middle of the grid in y
                          //    const double dx = 0.01,      // Cell size [m]
                          //                 dt = dx/(2*co); // Time step [s]
    double       T = 0.0;        // Time
    const int    NSTEPS = 220;//92;  // Number of time steps

    const double t0 = 20.0,      // Center of the incident pulse
        spread = 3.0;   // Width of the incident pulse

//    double       dz[IE][JE],     // Field containers
//        ez[IE][JE],
//        hx[IE][JE],
//        hy[IE][JE],
//        ga[IE][JE];     // Stores medium profile
    double * dz = new double [IE*JE];
     double * ez = new double [IE*JE];
      double * hx = new double [IE*JE];
       double * hy = new double [IE*JE];
        double * ga = new double [IE*JE];


    int  n = 0, i = 0, j = 0;    // Loops iterators

   // double * exy = new double [IE*JE];
    double * onel=  new double [10];

//    //std::ofstream fp;

//    // Initialize the E field and all cells to free space
    for (j = 0; j < JE; j++)
    {
        for (i = 0; i < IE; i++)
        {
//            dz[i][j] = 0.0;
//            ez[i][j] = 0.0;
//            hx[i][j] = 0.0;
//            hy[i][j] = 0.0;
//            ga[i][j] = 1.0;
            dz[JE*i + j] = 0.0;
            ez[JE*i + j] = 0.0;
            hx[JE*i + j] = 0.0;
            hy[JE*i + j] = 0.0;
            ga[JE*i + j] = 1.0;

            //exy[JE*i + j] = 0.0;
        } // end of i for
    } // end of j for

//      // Check if there is at least 2 steps
    if (NSTEPS <= 1) {


////		std::cout << "Error: Number of steps must be larger than 1."
////			<< std::endl;
////		getchar();
    }

    else {
//        // FDTD loop
      for (n = 1; n <= NSTEPS; n++)
        {
            T += 1.0;   // T keeps track of the number of times FDTD loop
                        // is executed.

                        // Calculate the Dz field
            for (j = 1; j < JE; j++) {
                for (i = 1; i < IE; i++) {
//                    dz[i][j] += 0.5*(hy[i][j] - hy[i - 1][j]
//                        - hx[i][j] + hx[i][j - 1]);
                    dz[JE*i + j] += 0.5*(hy[JE*i + j] - hy[JE*(i-1) + j]
                        - hx[JE*i + j] + hx[JE*i + j-1]);
                } // end of i for
            } // end of j for

              // Put a Gaussian pulse in the middle
            dz[JE*ic + jc] = exp(-0.5*pow((t0 - T) / spread, 2.0));

            // Calculate the Ez field
            for (j = 1; j < JE; j++) {
                for (i = 1; i < IE; i++) {
//                    ez[i][j] = ga[i][j] * dz[i][j];
                    ez[JE*i + j] = ga[JE*i + j] * dz[JE*i + j];
                    // exy[JE*i + j] = ga[i][j] * dz[i][j];
                } // end of i for
            } // end of j for

              // Calculate the Hx field
            for (j = 0; j < JE - 1; j++) {
                for (i = 0; i < IE - 1; i++) {
//                    hx[i][j] += 0.5*(ez[i][j] - ez[i][j + 1]);
                    hx[JE*i + j] += 0.5*(ez[JE*i + j] - ez[JE*i + j+1]);
                   // hx[i][j] += 0.5*( exy[JE*i + j] -  exy[JE*i + j+1]);

                } // end of i for
            } // end of j for

              // Calculate the Hy field
            for (j = 0; j < JE - 1; j++) {
                for (i = 0; i < IE - 1; i++) {
//                    hy[i][j] += 0.5*(ez[i + 1][j] - ez[i][j]);
                    hy[JE*i + j] += 0.5*(ez[JE*(i+1) + j] - ez[JE*i + j]);
                    //hy[i][j] += 0.5*( exy[JE*(i+1) + j] -  exy[JE*i + j]);
                } // end of i for
            } // end of j for


              // Outputs the progress of the calculation on screen
              // Typecast to (int) for an output without digits
            //std::cerr << "Progress = " << (int)(100 * T / NSTEPS) << "% \r";


           releasePlot(ez, onel,JE) ;
        } // end of FDTD for loop


   } // end of else

//testFunc(512);

}
void MainWin::testFunc(int size)
{

     int sizePlot = size;
     colorMap->data()->setSize(sizePlot, sizePlot); // we want the color map to have nx * ny data points
     //int x1, y1;
     //double x, y;

   // colorMap->data()->setSize(size, size); // we want the color map to have nx * ny data points



//    for (int X3=0; X3<size; X3++)//Пробегаем по всем точкам
//    {
//      // x1 = (X3 + a)/64.0;
//       for (int Y3=0; Y3<size; Y3++)//Пробегаем по всем точкам
//       {
//           colorMap->data()->setCell(X3, Y3, x[size*X3 + Y3]);

//       }
//    }

   ui->widget->replot();

//    QString str;

//    str.setNum(size);

//    ui->lineEdit->setText(str);

}

void MainWin::on_pushButton_2_clicked()
{

    // считываем значения с LineEdit

    radius = ui->lineEdit_Radius->text().toFloat();
    sigma = ui->lineEdit_Sigma->text().toFloat();
    epsilon = ui->lineEdit_Epsilon->text().toFloat();
    height = ui->lineEdit_Height->text().toFloat();
    m_dx=ui->lineEdit_Step->text().toDouble();
    m_frequency = ui->lineEdit_Frequency->text().toFloat();

    m_heightRec = ui->lineEdit_HeightRec->text().toInt();
    m_widthRec = ui->lineEdit_WidthRec->text().toInt();

    worker->setParam(sigma,//sig
                     epsilon,//eps
                     radius,
                     height,
                     m_heightRec,
                     m_widthRec,
                     m_dx,
                     m_frequency);//rad




    //thread->quit();

    thread->start();
   // thread->c
}


void MainWin::on_pushButton_Settings_clicked()
{
    worker->reset();
}
