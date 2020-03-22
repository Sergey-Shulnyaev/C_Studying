#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 3
char *double_string(char *st)
{
    int i;
    static char ans[N*2];
    for (i=0; i < N; i++)
    {
        ans[i] = st[i];
        ans[i+N] = st[i];
    }
    return ans;
}

int main()
{
    char st[N] = "abc";
    printf("Answer: %s", double_string(st));
    return 0;
}
