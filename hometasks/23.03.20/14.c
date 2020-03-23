#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50

const int string_length(char *st)
{
    int i, len = 0;
    for (i=0; i < N; i++)
        if (st[i] != 0)
            len++;
        else
            break;
    return len;
}

int fatoi(char *st)
{
    int i, len=string_length(st);
    int a = 0;
    for (i=0; i < len; i++)
    {
        if(st[i] <= 57 && st[i] >= 48)
        {
            a *= 10;
            a += st[i] - 48;
        }
        else
        return 1;
    }
    return a;
}

int main()
{
    char st[N] = "1234";
    printf("Answer: %d", fatoi(st));
    return 0;
}
