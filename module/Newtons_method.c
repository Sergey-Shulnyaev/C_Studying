#include <stdio.h>
#include <stdlib.h>
#include <Python.h>

float myfabs(float a)
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

arrayNode *methodOfNewton(arrayNode *fun, arrayNode *range)
{
    float s, f, step, value, oldvalue, dot;
    const double e = 0.0001;
    step = pop(range);
    f = pop(range);
    s = pop(range);
    printf("%f, %f, %f.\n", s, f, step);

    arrayNode *lenDif;
    lenDif = dif(fun);
    arrayNode *answer=malloc(sizeof(arrayNode));
    answer->next = NULL;
    answer->value = 0.;


    oldvalue = funcValue(fun, s);
    while (s <= f)
    {
        s += step;
        value = funcValue(fun, s);
        if (value * oldvalue <= 0)
        {
            dot = - oldvalue / funcValue(lenDif, s) + s;

            while (myfabs(funcValue(fun, dot)) > e)
                {
                    dot = dot - funcValue(fun, dot) / funcValue(lenDif, dot);
                }

            append(answer, dot);
        }
        oldvalue = value;

    }
    if (NULL != answer->next)
    {
        arrayNode *aold=answer;
        answer = answer->next;
        free(aold);
    }

    return answer;
}

static PyObject *method(PyObject *self, PyObject *args){


    PyObject *func;
    PyObject *range;
    PyObject *pItem;
    Py_ssize_t n;
    int i;

    arrayNode *f = malloc(sizeof(arrayNode));
    f->next = NULL;

    arrayNode *r = malloc(sizeof(arrayNode));
    r->next = NULL;

    arrayNode *ans;
    PyObject *answer;


    if (!PyArg_ParseTuple(args, "OO", &func, &range))
        return NULL;

    n = PyList_Size(func);
    f->value = PyFloat_AsDouble(PyList_GetItem(func, 1));
    for (i=0; i<n; i++) {
        pItem = PyList_GetItem(func, i);
        if(!PyFloat_Check(pItem))
            return NULL;
        append(f, PyFloat_AsDouble(pItem));

    }
    n = PyList_Size(range);
    r->value = PyFloat_AsDouble(PyList_GetItem(range, 1));
    for (i=0; i<n; i++) {
        pItem = PyList_GetItem(range, i);
        if(!PyFloat_Check(pItem))
            return NULL;
        append(r, (float)PyFloat_AsDouble(pItem));

    }

    ans = methodOfNewton(f, r);
    arrayNode *j = ans;
    answer = PyList_New(0);
	while(j != NULL){ /* i=(*i).next */
        PyList_Append(answer, PyFloat_FromDouble((double)j->value));
		j=j->next;
	}
      return answer;
}

/* Описывает методы модуля */
static PyMethodDef ownmod_methods[] = {
{
    "method",          // название функции внутри python
     method,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "solve equation" // документация для функции внутри python
},
{ NULL, NULL, 0, NULL }
// так называемый sentiel. Сколько бы элементов структуры
// у вас не было, этот нулевой элемент должен быть всегда, и при этом быть последним
};

/* Описываем наш модуль */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,   // обязательный макрос
    "solving_equation",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // сюда передаем методы модуля
};

// в названии функции обязательно должен быть префикс PyInit
PyMODINIT_FUNC PyInit_method(void) {
      PyObject* m;
      // создаем модуль
      m = PyModule_Create(&simple_module);
      // если все корректно, то эта проверка не проходит
      if (m == NULL)
          return NULL;
      return m;
}
