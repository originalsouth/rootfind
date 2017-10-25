#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits>

using namespace std;
const double pi=acos(-1.0);

double f(double x)
{
    return (x-pi)*(x-1e1*pi)*(x+1e1*pi);
}

double bisect_f(double a,double b)
{
    if(f(a)*f(b)<=0.0)
    {
        double x=0.5*(a+b);
        while(fabs(f(x))>=numeric_limits<double>::epsilon())
        {
            if(f(a)*f(x)>0.0) a=x;
            else b=x;
            x=0.5*(a+b);
        }
        return x;
    }
    else return a+b;
}

int main()
{
    printf("%.17g\n",pi);
    printf("%.17g\n",bisect_f(3.0,4.0));
    return EXIT_SUCCESS;
}
