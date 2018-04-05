#include "bodycls.h"
#include <omp.h>
#include <math.h>
#include "funcplot.h"
# include <stdlib.h>
# include <stdio.h>

#include "physconst.h"




//double funcplot(int Y3, int X3, double i1, double a);

BodyCls::BodyCls()//(QObject *parent) : QObject(parent)
{

}

BodyCls::~ BodyCls ()
{
//    if (rb != NULL) {
//        delete rb;
//    }
}

void BodyCls::createMassiveFields()
{

//    ex = new  double **[nx];
//    ey = new  double **[nx];
//    ez = new  double **[nx];

//    hx = new  double **[nx];
//    hy = new  double **[nx];
//    hz = new  double **[nx];

//    for (int j=0;j<nx;j++)

//    {
//        ex[j] =new double *[ny];
//        hx[j] =new double *[ny];
//        for (int k=0;k<nx;k++)

//        {
//            ex[j][k] =new double[nz];
//            hx[j][k] =new double[nz];
//        }
//    }


//    for (int j=0;j<nx;j++)

//    {
//        ey[j] =new double *[ny];
//        hy[j] =new double *[ny];
//        for (int k=0;k<nx;k++)

//        {
//            ey[j][k] =new double[nz];
//            hy[j][k] =new double[nz];
//        }
//    }

//    for (int j=0;j<nx;j++)

//    {
//        ez[j] =new double *[ny];
//        hz[j] =new double *[ny];

//        for (int k=0;k<nx;k++)

//        {
//            ez[j][k] =new double[nz];
//            hz[j][k] =new double[nz];
//        }
//    }

}


void BodyCls::process()
{


    isWork = true;
    double a = -4; //Начало интервала, где рисуем график по оси Ox

    double b =  4; //Конец интервала, где рисуем график по оси Ox

    //double h = 0.01; //Шаг, с которым будем пробегать по

   // int N=(b-a)/h + 2; //Вычисляем количество точек, которые будем


    double i1=0;
    a*=64;
    b*=64;
   // int sizePlot = 512;//2*b;
//    CoordZWork = new double *[sizePlot];
//    materialCoord = new double *[sizePlot];

//    for (int i=0;i<sizePlot;i++)
//    {
//      CoordZWork[i] =new double[sizePlot];
//      materialCoord[i] =new double[sizePlot];
//    }

////electrodCoord(sizePlot);
//    double *x;
//    double *y;

////    x=new double [sizePlot];
////    y=new double [sizePlot];

//    const int DATA_SIZE = 1536;
////    double *pInputVector1;
////    double *pInputVector2;



//    x = new double[DATA_SIZE];
//    y = new double[DATA_SIZE];
//  //QVector<double> qx(DATA_SIZE), qy(DATA_SIZE); //Массивы координат точек
//#pragma omp parallel for //private(*x,*y)
//    for (int X3=0; X3<DATA_SIZE; X3++)//Пробегаем по всем точкам
//    {

//        x[X3]= X3/double(3*DATA_SIZE);
//        y[X3] = -60*x[X3]* x[X3] ;

//}

//emit rePlot(x,y,DATA_SIZE);//materialCoord, sizePlot, b);

//FDTD();
    fdtdPML();
emit finished();

//   double * nxy = new double [sizePlot*sizePlot];
//   double * onel=  new double [1];

//    while(true)
//    {
//  #pragma omp parallel for// private(nxy)


//    for (int X3=0; X3<sizePlot; X3++)//Пробегаем по всем точкам
//    {

//        for (int Y3=0; Y3<sizePlot; Y3++)//Пробегаем по всем точкам
//        {
//                   // x1 = (X3 + a)/64.0;
//                    //y1 = (Y3+ a)/64.0;
//                    // double r = 25.0*qSqrt(x1*x1+y1*y1);//+1e-0;//qSqrt(x*x+y*y)
//                               //  double r = 5*qSqrt(xIndex*xIndex+yIndex*yIndex);//qSqrt(x*x+y*y)
//                    //z =  (qCos(r+2-i1)/r-qSin(r+2-i1)/r)/ 5.0;
//                  nxy[sizePlot*X3 + Y3] = funcplot(Y3,X3, i1, a);// nxy[sizePlot*X3 + Y3] =  z;
//                    //CoordZWork[X3][Y3] = z;
//                    //colorMap->data()->setData(x1,y1,z);
//          //  funcplot(0,0,0,0);

//        }

//     }

//  //  emit rePlot(CoordZWork, sizePlot, b);
//    emit rePlot(nxy, onel,sizePlot) ;
//     i1+=0.1;
//     if (i1 >= 6.28318530718) i1 = 0;
//   //Sleep(300);
//  }
}

