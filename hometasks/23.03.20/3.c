#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 /* количество элементов массива */

int main()
{
    int a[N]; /* массив a размера N */
    int i, j;    /* счетчик */
    srand(time(NULL)); /* начальное значение генератора ПСЧ */
    for(i = 0; i < N; i++)
    {
        a[i] = rand()%10;
        printf("%d ", a[i]);
    }
    printf("\n");
    int x;
    for(i=0; i<N-1; ++i)
    {
        for(j=i+1; j<N; ++j)
        {
            if (a[i] < a[j])
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    int max=1;
    for(i = 1; i < N; i++)
    {
        if (a[i] == a[i-1])
            max++;
        else
            max=1;
    }
    printf("\n%d", max);
    return 0;
}
