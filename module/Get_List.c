PyObject *pList;
PyObject *pItem;
Py_ssize_t n;
int i;

if (!PyArg_ParseTuple(args, "O!", &PyList_Type, &pList)) {
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
