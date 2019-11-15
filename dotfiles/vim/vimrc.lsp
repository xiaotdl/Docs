set nocompatible              " be iMproved, required
filetype off                  " required

" set the runtime path to include Vundle and initialize
set rtp+=~/.vim/bundle/Vundle.vim
call vundle#begin()
" alternatively, pass a path where Vundle should install plugins
"call vundle#begin('~/some/path/here')

" let Vundle manage Vundle, required
Plugin 'VundleVim/Vundle.vim'

" " The following are examples of different formats supported.
" " Keep Plugin commands between vundle#begin/end.
" " plugin on GitHub repo
" Plugin 'tpope/vim-fugitive'
" " plugin from http://vim-scripts.org/vim/scripts.html
" " Plugin 'L9'
" " Git plugin not hosted on GitHub
" Plugin 'git://git.wincent.com/command-t.git'
" " git repos on your local machine (i.e. when working on your own plugin)
" Plugin 'file:///home/gmarik/path/to/plugin'
" " The sparkup vim script is in a subdirectory of this repo called vim.
" " Pass the path to set the runtimepath properly.
" Plugin 'rstacruz/sparkup', {'rtp': 'vim/'}
" Install L9 and avoid a Naming conflict if you've already installed a
" different version somewhere else.
" Plugin 'ascenator/L9', {'name': 'newL9'}

" [view][file][linter] asynchronous linting/fixing for Vim
Plugin 'dense-analysis/ale' " XXX: not working, needs vim version > vim8

" async autocomplete
Plugin 'prabirshrestha/async.vim'
Plugin 'prabirshrestha/vim-lsp'
Plugin 'prabirshrestha/asyncomplete.vim'
Plugin 'prabirshrestha/asyncomplete-lsp.vim'

" (Optional) This plugin is an extension of vim-lsp plugin that supports some
" additional methods provided by cquery. For now, this methods are
" $cquery/base, $cquery/derived and $cquery/vars. More methods will be added
" in future.
Plugin 'pdavydov108/vim-lsp-cquery'

" All of your Plugins must be added before the following line
call vundle#end()            " required
filetype plugin indent on    " required
" To ignore plugin indent changes, instead use:
"filetype plugin on
"
" Brief help
" :PluginList       - lists configured plugins
" :PluginInstall    - installs plugins; append `!` to update or just :PluginUpdate
" :PluginSearch foo - searches for foo; append `!` to refresh local cache
" :PluginClean      - confirms removal of unused plugins; append `!` to auto-approve removal
"
" see :h vundle for more details or wiki for FAQ
" Put your non-Plugin stuff after this line

" " ==============================================================================
syntax enable
" " colorscheme molokai
" set background=dark
set cursorline          " highlight/underscore current line
set wildmenu            " visual autocomplete for command menu, e.g. run :e ~/.vim<TAB>?
set wildmode=list:longest,full
set hls
set path+=/data/users/xiaotianli/fbsource/fbcode
set path+=/data/users/xiaotianli/fbsource/fbcode/admarket/adindexer/**
set path+=/data/users/xiaotianli/fbsource/fbcode/buck-out/opt/gen/admarket/adindexer/if/**
" " ==============================================================================

" ==============================================================================
" Plugin: 'dense-analysis/ale' {{{
" Ref: https://github.com/dense-analysis/ale
" Usage:
"   :ALEToggle - toggle
"   :help ale-cpp-options - check cpp related options
" Config:
let g:ale_enabled = 0
" let b:ale_linters = ['cquery_buck']

" " disabled in favor of vim-lsp
" let g:ale_completion_enabled = 1
" set omnifunc=ale#completion#OmniFunc

let g:ale_sign_error = '!'
let g:ale_sign_warning = '?'
" let g:ale_completion_enabled = 1
" let g:ale_linters = {
" \  'c': ['clangtidy'],
" \  'cpp': ['clangtidy'],
" \}
" let g:ale_linters_explicit = 1 " only run linters named in ale_linters settings
" let g:ale_cpp_clangtidy_executable = 'clang-tidy.par clang-tidy'
" let g:ale_c_build_dir = '/home/xiaotianli/compile_commands.json'
" let g:ale_set_signs = 1
" let g:ale_lint_on_enter = 1
" let g:ale_lint_on_save = 1
" }}}

" ==============================================================================
" source:
" https://our.internmc.facebook.com/intern/wiki/Development_Environment/Vim/#configerator
" if getcwd() =~ 'configerator'
"     let prefix = 'source/'
" 
"     if getcwd() =~ 'source\/\?$'
"         let prefix = ''
"     endif
" 
"     setlocal includeexpr=prefix.substitute(substitute(v:fname,'\\.','/','g'),'\\(.*\\)\\/','\\1.','')
" endif

" ==============================================================================
" source:
" https://our.internmc.facebook.com/intern/wiki/Development_Environment/Vim/#c-fold-includes-and-name
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

  if cur_line[:9] == 'namespace '
    return prev_line[:9] == 'namespace ' ? 1 : '>1'
  endif

  let end_ns_regex = '^}}*\s*//\s*namespace'
  if cur_line =~ end_ns_regex
    return prev_line =~ end_ns_regex ? 1 : '>1'
  endif

  return 0