int funcElectrod(int x)
{
    float a = -0.5;
    float b = 256.0;
    float c = 128.0;
    return a*x*x+b*x+c;
}

void parabola(int sizePlot)
{
//    QVector<double> x(sizePlot), y(sizePlot); //Массивы координат точек

//     #pragma omp parallel for
//      for (int X3=0; X3<sizePlot; X3++)//Пробегаем по всем точкам
//      {

//          x[X3] = X3/64.0 -1;
//          //if (CoordZ1344[X3][Y3] != 0) y=
//          y[X3] = - x[X3]*x[X3];
//          materialCoord[int(x[X3])][int(y[X3])] = 5.0;
//      }

}

void BodyCls::electrodCoord(int sizePlot)
{
////float i0 = sizePlot/2.0;
//  //  int tempI = sizePlot*sizePlot;
////    for (int i=0;i<sizePlot;i++)
////    {
////        //for (int j=0;j<sizePlot;j++)
////       // {
////       // if ( i < tempI)
////        float s = sqrt(i*10.0);

//////        if (i<=i0)
//////         materialCoord[int(i0-s)][i+i0] = 5.0;
//////        else
////        //materialCoord[i][funcElectrod(i)] = 5.0;
////        materialCoord[int(i0-s)][int(i+i0)] = 5.0;
////        materialCoord[int(i0+s)][int(i+i0)] = 5.0;
////            //funcElectrod(i/64 - 1)] = 5.0;//
////        //else break;
////       // }

////    }
//     //parabola(sizePlot);
//    QVector<double> x(sizePlot), y(sizePlot); //Массивы координат точек

//     #pragma omp parallel for
//      for (int X3=0; X3<sizePlot; X3++)//Пробегаем по всем точкам
//      {

//          x[X3] = X3/64.0 -1;
//          //if (CoordZ1344[X3][Y3] != 0) y=
//          y[X3] = - x[X3]*x[X3];
//        //  materialCoord[int(x[X3])][int(y[X3])] = 5.0;
//      }


//   // materialCoord[i0][i0] = 5.0;
}

