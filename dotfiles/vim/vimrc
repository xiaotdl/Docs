" source $LOCAL_ADMIN_SCRIPTS/master.vimrc

" ==============================================================================
" Vundle >>>
" NOTE: Put this at the top of your .vimrc to use Vundle
set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()

" let Vundle manage Vundle, required

" vim package manager
Plugin 'VundleVim/Vundle.vim'

" [view][file] color scheme for vim
" Plugin 'morhetz/gruvbox' " XXX: less favored than molokai
Plugin 'tomasr/molokai'

" [view][file] highlight trailing spaces
Plugin 'ntpeters/vim-better-whitespace'

" [view][file] show parentheses in diff color
Plugin 'luochen1990/rainbow'

" [view][file][linter] asynchronous linting/fixing for Vim
Plugin 'w0rp/ale' " XXX: not working

" [view][file][cpp] cpp syntax highlighting
Plugin 'octol/vim-cpp-enhanced-highlight'

" [view][file][svn] show diff using the sign column
Plugin 'mhinz/vim-signify'

" [view][tool] a file system tree explorer
Plugin 'scrooloose/nerdtree'
Plugin 'jistr/vim-nerdtree-tabs' " nerdtree helper

" [view][tool] show buffers in tabline
Plugin 'vim-airline/vim-airline'
Plugin 'vim-airline/vim-airline-themes'

" [view][tool] show opened buffers in new window
Plugin 'jlanzarotta/bufexplorer'

" [view][tool] show class blueprints
" prerequisite: install exuberant-ctags
Plugin 'majutsushi/tagbar'

" [navigation] toggle between .h and .cpp
Plugin 'alxyang/a.vim'

" " [navigation] fuzzy search files and buffers
" Plugin 'wincent/command-t'  " XXX: cannot compile

" [navigation] fuzzy search files and buffers
Plugin 'ctrlpvim/ctrlp.vim'

" [auto-complete] a code-completion engine for Vim
" prerequisite:
"   install vim8
"   $ sudo yum install gcc-c++ cmake python-devel
"   $ cd ~/.vim/bundle/youcompleteme && python ./install.py
Plugin 'valloric/youcompleteme'

" [edit][auto-complete] Insert or delete brackets, parens, quotes in pair.
Plugin 'jiangmiao/auto-pairs'

" [edit][comment] comment multiple lines in visual mode
Plugin 'scrooloose/nerdcommenter'


" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line
" <<<

" ==============================================================================
" UI Layout {{{
" set colorcolumn=100     " display vertical line
set number              " show line numbers
set cursorline          " highlight/underscore current line
set wildmenu            " visual autocomplete for command menu, e.g. run :e ~/.vim<TAB>?
set wildmode=list:longest,full
set lazyredraw          " redraw only when we need to
set showmatch           " highlight matching [{()}]
set matchtime=15        " defaults to 5
set laststatus=2        " make statusline always visible
" set fillchars+=stl:\ ,stlnc:\
" set ruler               " show line, column, relative position
" highlight StatusLine ctermbg=White ctermfg=DarkRed
" highlight StatusLineNC ctermbg=White ctermfg=Black
" }}}

" ==============================================================================
" Searching {{{
set ignorecase          " ignore case when searching
set smartcase
set incsearch           " search as characters are entered
set hlsearch            " highlight matches
set nowrapscan          " disable search wrap around the eof

" * highlight search no jump forward, ref: https://stackoverflow.com/a/49944815
nnoremap <silent> * :let @/= '\<' . expand('<cword>') . '\>' <bar> set hls <cr>
" }}}

" ==============================================================================
" Spaces & Tabs {{{
set tabstop=2           " number of visual spaces per TABs
set shiftwidth=2        " when using the >> or << commands, shift lines
set softtabstop=2       " number of visual spaces in tab when editing
set expandtab           " expand tabs into spaces, e.g. :set tabstop=4 shiftwidth=4 expandtab; :retab
set autoindent          " indent when moving to the next line while writing code
set smartindent
set modelines=1         " ?
filetype indent on      " load filetype-specific indent files
filetype plugin on      " ?
" }}}

" ==============================================================================
" Leader Shortcuts && Key Mappings {{{
let mapleader=","       " leader is comma, defaults to \
noremap <leader>s       :source ~/.vimrc<CR>
nnoremap <leader>,      :w<CR>
nnoremap <leader>l      e %<CR>


" search <keyword> in fbgs
nnoremap <leader>g      yiw:!fbgs <C-r>"<CR>
" nnoremap <leader>g      yiw:!fbgs -f admarket/.* <C-r>"<CR>
nnoremap <leader>t      :tab sp

" buffer navigation >>>
nnoremap <C-j>           :bp<CR>
nnoremap <C-k>           :bn<CR>
" <<<

