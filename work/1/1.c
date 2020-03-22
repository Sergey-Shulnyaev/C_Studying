#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int fac(int a)
{
    if (a == 1 || a == 0)
        return 1;
    else
        return a * fac(a-1);
}

double power(double x, int y)
{
    double res;
    if (y == 0)
    {
        return 1;
    }
    res = x;
    int i = 1;
    while (i < y)
    {
        res = res * x;
        ++i;
    }
    return res;
}

double ETeylor(double x,int y)
{
    double sum=0;
    for (int i=0; i < y; ++i)
    {
        sum += power(x, i) / fac(i);
    }
    return sum;
}

double fun(double a, double x)
{
    return (a + ETeylor(x, 8)) / (a + ETeylor(x*(-1), 15));
}


int main()
{
    double a, x;
    printf("Input a: ");
    scanf("%lf", &a);
    printf("Input x: ");
    scanf("%lf", &x);
    printf("y = %lf", fun(a, x));
    return 0;
}
