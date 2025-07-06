let s:so_save = &g:so | let s:siso_save = &g:siso | setg so=0 siso=0 | setl so=-1 siso=-1
argglobal
if bufexists(fnamemodify("D:/Dev/workspace/github_repository/test01/cpp/pjt01/algo/src/copcar.cpp", ":p")) | buffer D:/Dev/workspace/github_repository/test01/cpp/pjt01/algo/src/copcar.cpp | else | edit D:/Dev/workspace/github_repository/test01/cpp/pjt01/algo/src/copcar.cpp | endif
if &buftype ==# 'terminal'
  silent file D:/Dev/workspace/github_repository/test01/cpp/pjt01/algo/src/copcar.cpp
endif
setlocal foldmethod=expr
setlocal foldexpr=v:lua.require'lazyvim.util'.ui.foldexpr()
setlocal foldmarker={{{,}}}
setlocal foldignore=#
setlocal foldlevel=99
setlocal foldminlines=1
setlocal foldnestmax=20
setlocal foldenable
13
normal! zo
13
normal! zc
72
normal! zo
72
normal! zc
148
normal! zo
148
normal! zc
284
normal! zo
284
normal! zc
311
normal! zo
311
normal! zc
let s:l = 311 - ((310 * winheight(0) + 29) / 59)
if s:l < 1 | let s:l = 1 | endif
keepjumps exe s:l
normal! zt
keepjumps 311
normal! 0
let &g:so = s:so_save | let &g:siso = s:siso_save
set hlsearch
nohlsearch
doautoall SessionLoadPost
" vim: set ft=vim :
