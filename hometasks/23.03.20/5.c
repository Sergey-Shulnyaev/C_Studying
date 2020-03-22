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
    if (nummax < nummin)
    {
        x = nummax;
        nummax = nummin;
        nummin = x;
    }
    int sum = 0;
    for(i = nummin +1; i < nummax; i++)
    {
        sum += a[i];
    }
    printf("Summary = %d", sum);
    return 0;
}
