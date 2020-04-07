#include <stdio.h>
#include <stdlib.h>
#define N 80

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
        exit(1);
    }
    return a;
}

typedef struct arrayNode{
    struct arrayNode *next;
    int value;
} arrayNode;

void display(arrayNode *first)
{
	arrayNode *i = first;
	while(i != NULL){ /* i=(*i).next */
        if (NULL == i->next)
            printf("%d.\n", i->value);
		else
            printf("%d, ", i->value);
		i=i->next;
	}
	printf("\n");
}

void append(arrayNode *first)
{
    int num;
    arrayNode *i = first;
    while(i->next != NULL)
		i=i->next;

    printf("Input value\n");
    scanf("%d", &num);
    arrayNode *last = malloc(sizeof(arrayNode));
    if (NULL == last)
    {
        printf("OS didn't gave memory. Exit...\n");
        exit(1);
    }
    last->next = NULL;
    last->value = num;
    i->next = last;
}

void destroyLast(arrayNode *first)
{
    arrayNode *i = first;
    arrayNode *iold = first;
    while(i->next != NULL)
    {
        iold = i;
		i=i->next;
    }
    iold->next = NULL;
    free(i);
}

void destroyAll(arrayNode *first)
{
    arrayNode *i = first;
    arrayNode *iold = first;
    while(i->next != NULL)
    {
        iold = i;
		i=i->next;
		free(iold);
    }
}
int searchElement(arrayNode *first)
{
    arrayNode *i = first;
    int num = 0, element;
    printf("Input value: ");
    scanf("%d", &element);
    while(i != NULL)
    {
        if(i->value == element)
            return num;
		i=i->next;
        num++;
    }
    return -1;
}

void program(arrayNode *array)
{
    char d[80];
    char str[80];
    int dir;
    while (1)
    {
        printf("1. Generate first element\n2. Append element\n3. Destroy last element\n4. Display\n5. Destroy array\n6. Search element\n7. Exit\n");
        scanf("%s", d);
        dir = fatoi(d);
        if (1 == dir)
        {
            printf("Input value\n");
            scanf("%s", str);
            array->value = fatoi(str);
        }
        if (2 == dir)
            append(array);
        if (3 == dir)
            destroyLast(array);
        if (4 == dir)
            display(array);
        if (5 == dir)
        {
            destroyAll(array);
            break;
        }
        if (6 == dir)
            printf("\n%d\n", searchElement(array));
        if (7 == dir)
            exit(0);
        if (dir < 1 || dir > 7)
            printf("Undefined command\n");
    }
}

int main()
{
    int dir;
    char d[80];
    char str[80];
    while (1)
    {
        printf("1. Generate first element\n2. Append element\n3. Destroy last element\n4. Display\n5. Destroy array\n6. Search element\n7. Exit\n");
        scanf("%s", d);
        dir = fatoi(d);
        if (1 == dir)
        {

            arrayNode *array = malloc(sizeof(arrayNode));
            if (NULL == array)
            {
                printf("OS didn't gave memory. Exit...\n");
                exit(1);
            }
            printf("Input value\n");
            scanf("%s", str);
            array->next = NULL;
            array->value = fatoi(str);
            program(array);

        }
        else
            if (dir < 7)
                printf("Undefined first element");

        if (7 == dir)
            break;

    }

}
