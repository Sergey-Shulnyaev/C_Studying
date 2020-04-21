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

/* ��������� ������ ������ */
static PyMethodDef ownmod_methods[] = {
{
    "plus",          // �������� ������� ������ python
     py_plus,        // ������� C
     METH_VARARGS,   // ������, ����������, ��� ������� � ��� � �����������
     "plus function" // ������������ ��� ������� ������ python
},
{ NULL, NULL, 0, NULL }
// ��� ���������� sentiel. ������� �� ��������� ���������
// � ��� �� ����, ���� ������� ������� ������ ���� ������, � ��� ���� ���� ���������
};

/* ��������� ��� ������ */
static PyModuleDef simple_module = {
    PyModuleDef_HEAD_INIT,   // ������������ ������
    "my_plus",               // my_plus.__name__
    "amazing documentation", // my_plus.__doc__
    -1,
    ownmod_methods           // ���� �������� ������ ������
};

// � �������� ������� ����������� ������ ���� ������� PyInit
PyMODINIT_FUNC PyInit_my_plus(void) {
      PyObject* m;
      // ������� ������
      m = PyModule_Create(&simple_module);
      // ���� ��� ���������, �� ��� �������� �� ��������
      if (m == NULL)
          return NULL;
      return m;
}
