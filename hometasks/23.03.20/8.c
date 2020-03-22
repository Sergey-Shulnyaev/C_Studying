#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 /* количество элементов массива */

int main()
{
    int a[N] = {1,2,3,4,5,6,7,8,9,10};
    int b[N] = {1,2,3,4,5,6,8,9,10,11};
    int i;    /* счетчик */
    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    for(i = 0; i < N; i++)
    {
        printf("%d ", b[i]);
    }
    printf("\n");
    int num =0;
    for(i = 0; i < N; ++i)
    {
        if (a[i] != b[i])
            num += 1;
    }
    printf("Amount of different numbers = %d", num);
    return 0;

}
