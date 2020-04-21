#include <stdio.h>
#include <stdlib.h>
#define N 50



typedef struct arrayNode{
    struct arrayNode *next;
    float value;
} arrayNode;

void display(arrayNode *first)
{
	arrayNode *i = first;
	while(i != NULL){ /* i=(*i).next */
        if (NULL == i->next)
            printf("%f.\n", i->value);
		else
            printf("%f, ", i->value);
		i=i->next;
	}
	printf("\n");
}

arrayNode *dif(arrayNode *fun)
{
    arrayNode *d = malloc(sizeof(arrayNode));
    arrayNode *res = malloc(sizeof(arrayNode));
    res = d;
    if (NULL == d)
    {
        printf("OS didn't gave memory. Exit...\n");
        exit(1);
    }

    arrayNode *i = fun;
    if (NULL == i->next){
        d->next = NULL;
		d->value = 0;
		return d;
    }

    int k =1;
    i = i->next;
	while(i != NULL){ /* i=(*i).next */
        if (NULL == i->next)
            d->next = NULL;
		else
        {
            arrayNode *newEl = malloc(sizeof(arrayNode));
            d->next = newEl;
        }

		d->value = i->value * k;

		d = d->next;
		i=i->next;
		k++;
	}

    return res;
}

void append(arrayNode *first, double num)
{
    arrayNode *i = first;
    while(i->next != NULL)
		i=i->next;

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

float pop(arrayNode *first)
{
    float last;
    arrayNode *i = first;
    arrayNode *iold = first;
    while(i->next != NULL)
    {
        iold = i;
		i=i->next;
    }
    iold->next = NULL;
    last = i->value;
    free(i);
    return last;
}

float power(float a, int b)
{
    int i;
    float res = 1;
    for(i = 0; i < b; i++){
        res *= a;
    }
    return res;
}

float funcValue(arrayNode *fun, float x)
{
    arrayNode *i = fun;
    int k = 0;
    float res = 0;
    float a;
	while(i != NULL){ /* i=(*i).next */
        a = power(x, k) * (i->value);
        res += a;
		i=i->next;
		k++;
	}
	return res;
}

arrayNode *methodOfNewton(arrayNode *fun, float start, float fin, float step)
{
    float s = start, f =fin;
    while (s <= f)
    {
        s += step;
    }
    return fun;
}


int main()
{
    arrayNode *f = malloc(sizeof(arrayNode));
    f->next = NULL;
    f->value = 1;
    append(f, 2);
    append(f, 1);
    display(f);
    printf("%f\n", funcValue(f, 5));
    return 0;
}
