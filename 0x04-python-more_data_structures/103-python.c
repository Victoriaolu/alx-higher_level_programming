#include <Python.h>

/**
 * print_python_list - Prints information about a Python list
 * @p: Pointer to the PyObject list
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, i;
    PyObject *item;

    size = PyList_Size(p);
    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %ld\n", size);
    printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

    for (i = 0; i < size; i++)
    {
        item = PyList_GetItem(p, i);
        printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
    }
}

/**
 * print_python_bytes - Prints information about a Python bytes object
 * @p: Pointer to the PyObject bytes object
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *str;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p))
    {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size = PyBytes_Size(p);
    str = PyBytes_AsString(p);

    printf("  size: %ld\n", size);
    printf("  trying string: %s\n", str);

    printf("  first %ld bytes: ", size + 1 > 10 ? 10 : size + 1);
    for (i = 0; i < size + 1 && i < 10; i++)
        printf("%02hhx%c", str[i], i + 1 < size + 1 && i < 9 ? ' ' : '\n');
}
