#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
int str_chr (char *s, char c)
{
    int i;
    for (i=0; i < N; i++)
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
