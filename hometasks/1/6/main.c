#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, k = 0;
    scanf("%d", &a);
    while(a != 0)
    {
        if (a % 10 == 7)
            ++k;
        a = a / 10;
    }
    printf("%d", k);
    return 0;
}
