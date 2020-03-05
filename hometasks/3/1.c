#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

int main()
{
    double x1, x2, y1, y2;
    printf("Coordiantes of first point: ");
    scanf("%lf%lf", &x1, &y1);
    printf("Coordiantes of second point: ");
    scanf("%lf%lf", &x2, &y2);
    printf("Result %lf\n", distance(x1, y1, x2, y2));
    return 0;
}
