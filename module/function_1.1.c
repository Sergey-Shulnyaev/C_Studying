#include <stdio.h>
#include <stdlib.h>
#define N 50

float fabs(float a)
{
    if (a > 0)
        return a;
    else
        return (-1)*a;
}

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

void append(arrayNode *first, float num)
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
    float s = start, f =fin, value, oldvalue, dot;
    const double e = 0.001;
    arrayNode *lenDif;
    lenDif = dif(fun);
    display(lenDif);
    arrayNode *answer=malloc(sizeof(arrayNode));
    answer->next = NULL;
    answer->value = 0.;


    oldvalue = funcValue(fun, start);
    while (s <= f)
    {
        s += step;
        value = funcValue(fun, s);

        if (value * oldvalue < 0)
        {
            printf("%f %f\n", value, oldvalue);
            dot = - oldvalue / funcValue(lenDif, s) + s;

            while (fabs(funcValue(fun, dot)) > e)
                {

                    dot = dot - funcValue(fun, dot) / funcValue(lenDif, dot);
                    printf("%f %f\n", fabs(funcValue(fun, dot)), dot);
                }
            append(answer, dot);
        }
        oldvalue = value;

    }


    return answer;
}


int main()
{
    arrayNode *f = malloc(sizeof(arrayNode));
    f->next = NULL;
    f->value = 5;
    append(f, 3);
    append(f, -2);
    append(f, 1);
    arrayNode *res;
    res = methodOfNewton(f, -1., 1, 0.03);
    display(res);
    return 0;
}
