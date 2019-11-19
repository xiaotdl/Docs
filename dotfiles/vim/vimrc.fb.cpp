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

" [view][file] show the indention levels with thin vertical lines
" Plugin 'thaerkh/vim-indentguides' " XXX: distracting

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
Plugin 'micbou/a.vim'

" " [navigation] fuzzy search files and buffers
" Plugin 'wincent/command-t'  " XXX: cannot compile

" [navigation] fuzzy search files and buffers
Plugin 'ctrlpvim/ctrlp.vim'

" [auto-complete] a code-completion engine for Vim
" prerequisite:
"   install vim8
"   $ sudo yum install gcc-c++ cmake python-devel
"   $ cd ~/.vim/bundle/youcompleteme && python ./install.py
" Plugin 'valloric/youcompleteme'

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
set colorcolumn=80      " display vertical line
set number              " show line numbers
set cursorline          " highlight/underscore  cursorline
set wildmenu            " visual autocomplete for command menu, e.g. run :e ~/.vim<TAB>?
set wildmode=list:longest,full
set lazyredraw          " redraw only when we need to
set showmatch           " highlight matching [{()}]
set matchtime=15        " defaults to 5
set laststatus=2        " make statusline always visible
" fill the statuslines and vertical separators with 'char'
set fillchars+=stl:\ ,stlnc:\
" set ruler               " show line, column, relative position
" highlight StatusLine ctermbg=White ctermfg=DarkRed
" highlight StatusLineNC ctermbg=White ctermfg=Black
" }}}

" ==============================================================================
" Searching {{{
set ignorecase          " ignore case when searching
set smartcase           " override "ignorecase" if search with upper case
set incsearch           " search as characters are entered
set hlsearch            " highlight matches
set redrawtime=1000     " time in milliseconds for redarwing display for hlsearch
set nowrapscan          " disable search wrap around the eof

" * highlight matches without moving to the next word >>>
" REF: http://vim.wikia.com/wiki/Highlight_all_search_pattern_matches#Highlight_matches_without_moving
nnoremap <silent> * :let @/='\<<C-R>=expand("<cword>")<CR>\>'<CR>:set hls<CR>
" <<<

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
nnoremap <leader>s       :source ~/.vimrc<CR>
nnoremap <leader>,      :w<CR>
nnoremap <leader>p      :set invpaste paste?<CR>


" search <keyword> in fbgs
" nnoremap <leader>f      yiw:!fbgs <C-r>"<CR>
" nnoremap <leader>f      yiw:!fbgs -f fbsource/fbcode/admarket/.* <C-r>"<CR>
nnoremap <leader>f      yiw:!fbgs -f fbsource/fbcode/admarket/adindexer/.* <C-r>" && fbgs -f fbsource/fbcode/admarket/libadmarket/if/.* <C-r>"<CR>

" search <keyword> in cbgs
nnoremap <leader>c      yiw:!cbgs -f source/admarket/adindexer/.* <C-r>"<CR>


" buffer mgmt >>>
" better version of :bd
" nnoremap <C-d>           :call CloseSplitOrBuffer()<CR>
nnoremap <C-d>           :q<CR>
" <<<

" buffer navigation >>>
" go to the left window
nnoremap gB              :bp<CR>
" go to the right window
nnoremap gb              :bn<CR>
" <<<

" window navigation >>>
" go to the left window
nnoremap <C-j>           <C-w>h
" go to the right window
nnoremap <C-k>           <C-w>l
" <<<

" tab mgmt >>>
" open current file in a new tab, go to next hls
nnoremap <leader>t      :tab sp %<CR>n
" <<<

" tab navigation >>>
"   gT " go to the previous tab page
"   gt " go to the next tab page
" <<<

" " ctrl-l to switch back to last active vim tab >>>
" " https://superuser.com/a/675119
au TabLeave * let g:lasttab = tabpagenr()
nnoremap <silent> <C-l> :exe "tabn ".g:lasttab<cr>
vnoremap <silent> <C-l> :exe "tabn ".g:lasttab<cr>
" " <<<

" }}}

" == Plugin key mappings ==
" ctags: {{{
" highlight current word, open a vertical split window, jump to the next tag, center
" nnoremap <silent> <C-]>           *:vs<CR><C-]>
" nnoremap <silent> <C-]>           :let @/='\<<C-R>=expand("<cword>")<CR>\>'<CR>:set hls<CR>  :vs<CR>  <C-]>
nnoremap <silent> <C-]>           b:let @/='\<<C-R>=expand("<cword>")<CR>\>'<CR>:set hls<CR>  :vs<CR>  <C-]> zz

