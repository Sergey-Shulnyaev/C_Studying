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

char *double_string(char *st)
{
    int i, len=string_length(st);
    static char ans[2*len];
    for (i=0; i < len; i++)
    {
        ans[i] = st[i];
        ans[i+len] = st[i];
    }
    return ans;
}

int main()
{
    char st[N] = "abc";
    printf("Answer: %s", double_string(st));
    return 0;
}