double  BodyCls::funcplot( int Y3, int X3, double i1, double a)
{
    //double z;
    double x1,y1;
    x1 = (X3 + a)/64.0;
    y1 = (Y3+ a)/64.0;
     double r = 25.0*sqrt(x1*x1+y1*y1);//+1e-0;//qSqrt(x*x+y*y)
               //  double r = 5*qSqrt(xIndex*xIndex+yIndex*yIndex);//qSqrt(x*x+y*y)


    return (cos(r+2-i1)/r-sin(r+2-i1)/r)/ 5.0;

}
void BodyCls::FDTD()
{


 double * onel = new double [1];

    const int    IE = 384;        // Number of cells in x
       const int JE = 384;//384;        // Number of cells in y
      const int  ic = IE / 2;      // Middle of the grid in x
      const int  jc = JE / 2;      // Middle of the grid in y
                          //    const double dx = 0.01,      // Cell size [m]
                          //                 dt = dx/(2*co); // Time step [s]
    double       T = 0.0;        // Time
    const   int    NSTEPS = 5000;   // Number of time steps

    const double t0 = 10.0,      // Center of the incident pulse
        spread = 3.0;   // Width of the incident pulse


    double * dz = new double [IE*JE];
     double * ez = new double [IE*JE];
      double * hx = new double [IE*JE];
       double * hy = new double [IE*JE];
        double * ga = new double [IE*JE];



        // with PML
        float *gi1 = new float[IE];
        float *gi2 = new float[IE];
        float *gi3 = new float[IE];

        float *gj1 = new float[IE];
        float *gj2 = new float[IE];
        float *gj3 = new float[IE];

        float *fi1 = new float[IE];
        float *fi2 = new float[IE];
        float *fi3 = new float[IE];

        float *fj1 = new float[IE];
        float *fj2 = new float[IE];
        float *fj3 = new float[IE];

        int l,m,nsteps,npml;
        float xn,xxn,xnum,xd,curl_e;

    int  n = 0, i = 0, j = 0;    // Loops iterators

     int ia,ib,ja,jb;
    ia = 10;                   /* Total/scattered field boundaries */
    ib = IE-ia-1;
    ja = 10;
    jb = JE-ja-1;


    /* Calculate the PML parameters */

       for (i=0;i< IE; i++) {
      gi1[i] = 0.0;
      gi2[i] = 1.0;
      gi3[i] = 1.0;
      fi1[i] = 0.0;
      fi2[i] = 1.0;
      fi3[i] = 1.0;
       }
       for (j=0;j< IE; j++) {
      gj1[j] = 0.0;
      gj2[j] = 1.0;
      gj3[j] = 1.0;
      fj1[j] = 0.0;
      fj2[j] = 1.0;
      fj3[j] = 1.0;
       }

       npml = 9;


       for (i=0;i<= npml; i++) {
       xnum  = npml - i;
       xd  = npml;
       xxn = xnum/xd;
       xn  = 0.25*pow(xxn,3.0);

          gi1[i] = xn;
          gi1[IE-1-i] = xn;
          gi2[i] = 1.0/(1.0+xn);
          gi2[IE-1-i] = 1.0/(1.0+xn);
          gi3[i] = (1.0 - xn)/(1.0 + xn);
          gi3[IE-i-1] = (1.0 - xn)/(1.0 + xn);
       xxn = (xnum-.5)/xd;
       xn  = 0.25*pow(xxn,3.0);
          fi1[i] = xn;
          fi1[IE-2-i] = xn;
          fi2[i] = 1.0/(1.0+xn);
          fi2[IE-2-i] = 1.0/(1.0+xn);
          fi3[i] = (1.0 - xn)/(1.0 + xn);
          fi3[IE-2-i] = (1.0 - xn)/(1.0 + xn);
       }

       for (j=0;j<= npml; j++) {
       xnum  = npml - j;
       xd  = npml;
       xxn = xnum/xd;
       xn  = 0.25*pow(xxn,3.0);

          gj1[j] = xn;
          gj1[JE-1-j] = xn;
          gj2[j] = 1.0/(1.0+xn);
          gj2[JE-1-j] = 1.0/(1.0+xn);
          gj3[j] = (1.0 - xn)/(1.0 + xn);
          gj3[JE-j-1] = (1.0 - xn)/(1.0 + xn);
       xxn = (xnum-.5)/xd;
       xn  = 0.25*pow(xxn,3.0);
          fj1[j] = xn;
          fj1[JE-2-j] = xn;
          fj2[j] = 1.0/(1.0+xn);
          fj2[JE-2-j] = 1.0/(1.0+xn);
          fj3[j] = (1.0 - xn)/(1.0 + xn);
          fj3[JE-2-j] = (1.0 - xn)/(1.0 + xn);
       }





//    // Initialize the E field and all cells to free space
    #pragma omp parallel for
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
     // for (n = 1; n <= NSTEPS; n++)
        while(isWork)
        {
            T += 1.0;   // T keeps track of the number of times FDTD loop
                        // is executed.

            #pragma omp parallel for
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
           // dz[JE*(ic-100) + jc] = exp(-0.5*pow((t0 - T) / spread, 2.0));
            #pragma omp parallel for
            for (int k1=0; k1<JE;k1++)
            {

                dz[JE*(jc) + k1] = exp(-0.5*pow((t0 - T) / (spread*2.0), 2.0));
                //dz[JE*(jc) + k1] =sin( exp(-0.5*pow((t0 - T) / (spread*2.0), 2.0))); //sin(0.5 *(t0 - T) / spread);//-0.5*pow((t0 - T) / spread, 2.0));

            }
            // Calculate the Ez field
            #pragma omp parallel for
            for (j = 1; j < JE; j++) {
                for (i = 1; i < IE; i++) {
//                    ez[i][j] = ga[i][j] * dz[i][j];
                    ez[JE*i + j] = ga[JE*i + j] * dz[JE*i + j];
                    // exy[JE*i + j] = ga[i][j] * dz[i][j];
                } // end of i for
            } // end of j for

              // Calculate the Hx field
            #pragma omp parallel for
            for (j = 0; j < JE - 1; j++) {
                for (i = 0; i < IE - 1; i++) {
//                    hx[i][j] += 0.5*(ez[i][j] - ez[i][j + 1]);
                    hx[JE*i + j] += 0.5*(ez[JE*i + j] - ez[JE*i + j+1]);
                   // hx[i][j] += 0.5*( exy[JE*i + j] -  exy[JE*i + j+1]);

                } // end of i for
            } // end of j for

              // Calculate the Hy field
            #pragma omp parallel for
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

           //onel = (double*)&n;
            onel[0] = T;
           //emit rePlot(ez, onel,JE) ;//onel
            switch (fieldChouse) {
            case 0:
                emit rePlot(ez, onel,JE) ;
                break;
            case 1:
                emit rePlot(hy, onel,JE) ;
                break;
            case 2:
                emit rePlot(hx, onel,JE) ;
                break;
            default:
                break;
            }

           // emit rePlotHx(hx, onel,JE) ;
            //emit rePlotHy(hy, onel,JE) ;
        } // end of FDTD for loop
    } // end of else


