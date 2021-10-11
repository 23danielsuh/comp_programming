set laststatus=2
set nocompatible
set noshowmode
set shortmess+=c
filetype off

:autocmd VimResized * wincmd =

let mapleader=" "
nmap <C-t> :Todoist CP<CR>

autocmd CompleteDone * if !pumvisible() | pclose | endif

call plug#begin()
"UI Plugins
Plug 'sainnhe/gruvbox-material'
Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
Plug 'neovim/nvim-lspconfig'
Plug 'norcalli/nvim-colorizer.lua'
Plug 'Murtaza-Udaipurwala/gruvqueen'
Plug 'hoob3rt/lualine.nvim'
Plug 'glepnir/lspsaga.nvim'
Plug 'onsails/lspkind-nvim'
Plug 'romgrk/todoist.nvim', { 'do': ':TodoistInstall' }
Plug 'nvim-lua/plenary.nvim'
Plug 'nvim-telescope/telescope.nvim'

"Editor plugins
Plug 'scrooloose/nerdcommenter'
Plug 'reedes/vim-pencil'
Plug 'hrsh7th/nvim-compe'
Plug 'kyazdani42/nvim-web-devicons'
Plug 'akinsho/nvim-bufferline.lua'
Plug 'numToStr/FTerm.nvim'
call plug#end()

nnoremap <C-f> <cmd>Telescope find_files<cr>
nnoremap <C-p> <cmd>Telescope buffers<cr>

let todoist = {
    \ 'icons': {
\   'unchecked': '  ',
\   'checked':   '  ',
\   'loading':   '  ',
\   'error':     '  ',
\ },
\  'defaultProject': 'Inbox',
\  'useMarkdownSyntax': v:true,
\}

nnoremap <silent>rn :Lspsaga rename<CR>

set completeopt=menuone,noselect

nnoremap <silent> [e :Lspsaga diagnostic_jump_next<CR>
nnoremap <silent> ]e :Lspsaga diagnostic_jump_prev<CR>

let g:compe = {}
let g:compe.enabled = v:true
let g:compe.autocomplete = v:true
let g:compe.debug = v:false
let g:compe.min_length = 1
let g:compe.preselect = 'enable'
let g:compe.throttle_time = 80
let g:compe.source_timeout = 200
let g:compe.resolve_timeout = 800
let g:compe.incomplete_delay = 400
let g:compe.max_abbr_width = 100
let g:compe.max_kind_width = 100
let g:compe.max_menu_width = 100
let g:compe.documentation = v:true

let g:compe.source = {}
let g:compe.source.path = v:true
let g:compe.source.buffer = v:true
let g:compe.source.calc = v:true
let g:compe.source.nvim_lsp = v:true
let g:compe.source.nvim_lua = v:true
let g:compe.source.vsnip = v:true
let g:compe.source.ultisnips = v:true
let g:compe.source.luasnip = v:true

syntax on
filetype plugin indent on

autocmd BufNewFile *.cpp 0r ~/template.cpp
autocmd BufEnter * :SoftPencil

"set clipboard=unnamedplus
nnoremap  <silent>   <tab>  :if &modifiable && !&readonly && &modified <CR> :write<CR> :endif<CR>:bnext<CR>
nnoremap  <silent> <s-tab>  :if &modifiable && !&readonly && &modified <CR> :write<CR> :endif<CR>:bprevious<CR>
set backspace=indent,eol,start termguicolors softtabstop=4 shiftwidth=4 tabstop=4 expandtab number relativenumber ruler showcmd scrolloff=35 splitright splitbelow title nojoinspaces mouse=a background=dark signcolumn=yes encoding=UTF-8
set shortmess+=c
let g:airline_powerline_fonts = 1
let g:airline#extensions#tabline#enabled = 1
imap jk <Esc>
nmap <C-h> <C-w>h
nmap <C-j> <C-w>j
nmap <C-k> <C-w>k
nmap <C-l> <C-w>l
nnoremap gA :%y+<CR>

function! W()
    w
endfunction

command! W call W()
set encoding=utf-8

function! TermWrapper(command) abort
if !exists('g:split_term_style') | let g:split_term_style = 'vertical' | endif
if g:split_term_style ==# 'vertical'
    let buffercmd = 'vnew'
elseif g:split_term_style ==# 'horizontal'
    let buffercmd = 'new'
