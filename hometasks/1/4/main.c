#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x, y, res;
    scanf("%d%d", &x, &y);
    if (y == 0)
    {
        printf("0");
        return 0;
    }
    res = x;
    int i = 1;
    while (i < y)
    {
        res = res * x;
        ++i;
    }
    printf("%d", res);
    return 0;
}
