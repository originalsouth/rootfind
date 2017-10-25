#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits>

using namespace std;
const double pi=acos(-1.0);
const double scale=5.0;
double a,b,c;

double f(double x)
{
    return a*pow(x,2)+b*x+c;
}

double F(double x)
{
    return -(b+c/x)/a;
}

double fxdpt(double x)
{
    int counter=0;
    double xp;
    do
    {
        x=F(xp=x);
        printf("%d: xp=%.17g, x=%.17g, F(x)=%.17g, f(x)=%.17g\n",counter,xp,x,F(x),f(x));
        counter++;
    }
    while(fabs(f(x))>numeric_limits<double>::epsilon() and counter<=0xFF);
    return x;
}

int main()
{
    srand48(time(NULL));
    double xpp,xmm;
    do
    {
        a=(2.0*drand48()-1.0)*scale;
        b=(2.0*drand48()-1.0)*scale;
        c=(2.0*drand48()-1.0)*scale;
        xpp=(-b+sqrt(pow(b,2)-4.0*a*c))/(2.0*a);
        xmm=(-b-sqrt(pow(b,2)-4.0*a*c))/(2.0*a);
    }
    while(isnan(xpp) or isnan(xmm));
    printf("a = %.17g, b = %.17g, c = %.17g\n",a,b,c);
    printf("x_+ = %.17g, x_- = %.17g\n",xpp,xmm);
    printf("f(x_+) = %.17g, f(x_-) = %.17g\n",f(xpp),f(xmm));
    const double miss=2.0*drand48();
    printf("x_0 = %.17g\n",miss*xpp);
    const double x=fxdpt(miss*xpp);
    printf("x=%.17g, f(x)=%.17g\n",x,f(x));
    if(fabs(x-xpp)<fabs(x-xmm)) printf("|x-x_+|=%.17g\n",fabs(x-xpp));
    else printf("|x-x_-|=%.17g\n",fabs(x-xmm));
    return EXIT_SUCCESS;
}
