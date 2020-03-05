#include <stdio.h>
#include <stdlib.h>

int fac(int a)
{
    if (a == 1 || a == 0)
    {
        printf("1\n");
        return 1;
    }
    else
    {
        int n = a * fac(a-1);
        printf("%d\n", n);
        return n;
    }
}

int main()
{
    int a;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Result: %d\n", fac(a));
    return 0;
}
