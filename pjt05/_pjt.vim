"============= path ====================================
set path+=.
set path+=/usr/include/c++/9
set path+=/usr/include/arm-linux-gnueabihf/c++/9
set path+=/usr/include/c++/9/backward
set path+=/usr/lib/gcc/arm-linux-gnueabihf/9/include
set path+=/usr/local/include
set path+=/usr/lib/gcc/arm-linux-gnueabihf/9/include-fixed
set path+=/usr/include/arm-linux-gnueabihf
set path+=/usr/include

set path+=/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/embedded-common
set path+=/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/sht-common
set path+=/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/sht20
set path+=/home/ubuntu/dev/git/repo/Test01/pjt05

"============= tags ====================================
set tags+=./tags
set tags+=/usr/include/c++/9/tags
set tags+=/usr/include/arm-linux-gnueabihf/c++/9/tags
set tags+=/usr/include/c++/9/backward/tags
set tags+=/usr/lib/gcc/arm-linux-gnueabihf/9/include/tags
set tags+=/usr/local/include/tags
set tags+=/usr/lib/gcc/arm-linux-gnueabihf/9/include-fixed/tags
set tags+=/usr/include/arm-linux-gnueabihf/tags
set tags+=/usr/include/tags

set tags+=/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/embedded-common/tags
set tags+=/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/sht-common/tags
set tags+=/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/sht20/tags
set tags+=/home/ubuntu/dev/git/repo/Test01/pjt05/tags

"============= syntastic ====================================
let g:syntastic_cpp_include_dirs = [ '../include', 'include', 'inc', '.' ]
let g:syntastic_cpp_include_dirs += [ '/usr/include/c++/9' ]
let g:syntastic_cpp_include_dirs += [ '/usr/include/arm-linux-gnueabihf/c++/9' ]
let g:syntastic_cpp_include_dirs += [ '/usr/include/c++/9/backward' ]
let g:syntastic_cpp_include_dirs += [ '/usr/lib/gcc/arm-linux-gnueabihf/9/include' ]
let g:syntastic_cpp_include_dirs += [ '/usr/local/include' ]
let g:syntastic_cpp_include_dirs += [ '/usr/lib/gcc/arm-linux-gnueabihf/9/include-fixed' ]
let g:syntastic_cpp_include_dirs += [ '/usr/include/arm-linux-gnueabihf' ]
let g:syntastic_cpp_include_dirs += [ '/usr/include' ]
let g:syntastic_cpp_include_dirs += [ '/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/embedded-common' ]
let g:syntastic_cpp_include_dirs += [ '/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/sht-common' ]
let g:syntastic_cpp_include_dirs += [ '/home/ubuntu/dev/git/repo/Sensirion/embedded-sht/sht20' ]

if filereadable("/usr/include/cscope.out")
  cs add /usr/include/cscope.out
endif

if filereadable("../cscope.out")
  cs add ../cscope.out
endif

if filereadable("./cscope.out")
  cs add cscope.out
endif