" jump to previous tag
nnoremap <C-[>           <C-T>
" }}}

" Plugin: 'jlanzarotta/bufexplorer' {{{
nnoremap <leader>B      :BufExplorer<CR>
" }}}

" ==============================================================================
" Miscellaneous {{{
set encoding=utf-8
set t_Co=256

set ttyfast             " faster redraw"

" Enable syntax for file types
" List All Vim supported filetypes
"   :echo getcompletion('', 'filetype')
au BufRead,BufNewFile *.md             set filetype=markdown
au BufRead,BufNewFile *.thrift         set filetype=cpp
au BufRead,BufNewFile *.cinc,*.cconf   set filetype=python

" disable recording
" https://stackoverflow.com/questions/1527784/what-is-vim-recording-and-how-can-it-be-disabled
map q <Nop>

" disable entering Ex mode in vim
nnoremap Q <Nop>

" mouse mgmt >>>
" if has('mouse')
"   set mouse=a "enable mouse
" endif

" disable mouse to avoid unintended insert
set mouse=
set ttymouse=
" <<<

" cursor navigation config >>>
" scrolling faster with cursor
set scrolljump=10  " scroll vertically
set sidescroll=10 " scroll horizontally
" <<<

" automatically re-read files changed outside vim
set autoread
" automatically write files when buffer is changed
set autowrite

set noerrorbells       " no bells in terminal"
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
" CTAGS:
" Build: ctags -R *
" $ ctags -R --c++-kinds=+p --fields=+iaS --extra=+q fbsource/fbcode/admarket/adindexer
" Usage:
"   Ctrl-]          - Jump to the tag underneath the cursor
"   :ts <tag> <RET> - Search for a particular tag
"   :tn             - Go to the next definition for the last tag
"   :tp             - Go to the previous definition for the last tag
"   :ts             - List all of the definitions of the last tag
"   :tags           - Show the contents of the tag stack, it's like showing stack trace
"   g]	            - Like CTRL-], but use ":tselect" instead of ":tag".
"   g CTRL-]        - Like CTRL-], but use ":tjump" instead of ":tag".
"   Ctrl-t          - Jump back up in the tag stack
"   echo tagfiles() - show all tags files
" Config:
set tags+=./tags,tags;  " recursively search tags file from current dir

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
" Overwrite: ~/.vim/bundle/molokai/colors/molokai.vim
"   if exists("g:rehash256") && g:rehash256 == 1
"     hi Normal       ctermfg=15  ctermbg=235
"     hi CursorLine               ctermbg=242   cterm=none
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
"" Plugin: 'thaerkh/vim-indentguides' {{{
"" Ref: https://github.com/thaerkh/vim-indentguides
"let g:indentguides_toggleListMode = 0
"" }}}

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
" let loaded_nerd_tree=0 .   " disable NERDTree

" close vim if the only window left open is a NERDTree
autocmd bufenter * if (winnr("$") == 1 && exists("b:NERDTreeType")) | q | endif
let NERDTreeIgnore = ['\.pyc$']
" }}}

" ==============================================================================
" Plugin: 'jistr/vim-nerdtree-tabs' {{{
" Ref: https://github.com/jistr/vim-nerdtree-tabs
" Config:
" let g:nerdtree_tabs_open_on_console_startup=1  " uncomment to auto open upon vim start-up
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

" let g:airline_powerline_fonts = 1 "XXX: powerline fonts not working
" }}}

" ==============================================================================
" Plugin: 'vim-airline/vim-airline-themes' {{{
" Ref: https://github.com/vim-airline/vim-airline-themes/blob/master/doc/airline-themes.txt
" Config:
let g:airline_theme='dark' " powerline alike tabline and statusline
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
" Ref: https://github.com/majutsushi/tagbark
" Usage:
"   :TagbarToggle - toggle
" Config:
" autocmd VimEnter * nested :TagbarOpen " uncomment to auto open upon vim start-up
" nnoremap <leader>T      :TagbarToggle<CR>
nnoremap <leader>T      :TagbarOpenAutoClose<CR>
let g:tagbar_width=150
" }}}

" ==============================================================================
" Plugin: 'micbou/a.vim' {{{

" Ref: https://github.com/micbou/a.vim
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
"   <c-v>       - open vertical split buffer
" Config:
let g:ctrlp_map = '<c-p>'
let g:ctrlp_cmd = 'CtrlPMixed'
let g:ctrlp_root_markers = ['.project']
let g:ctrlp_mruf_case_sensitive = 0 " set to enable search case insensitive
" }}}

" ==============================================================================
" Plugin: 'valloric/youcompleteme' {{{
" AKA: YCM
" Ref: https://github.com/Valloric/YouCompleteMe
" Usage:
"   :YcmRestartServer - restart ycmd for vimrc changes to take effect
" Config:
" let g:ycm_filetype_blacklist = {'*': 1} " toggle, uncomment to turn off YCM, use :set ft? to check filetype
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

" ==============================================================================
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

" autocmd FileType c,cpp setlocal foldexpr=Fold_Includes(v:lnum) foldmethod=expr " uncomment to toggle
" }}}

" Usage:
"   :set nofoldenable - toggle

" ==============================================================================
" Close only one buffer instance
" Use Case: after vsplit, still use :bd to close the buffer instead of :q
function! g:CloseSplitOrBuffer()
    " Is the file opened at least two times?
    if winnr('$') > 1
        execute ':q'
    else
        execute ':bd'
    endif
endfunction
" }}}

" ==============================================================================
" VIM_MANUAL:
" help:
"   :help {CMD}       - show command, e.g. `:h :file`, `:h CTRL-G`

" vim variable:
"   :let g:[var] = [value] - set variable
"   :echo g:[var]          - print variable
"   :verbose set [var]?    - e.g. verbose set modeline? modelines?

" key mapping:
"   :help index       - show built-in command mappings in different modes, e.g. CTRL-I: same as <Tab>
"   :map              - show user-defined command mappings, e.g. <MODE> <C-P>: <Plug>(ctrlp)

" ==============================================================================
" VIM_MGMT:
" fold mgmt:
"   :help fold - manual
"   zo         - open one fold under the cursor
"   zc         - close one fold under the cursor
"   za         - toggle one fold under the cursor
"   zR         - open all folds
"   zM         - close all folds
"   zi         - toggle foldenalbe

" buffer mgmt:
"   description: the in-memory text of a file
"   :ls or :buffers - list all buffers

" window mgmt:
"   description: a viewport on a buffer
"   :help window     - manual
"   :s[plit] [file]  - split current window in two horizontally
"   :vs[plit] [file] - split current window in two vertically
"   :bel[owright] vsp[lit] [file] - open new window on below right
"   :q[uit]          - quit the current window, quit vim if this is the last window

"   Ctrl-w x         - swap the current window with the next one
"   Ctrl-w =         - make all windows the same height and width

" tab page mgmt:
"   description: a collection of windows
"   :help tabpage       - manual
"   :tabs               - list all tabs
"   :tabe[dit] [file]   - open file in a new tab
"   :tabf[ind] [file]   - open a new tab with filename given, searching the path to find it
"   :tab sp[lit] [file] - split the current window, but open the split in a new tab
"   :tabm[ove] -N|+N    - move current tab to N places to the left|right
"   :tabclose           - close current tab

" file mgmt:
"   :f[ile] - prints the current file name
" Config:
"   .       - parent dir
"   <empty> - current dir
"   **      - subdir
set path=.,,** " used by tabfind etc.


" font mgmt:
"   CMD-+    - increase font size
"   CMD--    - decrease font size


" ==============================================================================
" VIM_NAVIGATION:
" cursor navigation:
"   H        - move cursor to the first line of the window
"   M        - move cursor to the middle line of the window
"   L        - move cursor to the last line of the window
"   {line#}G - move cursor to {line#}

" buffer navigation:
"   Ctrl-o   - jump back to the pevious(older) location
"   Ctrl-i   - jump forward to the next(newer) location

" window navigation:
"   Ctrl-w w - go to the next window
"   Ctrl-w h - go to the left window
"   Ctrl-w l - go to the right window

" tab page navigation:
"   {count}gt    - go to tab page {count}
"   :tabp or gT  - go to the previous tab page
"   :tabn or gt  - go to the next tab page

" ==============================================================================
" VIM_NAVIGATION_THROUGH_CALLSTACK:
" 1. open a vertical buffer on the left window
"    CMD: Ctrl-w v  or :vs
" 2. goto declaration
"    CMD: Ctrl-]
" 1-2.
"    CMD: Ctrl-] or :vs<CR><C-]>
" 3. close current split/buffer
"    CMD: Ctrl-d or :q/:bd
" 3.1. repeatedly doing step1-2 till too many windows, open current file in a new tab
"    CMD: <leader>t or :tab sp %<CR>
" 4.1. close current tab
"    CMD: :tabclose
" 4.2. go back to previous active tab
"    CMD: Ctrl-l

" ==============================================================================
" VIM_MOUSE_COPY:
" press 'alt' and use mouse to select, then cmd+c to copy selected word

" ==============================================================================
" LESSION:
" * Accidentally press Ctrl-s will lock the screen. Press Ctrl-q to unlock.

" vim:tw=78:ts=2:sw=2:expandtab:ft=help:norl:syntax=vim:foldmethod=marker:
