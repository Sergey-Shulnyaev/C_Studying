#include <stdio.h>
#include <stdlib.h>

double diameter(double radius)
{
    return 2 * radius;
}

double perimeter(double radius)
{
    return 3.14159 * 2 * radius;
}

double area(double radius)
{
    return radius * radius * 3.14159;
}

int main()
{
    double radius;
    scanf("%lf", &radius);
    printf("diam %lf, perimeter %lf, area %lf", diameter(radius), perimeter(radius), area(radius));
    return 0;
}
