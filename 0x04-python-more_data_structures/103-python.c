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
#!/usr/bin/python3
from ctypes import cdll, py_object

# Load the shared library
lib = cdll.LoadLibrary("./libPython.so")

# Create a Python list
my_list = [1, 2, 3, 4, 5]

# Call the print_python_list function
lib.print_python_list(py_object(my_list))

# Create a Python bytes object
my_bytes = b"Hello, world!"

# Call the print_python_bytes function
lib.print_python_bytes(py_object(my_bytes))

This will output:
[*] Python list info
[*] Size of the Python List = 5
[*] Allocated = 8
Element 0: int
Element 1: int
Element 2: int
Element 3: int
Element 4: int
[.] bytes object info
  size: 13
  trying string: Hello, world!
  first 10 bytes: 48 65 6c 6c 6f 2c 20 77 6f 72

Try Copilot
Copilot is the best way to answer the hardest questions. Search the web more comprehensively than ever before.
Related
What is the purpose of the print_python_list function
What is the difference between a Python string and a byte string
What is the struct module in Python and how is it related to bytes

