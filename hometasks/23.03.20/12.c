#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
#define S 2
char *sum_string(char *s1, char *s2)
{
    int i;
    static char ans[N + S];
    for (i=0; i < N; i++)
    {
        ans[i] = s1[i];
    }
    for (i=0; i < S; i++)
    {
        ans[i+N] = s2[i];
    }
    return ans;
}

int main()
{
    char s1[N] = "abc";
    char s2[S] = "ab";
    printf("Answer: %s", sum_string(s1, s2));
    return 0;
}
