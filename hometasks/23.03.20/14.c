#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
int fotoi(char *s)
{
    int i;
    int a = 0;
    for (i=0; i < N; i++)
    {
        a *= 1000;
        a += (int)s[i];
        printf("%d\n", a);
    }
    return a;
}

int main()
{
    char st[N] = "abc";
    printf("Answer: %d", fotoi(st));
    return 0;
}
