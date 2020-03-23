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

int str_chr (char *s, char c)
{
    int i, len=string_length(s);
    for (i=0; i < len; i++)
    {
        if(s[i] == c)
         return i;
    }
    return -1;
}

int main()
{
    char st[N] = "abcdec";
    printf("Answer: %d", str_chr(st, 'c'));
    return 0;
}
