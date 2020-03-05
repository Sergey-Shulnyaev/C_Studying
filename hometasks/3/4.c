#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool primeQ(int a)
{
    for(int div=2; div*div <=a; ++div)
    {
        if (a%div == 0)
            return true;
    }
    return false;
}

int main()
{
    int a;
    printf("Input a: ");
    scanf("%d", &a);
    printf("Result: %d\n", primeQ(a));
    return 0;
}
