#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10 /* ���������� ��������� ������� */

int main()
{
    int a[N] = {1,2,1,4,5,6,7,8,9,10}; /* ������ a ������� N */
    int i;   /* ������� */
    for(i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    int flag = 1;
    for(i=0; i<N-1; ++i)
    {
        if (a[i] >= a[i+1])
        {
            flag = 0;
            break;
        }
    }
    if (flag == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
