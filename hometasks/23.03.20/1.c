#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 /* количество элементов массива */

int main()
{
    int a[N]; /* массив a размера N */
    int i;    /* счетчик */
    srand(time(NULL)); /* начальное значение генератора ПСЧ */
    for(i = 0; i < N; i++)
    {
        a[i] = rand()%100;
        printf("%d ", a[i]);
    }
    printf("\n");
    int min=100, nummin, max=0, nummax;
    for (i=0; i<N; ++i)
    {
        if (min > a[i])
        {
            min = a[i];
            nummin = i;
        }
        if (max < a[i])
        {
            max = a[i];
            nummax = i;
        }
    }
    int x;
    x = a[nummin];
    a[nummin] = a[nummax];
    a[nummax] = x;
    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
