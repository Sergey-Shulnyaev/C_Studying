#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 /* количество элементов массива */

int main()
{
    int a[N]; /* массив a размера N */
    int i;    /* счетчик */
    srand(time(NULL)); /* начальное значение генератора ПСЧ */

    int sum = 0;
    for(i = 0; i < N; i++)
    {
        a[i] = rand()%100;
    }
    for (i=0; i<N; i+=2)
    {
        printf("%d", a[i]);
    }
    for (i=1; i<N; i+=2)
    {
        printf("%d", a[i]);
    }

    return 0;
}
