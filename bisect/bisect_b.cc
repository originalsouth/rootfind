#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits>

using namespace std;
const double pi=acos(-1.0);

double f(double x)
{
    return x*x*x-x-2;
}

double bisect_f(double a,double b)
{
    if(f(a)*f(b)<=0.0)
    {
        int counter=0;
        double n=2.0;
        const double d=b-a;
        while(fabs(f(a))>=numeric_limits<double>::epsilon())
        {
            const double h=d/n;
            if(f(a+h)*f(b)<=0.0) a+=h;
            else n*=2.0;
            printf("%d: x=%.17g, h=%.17g, f(x)=%.17g\n",counter,a,h,f(a));
            counter++;
        }
    }
    return a;
}

int main()
{
    printf("%.17g\n",bisect_f(1.0,2.0));
    return EXIT_SUCCESS;
}