else
    echoerr 'ERROR! g:split_term_styleis not a valid value (must be ''horizontal'' or ''vertical'' but is currently set to ''' . g:split_term_style . ''')'
    throw 'ERROR! g:split_term_style is not a valid value (must be ''horizontal'' or ''vertical'')'
endif
if exists('g:split_term_resize_cmd')
    exec g:split_term_resize_cmd
endif
exec buffercmd
exec 'term ' . a:command
exec 'startinsert'
endfunction

command! -nargs=0 CompileAndRunWithFlags call TermWrapper(printf('g++ -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 %s -o ~/./a.out && ~/./a.out', expand('%:p')))
command! -nargs=0 Run call TermWrapper(printf('~/./a.out'))

autocmd FileType cpp nnoremap gc :w <bar> :CompileAndRunWithFlags<CR>
autocmd FileType cpp nnoremap gr :w <bar> :Run<CR>

let bufferline = get(g:, 'bufferline', {})

lua << EOF
    require('lspkind').init({
        -- enables text annotations
        --
        -- default: true
        with_text = true,

        -- default symbol map
        -- can be either 'default' or
        -- 'codicons' for codicon preset (requires vscode-codicons font installed)
        --
        -- default: 'default'
        preset = 'codicons',

        -- override preset symbols
        --
        -- default: {}
        symbol_map = {
          Text = "",
          Method = "",
          Function = "",
          Constructor = "",
          Field = "ﰠ",
          Variable = "",
          Class = "ﴯ",
          Interface = "",
          Module = "",
          Property = "ﰠ",
          Unit = "塞",
          Value = "",
          Enum = "",
          Keyword = "",
          Snippet = "",
          Color = "",
          File = "",
          Reference = "",
          Folder = "",
          EnumMember = "",
          Constant = "",
          Struct = "פּ",
          Event = "",
          Operator = "",
          TypeParameter = ""
        },
    })
    vim.g.gruvqueen_transparent_background = false

    vim.g.gruvqueen_disable_bold = true
    vim.g.gruvqueen_italic_comments = false
    vim.g.gruvqueen_italic_keywords = false
    vim.g.gruvqueen_italic_functions = false
    vim.g.gruvqueen_italic_variables = false
    vim.g.gruvqueen_invert_selection = false
    vim.g.gruvqueen_style = 'mix' -- possible values: 'original', 'mix', 'material'

    vim.cmd('colorscheme gruvbox-material')
    require'nvim-treesitter.configs'.setup {
      --ensure_installed = "maintained", -- one of "all", "maintained" (parsers with maintainers), or a list of languages
      ignore_install = { "javascript" }, -- List of parsers to ignore installing
      highlight = {
        enable = true,              -- false will disable the whole extension
        disable = { "c", "rust" },  -- list of language that will be disabled
        -- Setting this to true will run `:h syntax` and tree-sitter at the same time.
        -- Set this to `true` if you depend on 'syntax' being enabled (like for indentation).
        -- Using this option may slow down your editor, and you may see some duplicate highlights.
        -- Instead of true it can also be a list of languages
        additional_vim_regex_highlighting = false,
      },
      indent = {
        enable = false
      }
    }

    require'lspconfig'.clangd.setup {}
    vim.lsp.handlers["textDocument/publishDiagnostics"] = vim.lsp.with(
      vim.lsp.diagnostic.on_publish_diagnostics, {
        update_in_insert = true,
      }
    )
    require'colorizer'.setup()
    require'lualine'.setup{
        options = {theme = 'auto'}
    }
    local saga = require 'lspsaga'
    saga.init_lsp_saga{
        code_action_prompt = {
            enable = false
        }
    }
    require("bufferline").setup{
        offsets = {
          {
            filetype = "NvimTree",
            text = function()
              return vim.fn.getcwd()
            end,
            highlight = "Directory",
            text_align = "left"
          }
        }
    }
    require('FTerm').setup()

    local map = vim.api.nvim_set_keymap
    local opts = { noremap = true, silent = true }

    map('n', '<A-i>', '<CMD>lua require("FTerm").toggle()<CR>', opts)
    map('t', '<A-i>', '<C-\\><C-n><CMD>lua require("FTerm").toggle()<CR>', opts)
EOF

nmap <C-t> <CMD>lua require("FTerm").toggle()<CR>
tmap <C-t> <C-\><C-n> <CMD>lua require("FTerm").toggle()<CR>
nnoremap <C-n> :NvimTreeToggle<CR>
nnoremap <leader>r :NvimTreeRefresh<CR>
nnoremap <leader>n :NvimTreeFindFile<CR>

autocmd BufEnter * set cindent

inoremap { {}<Left>
inoremap {<CR> {<CR>}<Esc>O<space><BS>
inoremap {{ {
inoremap {} {}
inoremap <Esc> <space><BS><Esc>
