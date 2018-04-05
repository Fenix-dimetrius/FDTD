#include <math.h>
#include "funcplot.h"
double  funcplot( int Y3, int X3, double i1, double a)
{
    //double z;
    double x1,y1;
    x1 = (X3 + a)/64.0;
    y1 = (Y3+ a)/64.0;
     double r = 25.0*sqrt(x1*x1+y1*y1);//+1e-0;//qSqrt(x*x+y*y)
               //  double r = 5*qSqrt(xIndex*xIndex+yIndex*yIndex);//qSqrt(x*x+y*y)


    return (cos(r+2-i1)/r-sin(r+2-i1)/r)/ 5.0;

}
