# see https://numpy.org/doc/stable/f2py/buildtools/meson.html
project(
    'purelib-and-platlib', 
    'c',
)

add_languages('fortran')

py_mod = import('python')
py = py_mod.find_installation(pure: false)
py_dep = py.dependency()

subdir('my_module')