endfunction

au FileType c,cpp setlocal foldexpr=Fold_Includes(v:lnum) foldmethod=expr


" " ==============================================================================
" LSP settings
let g:lsp_log_file = expand('/tmp/vim-lsp.log')
" Key bindings for normal mode
nnoremap <C-]> :LspDefinition<CR>
nnoremap T :LspHover<CR>
nnoremap <c-y> :LspDocumentDiagnostics<Cr>

" Autocomplete
let g:lsp_async_completion = 1
imap <c-space> <Plug>(asyncomplete_force_refresh)
inoremap <expr> <Tab> pumvisible() ? "\<C-n>" : "\<Tab>"
inoremap <expr> <S-Tab> pumvisible() ? "\<C-p>" : "\<S-Tab>"
inoremap <expr> <cr> pumvisible() ? "\<C-y>\<cr>" : "\<cr>"
autocmd! CompleteDone * if pumvisible() == 0 | pclose | endif

" Hover (type info) settings
let &previewheight = 5

" Diagnostics/Linter
let g:lsp_diagnostics_enabled = 1
let g:lsp_signs_enabled = 1         " Show errors in sidebar
let g:lsp_diagnostics_echo_cursor = 1 " Enable echo under cursor when in normal mode
let g:lsp_signs_error = {'text': '✗'}
let g:lsp_signs_warning = {'text': '‼'}


" FBCode using cquery
" Options from
" https://phabricator.internmc.facebook.com/diffusion/FBS/browse/master/xplat/nuclide/pkg/nuclide-cquery-lsp-rpc/lib/CqueryInitialization.js
if executable('cquery')
   au User lsp_setup call lsp#register_server({
      \ 'name': 'cquery',
      \ 'cmd': {server_info->['bash', '-c',
      \   '/data/users/$USER/fbsource/fbcode/experimental/gwicke/vim/fbcode_cquery_wrapper' ]},
      \ 'root_uri': {server_info->lsp#utils#path_to_uri(lsp#utils#find_nearest_parent_file_directory(lsp#utils#get_buffer_path(), '.buckconfig'))},
      \ 'initialization_options': {
      \   'cacheDirectory': '/tmp/cquery_cache',
      \   'index': {
      \     'blacklist': ['.*/buck-out/.*', '.*/third-party-buck/.*']
      \   },
      \   'completion': {
      \     'includeBlacklist': ['.*/buck-out/.*', '.*/third-party-buck/.*'],
      \     'enableSnippets': v:true,
      \   },
      \   'diagnostics': {
      \     'blacklist': ['.*/buck-out/.*', '.*/third-party-buck/.*'],
      \     'onParse': v:true,
      \     'onType': v:true,
      \   },
      \   'resourceDirectory': '',
      \   'discoverSystemIncludes': v:false,
      \   'showDocumentLinksOnIncludes': v:false,
      \   'disableInitialIndex': v:true,
      \   'progressReportFrequencyMs': 500,
      \   'clientVersion': 3,
      \   'codeLens': {
      \        'localVariables': v:false,
      \   },
      \ },
      \ 'whitelist': ['c', 'cpp', 'objc', 'objcpp', 'cc'],
      \ })
endif

" FB: C++ Autocomplete with LSP
" https://fb.workplace.com/groups/vim/permalink/2153216101386074/
let g:asyncomplete_auto_popup=1
let g:asyncomplete_remove_duplicates=1
autocmd FileType c,cpp,h setlocal omnifunc=lsp#complete
let g:asyncomplete_log_file = expand('/tmp/asyncomplete.log')

" Python
au User lsp_setup call lsp#register_server({
    \ 'name': 'pyls',
    \ 'cmd': {server_info->['bash', '-c',
    \   '/data/users/$USER/fbsource/fbcode/experimental/gwicke/vim/fbcode_pyls_wrapper']},
    \ 'whitelist': ['python'],
    \ 'workspace_config': {
    \   'pyls': { 'plugins': { 'pydocstyle': {' enabled': v:true}}}
    \ },
    \ })
