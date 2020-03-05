#include <stdio.h>
#include <stdlib.h>

int reverse(int a)
{
    int k = a, c=0;
    while (k !=0)
    {
        c = c*10 + k%10;
        k /= 10;
    }
    return c;
}

int main()
{
    int a;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Result: %d\n", reverse(a));
    return 0;
}
