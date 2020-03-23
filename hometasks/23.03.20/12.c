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

char *sum_string(char *s1, char *s2)
{
    int i, l1=string_length(s1), l2=string_length(s2);
    static char ans[N];
    for (i=0; i < l1; i++)
    {
        ans[i] = s1[i];
    }
    for (i=0; i < l2; i++)
    {
        ans[i+l1] = s2[i];
    }
    return ans;
}

int main()
{
    char s1[N] = "abc";
    char s2[N] = "ab";
    printf("Answer: %s", sum_string(s1, s2));
    return 0;
}
