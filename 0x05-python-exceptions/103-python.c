void print_python_list(PyObject *p)
{
    Py_ssize_t size, i;
    PyObject *item;

    if (!PyList_Check(p))
    {
        printf("[ERROR] Invalid List Object\n");
        fflush(stdout);
        return;
    }

    size = PyList_Size(p);
    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
    fflush(stdout);
}



void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *buffer;

    if (!PyBytes_Check(p))
    {
        printf("[ERROR] Invalid Bytes Object\n");
        fflush(stdout);
        return;
    }

    size = PyBytes_Size(p);
    printf("[.] bytes object info\n");
    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", PyBytes_AsString(p));

    if (size > 10)
        size = 10;

    buffer = PyBytes_AsString(p);
    printf("  first %ld bytes: ", size);
    for (i = 0; i < size; i++)
        printf("%02hhx%c", buffer[i], i == size - 1 ? '\n' : ' ');
    fflush(stdout)

void print_python_float(PyObject *p)
{
    char *buffer;
    PyFloatObject *float_obj = (PyFloatObject *)p;

    if (!PyFloat_Check(p))
    {
        printf("[ERROR] Invalid Float Object\n");
        fflush(stdout);
        return;
    }

    printf("[.] float object info\n");

    buffer = PyOS_double_to_string(PyFloat_AsDouble(p), 'r', 0, Py_DTSF_ADD_DOT_0, NULL);
    printf("  value: %s\n", buffer);
    printf("  precision: %d\n", float_obj->ob_base.ob_size * 8 - 1);
    fflush(stdout);
}


