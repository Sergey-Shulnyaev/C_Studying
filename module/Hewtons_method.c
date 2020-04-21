#include <Python.h>

static PyObject *solve_Newton(PyObject *self, PyObject *args){
    PyObject *pList;
    PyObject *pItem;
    Py_ssize_t n;
    int i;
    double st, fin, step;

    if (!PyArg_ParseTuple(args, "O!ddd", &PyList_Type, &pList, &st, &fin, &step)) {
        PyErr_SetString(PyExc_TypeError, "parameter must be a list.");
        return NULL;
    }

    n = PyList_Size(pList);
    for (i=0; i<n; i++) {
        pItem = PyList_GetItem(pList, i);
        if(!PyInt_Check(pItem)) {
            PyErr_SetString(PyExc_TypeError, "list items must be integers.");
            return NULL;
        }
    }

    double


}

/* Описывает методы модуля */
static PyMethodDef ownmod_methods[] = {
{
    "plus",          // название функции внутри python
     py_plus,        // функция C
     METH_VARARGS,   // макрос, поясняющий, что функция у нас с аргументами
     "plus function" // документация для функции внутри python
},
{ NULL, NULL, 0, NULL }
// так называемый sentiel. Сколько бы элементов структуры
// у вас не было, этот нулевой элемент должен быть всегда, и при этом быть последним
};

/* Описываем наш модуль */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,   // обязательный макрос
    "my_plus",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // сюда передаем методы модуля
};

// в названии функции обязательно должен быть префикс PyInit
PyMODINIT_FUNC PyInit_my_plus(void) {
      PyObject* m;
      // создаем модуль
      m = PyModule_Create(&simple_module);
      // если все корректно, то эта проверка не проходит
      if (m == NULL)
          return NULL;
      return m;
}
