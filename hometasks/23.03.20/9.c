#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 /* количество элементов массива */

int main()
{
    float a[N] = {0.};
    float b[N] = {0.};
    int i, j;    /* счетчик */
    srand(time(NULL)); /* начальное значение генератора ПСЧ */
    for(i = 0; i < N; i++)
    {
        a[i] = (float)(rand()%10) / 2;
        printf("%f ", a[i]);
    }
    printf("\n");
    float x;
    for(i=0; i<N-1; ++i)
    {
        for(j=i+1; j<N; ++j)
        {
            if (a[i] > a[j])
            {
                x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }
    for(i = 0; i < N; i++)
    {
        printf("%f ", a[i]);
    }
    printf("\n");
    b[0] = a[0];
    int top=1;
    for(i = 1; i < N; i++)
    {
        if (a[i] != a[i-1])
            {
                b[top] = a[i];
                top += 1;
            }
    }
    for(i = 0; i < top; i++)
    {
        printf("%f ", b[i]);
    }
    return 0;

}
