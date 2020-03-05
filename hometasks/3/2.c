#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b)
{
    int c, d, k;
    if (a > b)
    {
        c = a;
        d = b;
    }
    else
    {
        c = b;
        d = a;
    }
    while (c%d != 0)
    {
        k = c % d;
        c = d;
        d = k;
        printf("%d %d ", c, d);
    }
    return d;
}

int main()
{
    int a, b;
    printf("Two numbers: ");
    scanf("%d%d", &a, &b);
    printf("Result %d\n", gcd(a, b));
    return 0;
}

