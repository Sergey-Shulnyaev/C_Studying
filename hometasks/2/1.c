#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x, sum = 0, l;
    scanf("%d", &x);
    for (int i=0; i < x; ++i)
    {
        scanf("%d", &l);
        sum += l;
    }
    printf("sum %d\n", sum);
    return 0;
}

