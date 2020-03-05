#include <stdio.h>
#include <stdlib.h>

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

int main()
{
    double x, sum=0;
    int y;
    scanf("%lf%d", &x, &y);
    for (int i=0; i < y; ++i)
    {
        sum += power(x, i) / fac(i);
    }
    printf("e^x %lf", sum);
    return 0;
}

