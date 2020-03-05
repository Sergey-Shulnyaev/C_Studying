#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i = 1;
    float sum = 0, k;
    while (i<=5)
    {
            scanf("%f", &k);
            sum += k;
            i++;
    }
    sum = sum / 5;
    printf("%f\n", sum);
    return 0;
}