" " tab navigation >>>
" nnoremap <C-j>           gT
" nnoremap <C-k>           gt
" " <<<

" " ctrl-l to switch back to last active vim tab >>>
" " https://superuser.com/a/675119
" au TabLeave * let g:lasttab = tabpagenr()
" nnoremap <silent> <c-l> :exe "tabn ".g:lasttab<cr>
" vnoremap <silent> <c-l> :exe "tabn ".g:lasttab<cr>
" " <<<

" == Plugin key mappings ==


" }}}

" ==============================================================================
" Miscellaneous {{{
set encoding=utf-8
set t_Co=256

set ttyfast             " faster redraw"

" Enable syntax for file types
autocmd FileType md set syntax=markdown

" disable recording
" https://stackoverflow.com/questions/1527784/what-is-vim-recording-and-how-can-it-be-disabled
map q <Nop>

if has('mouse')
  set mouse=a
endif
" }}}


" ==============================================================================
" Autocommands for all languages:
function! VIMSET()
endfunction

function! CPPSET()
	nnoremap <leader>e       :w!<CR>:!g++ -std=c++11 -Wall % && ./a.out<CR>
endfunction

autocmd FileType vim        call VIMSET()
autocmd FileType c,cpp      call CPPSET()

" ==============================================================================
" ctags
" Build: ctags -R *
" Usage:
"   Ctrl-]          - Jump to the tag underneath the cursor
"   :ts <tag> <RET> - Search for a particular tag
"   :tn             - Go to the next definition for the last tag
"   :tp             - Go to the previous definition for the last tag
"   :ts             - List all of the definitions of the last tag
"   :tags           - Show the contents of the tag stack, it's like showing stack trace
"   Ctrl-t          - Jump back up in the tag stack
"   echo tagfiles() - show all tags files
" Config:
set tags=./tags;/ " recursively search tags file from current dir
" }}}

" ==============================================================================
" Plugin: 'VundleVim/Vundle.vim' {{{
" Ref: https://github.com/VundleVim/Vundle.vim#quick-start
" Usage:
"   :PluginInstall - install plugins
"   :PluginClean   - delete plugins
" }}}

" ==============================================================================
" Plugin: 'tomasr/molokai' {{{
" Ref: https://github.com/tomasr/molokai
" Tuning:
"   :runtime syntax/colortest.vim " check supported colors
"   256 colors - xterm number <-> display mapping, https://jonasjacek.github.io/colors/
" Overwrite: ~/.vim/bundle/molokai/colors/molokai.vim:238
"   hi Normal       ctermfg=15  ctermbg=235
" Config:
let g:molokai_original = 1
let g:rehash256 = 1
" }}}

syntax enable
colorscheme molokai
set background=dark

" ==============================================================================
" Plugin: 'ntpeters/vim-better-whitespace' {{{
" Ref: https://github.com/ntpeters/vim-better-whitespace
" Config:
highlight ExtraWhitespace ctermbg=red
let g:better_whitespace_enabled=1
let g:strip_whitespace_on_save=0
" }}}

" ==============================================================================
" Plugin: 'luochen1990/rainbow' {{{
" Ref: https://github.com/luochen1990/rainbow
" Usage:
"   :RainbowToggle - toggle
" Config:
let g:rainbow_active = 1
autocmd BufEnter * :RainbowToggleOn
" }}}

" ==============================================================================
" Plugin: 'w0rp/ale' {{{
" Ref: https://github.com/w0rp/ale
" Usage:
"   :ALEToggle - toggle
"   :help ale-cpp-options - check cpp related options
" Config:
let g:ale_linters = {
\  'c': ['clangtidy'],
\  'cpp': ['clangtidy'],
\}
let g:ale_linters_explicit = 1 " only run linters named in ale_linters settings
let g:ale_cpp_clangtidy_executable = 'clang-tidy.par clang-tidy'
let g:ale_c_build_dir = '/home/xiaotianli/compile_commands.json'
let g:ale_set_signs = 1
let g:ale_lint_on_enter = 1
let g:ale_lint_on_save = 1
" }}}

" ==============================================================================
" Plugin: 'octol/vim-cpp-enhanced-highlight' {{{
" Ref: https://github.com/octol/vim-cpp-enhanced-highlight
" }}}

" ==============================================================================
" Plugin: 'mhinz/vim-signify' {{{
" Ref: https://github.com/mhinz/vim-signify
" Usage:
"   :SignifyToggle - toggle
" Config:
" let g:signify_disable_by_default = 1 " toggle
let g:signify_vcs_list = ['git', 'hg']
let g:signify_realtime = 0 " 0 -> BufRead && BufWritePost
                           " 1 -> much more...
" }}}


