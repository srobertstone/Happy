set number                 "" Shows the line numebr

set autoindent             "" Makes the next line on same tab 

syntax on


"" Changes tab to be equal to 2 spaces

filetype plugin indent on
" show existing tab with 2 spaces width
set tabstop=2
" when indenting with '>', use 2 spaces width
set shiftwidth=2
" On pressing tab, insert 4 spaces
set expandtab


set visualbell t_vb=
if has("autocmd") && has("gui")
    au GUIEnter * set t_vb=
endif
