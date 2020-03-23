#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 50

int string_length(char *st)
{
    int i, len = 0;
    for (i=0; i < N; i++)
        if (st[i] != 0)
            len++;
        else
            break;
    return len;
}

int count_digits(char *st)
{
    int i, num=0, len=string_length(st);
    for (i=0; i < len; i++)
    {
        if(st[i] <= 57 && st[i] >= 48)
        {
            num += 1;
        }
    }
    return num;
}

int main()
{
    char st[N] = "abcd5df2452g";
    printf("Amount of numbers = %d", count_digits(st));
    return 0;
}
