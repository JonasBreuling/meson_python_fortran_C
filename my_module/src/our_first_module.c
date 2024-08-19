// see https://github.com/scipy/scipy/blob/main/scipy/integrate/_odepackmodule.c
// how a fortran function can be wrapped via a C module that is compiled via meson
#include <Python.h>

#ifdef HAVE_BLAS_ILP64
#define F_INT npy_int64
#define F_INT_NPY NPY_INT64
#else
#define F_INT int
#define F_INT_NPY NPY_INT
#endif

#if defined(UPPERCASE_FORTRAN)
    #if defined(NO_APPEND_FORTRAN)
        /* nothing to do here */
    #else
        #define BAR  BAR_
    #endif
#else
    #if defined(NO_APPEND_FORTRAN)
        #define BAR  bar
    #else
        #define BAR  bar_
    #endif
#endif

typedef void bar_f_t();

void BAR();

static PyObject* foo(PyObject* self)
{
    BAR();
    return PyUnicode_FromString("foo");
}

static PyMethodDef methods[] = {
    {"foo", (PyCFunction)foo, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "our_first_module",
    NULL,
    -1,
    methods,
};

PyMODINIT_FUNC PyInit_our_first_module(void)
{
    return PyModule_Create(&module);
}