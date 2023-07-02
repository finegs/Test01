"============= path =====================================

let s:lines = []
if executable('sed')
  if executable('cl') 
	let s:lines = systemlist('echo $INCLUDE')
  elseif executable('g++')
    let s:expr = 'echo |g++ -Wp,-v -x c++ - -fsyntax-only 2>&1 | grep "^ " | sed "s/^ //"'
    let s:lines = systemlist(s:expr)

"	let s:lines = []

"	let s:lines = add(s:lines, $MINGW_HOME)
	let s:lines = add(s:lines, 'inc')
	let s:lines = add(s:lines, '.')
	let s:lines = add(s:lines, 'D:\\Programs\\glibc\\glibc')
  endif

  for s:line in s:lines

"============= path =====================================
      execute 'set path+=' . fnameescape(s:line)
"============= tags =====================================
"
"	  let s:tagfile = s:line.'\tags'
"	  if filereadable(s:tagfile)
"		  execute 'set tags+='.s:tagfile
"	  endif
	"  let s:csf = s:line.'/cscope.out'
	"  if filereadable(s:csf)
	"	cs add s:csf
	"  endif
  endfor
endif

"============= tags =====================================
"if filereadable('./tags')
"	set tags+=./tags
"endif


"============= syntastic =====================================
"let g:syntastic_cpp_include_dirs = [ '../include', 'include', 'inc', '.']
"let g:syntastic_cpp_include_dirs +=[ 'D:/Programs/mingw64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++' ]
"let g:syntastic_cpp_include_dirs +=[ 'D:/Programs/mingw64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/x86_64-w64-mingw32' ]
"let g:syntastic_cpp_include_dirs +=[ 'D:/Programs/mingw64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include/c++/backward' ]
"let g:syntastic_cpp_include_dirs +=[ 'D:/Programs/mingw64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include' ]
"let g:syntastic_cpp_include_dirs +=[ 'D:/Programs/mingw64/mingw64/lib/gcc/x86_64-w64-mingw32/8.1.0/include-fixed' ]
"let g:syntastic_cpp_include_dirs +=[ 'D:/Programs/mingw64/mingw64/x86_64-w64-mingw32/include' ]
"let g:syntastic_cpp_include_dirs +=[ 'D:/Dev/git/gnuplot-gnuplot-main/src' ]

for s:item in s:lines
  let s:csf = s:item.'\\cscope.out'
  if filereadable(s:csf)
	execute 'cs add '.s:csf
  endif

  let s:tagfile = s:item.'\\tags'
  if filereadable(s:tagfile)
	  execute 'set tags+='.s:tagfile
  endif

endfor

