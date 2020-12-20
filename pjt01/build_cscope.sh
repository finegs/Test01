#!/bin/bash

find /D/Programs/glibc/glibc/ -name '*.h' -o -name '*.c' > cscope.files
find . -name "*.[ch]" >> cscope.files
cscope -b -k -q

ctags -R --c++-kinds=+p --fields=+iaS --extra=+q /D/Programs/glibc/glibc

#ctags -R --c++-kinds=+p --fields=+iaS --extra=+q /usr/include