//	  // Writing fields to file
//	fp.open("Out.dat", std::ios::out);
//	fp.precision(6);

//	for (i = 1; i < IE; i++) {
//		for (j = 1; j < JE; j++) {       // Typecast to (float) to avoid
//			fp << (float)i << "\t" // writing numbers with large
//				<< (float)j << "\t" // exponents in the file
//				<< (float)ez[i][j] << std::endl;
//		} // end of i for
//	} // end of j for

//	fp.close();


}
void BodyCls::reset()
{
    isWork = false;
}
\

void BodyCls::fdtdPML()
{
double * onel = new double [1];
    const int    IE = 256;        // Number of cells in x
      const int JE = 256;//384;        // Number of cells in y
       const int NFREQS =3;
     // const int  ic = IE / 2;      // Middle of the grid in x
     // const int  jc = JE / 2;      // Middle of the grid in y


double * Ja = new double [IE*JE];
    double * dz = new double [IE*JE];
     double * ez = new double [IE*JE];
      double * hx = new double [IE*JE];
       double * hy = new double [IE*JE];
        double * ga = new double [IE*JE];
         double * gb = new double [IE*JE];
          double * iz = new double [IE*JE];
          double * ihx = new double [IE*JE];
          double * ihy = new double [IE*JE];


    const double e1 = 1.6E-19,
            h = 6.62E34,
            fia = 4.36*e1,
            m1= 9.1E-31;

        int l,m,n,i,j,ic,jc,nsteps,npml;
        float dt,T,epsz,pi;//ddx
        float xn,xxn,xnum,xd,curl_e;
        float t0,spread,pulse;
        float gi1[IE],gi2[IE],gi3[IE];
        float gj1[JE],gj2[JE],gj3[IE];
        float fi1[IE],fi2[IE],fi3[JE];
        float fj1[JE],fj2[JE],fj3[JE];
        //float ihx[IE][JE],ihy[IE][JE];
       // FILE *fp;
    //     *fopen();
        float ez_inc[JE],hx_inc[JE];
        float ez_inc_low_m1,ez_inc_low_m2;
        float ez_inc_high_m1,ez_inc_high_m2;
        int ia,ib,ja,jb;
        float xdist,ydist,dist;
        float arg[NFREQS];//float freq[NFREQS]
        float
        real_pt[NFREQS][IE][JE],imag_pt[NFREQS][IE][JE],amp[IE][JE],phase[IE][JE];
        float real_in[5],imag_in[5],amp_in[5],phase_in[5];


        ia = 10;                   /* Total/scattered field boundaries */
        ib = IE-ia-1;
        ja = 10;
        jb = JE-ja-1;
       // ddx = 0.0000003;                 /* Cell size */
        dt =ddx/6e8;               /* Time step */
        epsz = 8.8e-12;
        pi=3.14159;

        ic = IE / 2;
        jc = JE / 2;

//        radius = 80;
//        epsilon = 10;//1.5;//34.5;
//        sigma = 0.02;//10000000;//59500000;

#pragma omp parallel for
for (j = 0; j < JE; j++)
{
    ez_inc[j] = 0.;
    hx_inc[j] = 0.;
    for (i = 0; i < IE; i++)
    {

        dz[JE*i + j] = 0.0;
        ez[JE*i + j] = 0.0;
        hx[JE*i + j] = 0.0;
        hy[JE*i + j] = 0.0;
        ga[JE*i + j] = 1.0;
        gb[JE*i + j] = 0.0;

        iz[JE*i + j]= 0.0  ;
        ihx[JE*i + j]= 0.0  ;
        ihy[JE*i + j]= 0.0  ;

    }
}



        /* Parameters for the Fourier Transforms */

//        freq[0] = 1000.e8; //50.e6;
//        freq[1] = 30.e9; //300.e6;
//        freq[2] = 30.5e9;//700.e6;

       for ( n=0; n < NFREQS; n++)
       {
           arg[n] = 2*pi*freq[n]*dt;
       //printf( "%d %6.2f %7.5f \n",n,freq[n]*1e-6,arg[n]);
       }


           for ( j = ja; j < jb; j++ ) {

              for ( i=ia; i < ib; i++ ) {
              xdist = abs(ic-i);
              ydist = abs(jc-j);

              if ((ydist <=radius-(i/height) && ydist >= 0) || (i>=ia-1 && i < ia + widthRec && j<jc + heightRec/2 && j>jc - heightRec/2))
              {

                  ga[JE*(IE  - i) + j] = 1./(epsilon + (sigma*dt/epsz));
                  gb[JE*(IE - i) + j] = sigma*dt/epsz;

              }

               }

            }


        /* Calculate the PML parameters */

           for (i=0;i< IE; i++) {
          gi1[i] = 0.0;
          gi2[i] = 1.0;
          gi3[i] = 1.0;
          fi1[i] = 0.0;
          fi2[i] = 1.0;
          fi3[i] = 1.0;
           }
           for (j=0;j< IE; j++) {
          gj1[j] = 0.0;
          gj2[j] = 1.0;
          gj3[j] = 1.0;
          fj1[j] = 0.0;
          fj2[j] = 1.0;
          fj3[j] = 1.0;
           }

           npml = 20;
          // printf( "Number of PML cells --> ");
          // scanf("%d", &npml);

           for (i=0;i<= npml; i++) {
           xnum  = npml - i;
           xd  = npml;
           xxn = xnum/xd;
           xn  = 0.25*pow(xxn,3.0);
           printf(" %d %7.4f  %7.4f \n",i,xxn,xn);
              gi1[i] = xn;
              gi1[IE-1-i] = xn;
              gi2[i] = 1.0/(1.0+xn);
              gi2[IE-1-i] = 1.0/(1.0+xn);
              gi3[i] = (1.0 - xn)/(1.0 + xn);
              gi3[IE-i-1] = (1.0 - xn)/(1.0 + xn);
           xxn = (xnum-.5)/xd;
           xn  = 0.25*pow(xxn,3.0);
              fi1[i] = xn;
              fi1[IE-2-i] = xn;
              fi2[i] = 1.0/(1.0+xn);
              fi2[IE-2-i] = 1.0/(1.0+xn);
              fi3[i] = (1.0 - xn)/(1.0 + xn);
              fi3[IE-2-i] = (1.0 - xn)/(1.0 + xn);
           }

           for (j=0;j<= npml; j++) {
           xnum  = npml - j;
           xd  = npml;
           xxn = xnum/xd;
           xn  = 0.25*pow(xxn,3.0);
           //printf(" %d %7.4f  %7.4f \n",i,xxn,xn);
              gj1[j] = xn;
              gj1[JE-1-j] = xn;
              gj2[j] = 1.0/(1.0+xn);
              gj2[JE-1-j] = 1.0/(1.0+xn);
              gj3[j] = (1.0 - xn)/(1.0 + xn);
              gj3[JE-j-1] = (1.0 - xn)/(1.0 + xn);
           xxn = (xnum-.5)/xd;
           xn  = 0.25*pow(xxn,3.0);
              fj1[j] = xn;
              fj1[JE-2-j] = xn;
              fj2[j] = 1.0/(1.0+xn);
              fj2[JE-2-j] = 1.0/(1.0+xn);
              fj3[j] = (1.0 - xn)/(1.0 + xn);
              fj3[JE-2-j] = (1.0 - xn)/(1.0 + xn);
           }

          // printf("gi + fi \n");
//           for (i=0; i< IE; i++) {
//               printf( "%2d  %5.2f  %5.2f  %5.2f \n",
//                    i,gi1[i],gi2[i],gi3[i]),
//               printf( "     %5.2f  %5.2f  %5.2f \n ",
//                   fi1[i],fi2[i],fi3[i]);
//           }

//           printf("gj + fj \n");
//           for (j=0; j< JE; j++) {
//               printf( "%2d  %5.2f  %5.2f  %5.2f \n",
//                        j,gj1[j],gj2[j],gj3[j]),
//               printf( "     %5.2f  %5.2f  %5.2f \n ",
//                   fj1[j],fj2[j],fj3[j]);
//           }

        t0 = 25.0;
        spread = 8.0;
        T = 0;
     //   nsteps = 1;

    //while ( nsteps > 0 )
        while(isWork)
        {
//           printf( "nsteps --> ");
//           scanf("%d", &nsteps);
//           printf("%d \n", nsteps);

        //for ( n=1; n <=nsteps ; n++)  {
           T = T + 1;

    /*  ----   Start of the Main FDTD loop ----  */

          /* Calculate the incidnet Ez  */
          for (j=1; j< JE; j++) {
             ez_inc[j] = ez_inc[j] + .5*(hx_inc[j-1]-hx_inc[j]);
          }

        /* Fourier Tramsform of the incident field */
            for ( m=0; m < NFREQS ; m++ )
            {  real_in[m] = real_in[m] + cos(arg[m]*T)*ez_inc[ja-1] ;
           imag_in[m] = imag_in[m] - sin(arg[m]*T)*ez_inc[ja-1] ;
        }

          /* ABC for the incident buffer */
          ez_inc[0]      = ez_inc_low_m2;
          ez_inc_low_m2  = ez_inc_low_m1;
          ez_inc_low_m1  = ez_inc[1];

          ez_inc[JE-1]    = ez_inc_high_m2;
          ez_inc_high_m2  = ez_inc_high_m1;
          ez_inc_high_m1  = ez_inc[JE-2];

           /* Calculate the Dz field */
           for ( j=1; j < IE; j++ ) {
              for ( i=1; i < IE; i++ ) {
                  dz[JE*i + j] = gi3[i]*gj3[j]*dz[JE*i + j]
             + gi2[i]*gj2[j]*.5*( hy[JE*i + j] - hy[JE*(i-1) + j]
                        - hx[JE*i + j] + hx[JE*i + j-1]) ;
              }
           }

           /*  Source */

           /* pulse =  sin(2*pi*400*1e6*dt*T) ; */
           pulse =sin(2*pi*freq[1]*dt*T) ;//exp( -0.5*pow((t0-T)/spread,2.0));// sin((t0-T)/200.0) ;//exp( -0.5*pow((t0-T)/spread,2.0)); // exp(-.5*(pow((t0-T)/spread,2.0) ));
             ez_inc[3] = pulse;
      /*     dz[ic-5][jc-5] = pulse; */

          // printf("%3.0f  %6.2f \n ",T,ez_inc[3]);
           /* Incident Dz values */

           for (i=ia; i<= ib; i++ )  {
              dz[JE*i + ja] = dz[JE*i + ja] + 0.5*hx_inc[ja-1];
              dz[JE*i + jb] = dz[JE*i + jb] - 0.5*hx_inc[jb];
           }

           /* Calculate the Ez field */
           for ( j=1; j < JE-1; j++ ) {
              for ( i=1; i < IE-1; i++ ) {
                  ez[JE*i + j] = ga[JE*i + j]*( dz[JE*i + j] - iz[JE*i + j] ) ;
              iz[JE*i + j] = iz[JE*i + j] + gb[JE*i + j]*ez[JE*i + j] ;
              }
           }

              /* Calculate the Fourier transform of Ex. */
         for ( j=0; j < JE; j++ )
         {   for ( i=0; i < JE; i++ )
            {   for ( m=0; m < NFREQS; m++ )
               { real_pt[m][i][j] = real_pt[m][i][j] + cos(arg[m]*T)*ez[JE*i + j] ;
                 imag_pt[m][i][j] = imag_pt[m][i][j] + sin(arg[m]*T)*ez[JE*i + j] ;
               }
            }
         }

          /* Calculate the incident Hx */
          for (j=0; j< JE; j++) {
             hx_inc[j] = hx_inc[j] + .5*(ez_inc[j]-ez_inc[j+1]);
          }

           /* Calculate the Hx field */
           for ( j=0; j < JE-1; j++ ) {
              for ( i=0; i < IE; i++ ) {
             curl_e =   ez[JE*i + j] - ez[JE*i + j+1]  ;
             ihx[JE*i + j] = ihx[JE*i + j]  + fi1[i]*curl_e ;
             hx[JE*i + j] = fj3[j]*hx[JE*i + j]
                  + fj2[j]*.5*(curl_e + ihx[JE*i + j]);
              }
           }

           /* Incident Hx values */

           for (i=ia; i<= ib; i++ )  {
              hx[JE*i + ja-1] = hx[JE*i + ja-1] + 0.5*ez_inc[ja];
              hx[JE*i + jb]   = hx[JE*i + jb] - 0.5*ez_inc[jb];
           }

           /* Calculate the Hy field */
           for ( j=0; j <= JE-1; j++ ) {
              for ( i=0; i < IE-1; i++ ) {
             curl_e  = ez[JE*(i+1) + j] - ez[JE*i + j];
             ihy[JE*i + j] = ihy[JE*i + j]  + fj1[j]*curl_e ;
             hy[JE*i + j] = fi3[i]*hy[JE*i + j]
                  + fi2[i]*.5*(curl_e + ihy[JE*i + j]);
              }
           }

           /* Incident Hy values */
           for (j=ja; j<= jb; j++ )  {
              hy[JE*(ia-1) + j] = hy[JE*(ia-1) + j] - 0.5*ez_inc[j];
              hy[JE*ib + j]   = hy[JE*ib + j]   + 0.5*ez_inc[j];
           }





           // вычисление плотности тока
           for ( j = ja; j < jb; j++ )
           {

              for ( i=ia; i < ib; i++ )
              {

                  xdist = abs(ic-i);
                  ydist = abs(jc-j);

                  if ((ydist <=(radius+1)-(i/(height)) && ydist >= 0) || (i>=ia-1 && i < ia + (widthRec+4) && j<jc + (heightRec+4)/2 && j>jc - (heightRec+4)/2))

                  {

                //  ga[JE*(IE  - i) + j] = 1./(epsilon + (sigma*dt/epsz));
                 // gb[JE*(IE - i) + j] = sigma*dt/epsz;

                      Ja[JE*(IE - i) + j] = pow(e1,3)*pow(ez[JE*(IE - i) + j],2)*exp(-8*pi*pow(2*m1,0.5)*pow(fia,3/2.0)*0.75/(3*e1*h*ez[JE*(IE - i) + j]))/(8*pi*h*fia)*1E75;

                 }


              }

            }

           ga[0] = Ja[JE*IE/2 + JE/2 ];//Ja[JE*IE/2 + JE/2 ];//T*dt*1e9;



           switch (fieldChouse) {
           case 0:
               emit rePlot(ez, ga,JE) ;
               break;
           case 1:
               emit rePlot(hy, ga,JE) ;
               break;
           case 2:
               emit rePlot(hx, ga,JE) ;
               break;
           case 3:
               emit rePlot(Ja, ga,JE) ;
               break;
           default:
               break;
           }

            //emit rePlot(ez, ga,JE) ;
          // emit rePlotHy(hy, ga,JE) ;
          // emit rePlotHx(hx, ga,JE) ;
       // }
    /*  ----  End of the main FDTD loop ---- */

      /* Calculate the Fouier amplitude and phase of the incident pulse */
//           for ( m=0; m < NFREQS; m++ )
//           {    amp_in[m]   = sqrt( pow(real_in[m],2.) + pow(imag_in[m],2.));
//                phase_in[m] = atan2(imag_in[m],real_in[m]) ;
//            // printf( "%d  Input Pulse :  %8.4f %8.4f %8.4f  %7.2f\n",
//            // m,real_in[m],imag_in[m],amp_in[m],(180.0/pi)*phase_in[m]);
//           }

       /* Calculate the Fouier amplitude and phase of the total field field */
//           for ( m=0; m < NFREQS; m++ )
//           {
//           if( m == 0)       fp = fopen( "amp1","w");
//           else if( m == 1)  fp = fopen( "amp2","w");
//           else if( m == 2)  fp = fopen( "amp3","w");
//           {   printf( "%2d  %7.2f  MHz\n",m,freq[m]*1.e-6);
//               for ( j=ja; j <= jb; j++ )
//               {  if( ga[ic][j] < 1.00 )
//                  {  amp[ic][j]  = (1./amp_in[m])
//                     *sqrt( pow(real_pt[m][ic][j],2.) + pow(imag_pt[m][ic][j],2.));
//                     printf( "%2d %9.4f \n",jc-j,amp[ic][j]);
//                     fprintf( fp," %9.4f \n",amp[ic][j]);
//                   }
//               }
//            }
//            fclose(fp);
//        }

         /*  for ( j=1; j < JE; j++ ) {
              printf( "%2d  %5.2f",j,ez_inc[j]);
              for ( i=1; i <= IE; i++ ) {
                 printf( "%5.2f",ez[i][j]);
          }
                 printf( " \n");
           } */

            /* Write the E field out to a file "Ez" */
//           fp = fopen( "Ez","w");
//           for ( j=0; j < jc; j++ ) {
//           for ( i=0; i < ic; i++ ) {
//                 fprintf( fp,"%6.3f ",ez[2*i][2*j]);
//          }
//                 fprintf( fp," \n");
//            }
//           printf("T = %3.0f  \n ",T);

//            fclose(fp);

    }
}
void BodyCls::setParam(float sig, float eps, float m_radius, float m_height, int m_heightRec, int m_widthRec, double m_dx, float m_freq)
{
    radius = m_radius;
    sigma = sig;
    epsilon = eps;
    height = m_height;
    ddx = m_dx;

    freq[0]= m_freq/10.0;
    freq[1]= m_freq;
    freq[2]= m_freq*10.0;

    heightRec = m_heightRec;
    widthRec = m_widthRec;
    //IE = m_points;
    //JE = IE;


}
void BodyCls::fieldPlotSet(int numField)
{
    fieldChouse = numField;
}
