#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1, sum = 0, k;
    while (i<=10)
    {
            scanf("%d", &k);
            sum += k;
            i++;
    }
    printf("%d\n", sum);
    return 0;
}
