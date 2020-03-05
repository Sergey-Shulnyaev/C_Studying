#include <stdio.h>
#include <stdlib.h>

float min(float a, float b, float c)
{
    float min = a;
    if (min > b)
        min = b;
    if (min > c)
        min = c;
    return min;
}

int main()
{
    float a, b, c;
    printf("Input a,b,c: ");
    scanf("%f%f%f", &a, &b, &c);
    printf("Result: %f\n", min(a, b, c));
    return 0;
}