" ==============================================================================
" Plugin: 'scrooloose/nerdtree' {{{
" Ref: https://github.com/scrooloose/nerdtree
" Usage:
"   :NERDTreeToggle - toggle
" Config:
" autocmd vimenter * NERDTree " uncomment to auto open upon vim start-up
" }}}

" ==============================================================================
" Plugin: 'jistr/vim-nerdtree-tabs' {{{
" Ref: https://github.com/jistr/vim-nerdtree-tabs
" Config:
let g:nerdtree_tabs_open_on_console_startup=1  " uncomment to auto open upon vim start-up
let g:nerdtree_tabs_autofind=1
" }}}

" ==============================================================================
" Plugin: 'vim-airline/vim-airline' {{{
" Ref: https://github.com/vim-airline/vim-airline
" Config:
" Enable the list of buffers
let g:airline#extensions#tabline#enabled = 1

" Show just the filename
let g:airline#extensions#tabline#fnamemod = ':t'
" }}}

" ==============================================================================
" Plugin: 'jlanzarotta/bufexplorer' {{{
" Ref: https://github.com/jlanzarotta/bufexplorer/blob/master/doc/bufexplorer.txt
" Usage:
"    <Leader>bt  or  :ToggleBufExplorer          - toggle
"    <Leader>be  or  :BufExplorer                - explore opened buffers in new window
"    <Leader>bs  or  :BufExplorerHorizontalSplit - explore opened buffers in horizontal window
"    <Leader>bv  or  :BufExplorerVerticalSplit   - explore opened buffers in vertical window
" }}}

" ==============================================================================
" Plugin: 'majutsushi/tagbar' {{{
" Ref: https://github.com/majutsushi/tagbar/blob/master/doc/tagbar.txt
" Usage:
"   :TagbarToggle - toggle
" Config:
" autocmd VimEnter * nested :TagbarOpen " uncomment to auto open upon vim start-up
let g:tagbar_width=100
" }}}

" ==============================================================================
" Plugin: 'alxyang/a.vim' {{{
" Ref: https://github.com/alxyang/a.vim
" Usage:
"   :A  - go to .h header/.cpp file in a new buffer
"   :AS - horizontal splits and switches
"   :AV - vertical splits and switches
" Example: if you are editing foo.c and need to edit foo.h simply execute :A and
" you will be editting foo.h, to switch back to foo.c execute :A again.
" }}}

" ==============================================================================
" Plugin: 'wincent/command-t' {{{
" Ref: https://github.com/wincent/command-t/blob/master/doc/command-t.txt
" }}}

" ==============================================================================
" Plugin: 'ctrlpvim/ctrlp.vim' {{{
" Ref: https://github.com/ctrlpvim/ctrlp.vim
" Usage:
"   :CtrlP  or CtrlP [starting-dir] - invoke CtrlP in find file mode
"   :CtrlPBuffer  or  CtrlPMRU      - invoke CtrlP in find buffer or MRU file mode
"   :CtrlPMixed                     - search in Files, Buffers and MRU files at the same time.
"   -- once CtrlP is opend --
"   <c-f>/<c-b> - cycle between modes
"   <c-j>/<c-k> - move down/up in the list
" Config:
let g:ctrlp_map = '<c-p>'
let g:ctrlp_cmd = 'CtrlPMixed'
let g:ctrlp_root_markers = ['adindexer.conf']
" }}}

" ==============================================================================
" Plugin: 'valloric/youcompleteme' {{{
" Ref: https://github.com/Valloric/YouCompleteMe
" }}}

" ==============================================================================
" Plugin: 'jiangmiao/auto-pairs' {{{
" Ref: https://github.com/jiangmiao/auto-pairs
" }}}

" ==============================================================================
" Plugin: 'scrooloose/nerdcommenter' {{{
" Ref: https://github.com/scrooloose/nerdcommenter/blob/master/doc/NERD_commenter.txt
" Usage:
"   first select lines with shift+v
"   :<Leader>cc - comment with //
"   :<Leader>cs - comment with /*
"                               * comment
"                               */
"   :<Leader>cu - uncomment
" }}}

" ======================================================================================================
" Fold C++ include files by default: {{{
function! Fold_Includes(ln)
  let cur_line = getline(a:ln)
  let prev_line = getline(a:ln - 1)

  " skip empty lines
  let empty_regex = '^\s*$'
  if cur_line =~ empty_regex
    return -1
  endif

  if cur_line[:8] == '#include '
    return (prev_line[:8] == '#include ' ||
          \ prev_line =~ empty_regex) ? 1 : '>1'
  endif

  return 0
endfunction

autocmd FileType c,cpp setlocal foldexpr=Fold_Includes(v:lnum) foldmethod=expr
" }}}
