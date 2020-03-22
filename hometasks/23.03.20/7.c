#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 /* количество элементов массива */

int main()
{
    int a[N]={1,2,3,4,4,5,4,3,2,1}; /* массив a размера N */
    int i;    /* счетчик */
    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int top = N/2, flag = 0;
    for(i = 0; i <= top; ++i)
    {
        if (a[i] != a[N-i-1])
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
