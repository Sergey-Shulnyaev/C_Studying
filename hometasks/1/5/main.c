#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, mas[5];
    scanf("%d", &a);
    if (a < 10000 || a > 99999)
        return 1;
    for(int i=0; i < 5; ++i)
    {
        mas[i] = a % 10;
        a = a / 10;
    }
    if (mas[0] == mas[4] && mas[1] == mas[3])
        printf("Palindrome");
    else
        printf("No");
    return 0;
}
