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

    double r;
    printf("Input r plz: ");
    scanf("%lf", &r);
    int num;
    double nd, distance=labs(r - a[0]);
    for(i = 0; i < N; i++)
    {
        nd = labs(r - a[i]);
        if(nd < distance)
        {
            distance = nd;
            num = i;

        }
    }
    printf("%d\n", num);
    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}
