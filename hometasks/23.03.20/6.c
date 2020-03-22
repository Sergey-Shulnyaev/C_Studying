#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 /* количество элементов массива */

int main()
{
    int a[N]= {1,1,2,3,4,5,6,7,8,9}; /* массив a размера N */
    int i;    /* счетчик */
    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int first = a[0]%2, flag = 0;
    for (i=1; i<N; ++i)
    {
        if (a[i]%2 != (first + i)%2)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
        printf("YES");
    else
        printf("NO");
    return 0;
}
