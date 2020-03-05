#include <stdio.h>
#include <stdlib.h>


int main()
{
    int x, min, l;
    scanf("%d", &x);
    if (x < 1)
        return 1;
    else
    {
        scanf("%d", &min);
    }
    for (int i=1; i < x; ++i)
    {
        scanf("%d", &l);
        if (min >= l)
            min = l;
    }
    printf("min %d\n", min);
    return 0;
}

