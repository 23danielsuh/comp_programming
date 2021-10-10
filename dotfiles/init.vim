:autocmd VimResized * wincmd =

let mapleader=" "
inoremap <Esc> <space><BS><Esc>

call plug#begin()
Plug 'sainnhe/gruvbox-material'
Plug 'ludovicchabant/vim-gutentags'
Plug 'lervag/vimtex'
Plug 'hrsh7th/vim-vsnip'
Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
Plug 'overcache/NeoSolarized'
Plug 'neovim/nvim-lspconfig'
Plug 'norcalli/nvim-colorizer.lua'
Plug 'kabouzeid/nvim-lspinstall'
Plug 'glepnir/lspsaga.nvim'
Plug 'onsails/lspkind-nvim'
Plug 'romgrk/todoist.nvim', { 'do': ':TodoistInstall' }
Plug 'nvim-lua/plenary.nvim'

Plug 'scrooloose/nerdcommenter'
Plug 'reedes/vim-pencil'
Plug 'hrsh7th/nvim-compe'
Plug 'kyazdani42/nvim-web-devicons'
Plug 'akinsho/nvim-bufferline.lua'
Plug 'numToStr/FTerm.nvim'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'windwp/nvim-autopairs'
Plug 'airblade/vim-gitgutter'
Plug 'tpope/vim-fugitive'
call plug#end()

let g:airline_powerline_fonts=1
let g:vimtex_view_general_viewer = 'evince'
    
nnoremap <silent>rn :Lspsaga rename<CR>

set completeopt=menuone,noselect

nnoremap <silent> ]e :Lspsaga diagnostic_jump_next<CR>
nnoremap <silent> [e :Lspsaga diagnostic_jump_prev<CR>

syntax on
filetype plugin indent on

autocmd BufNewFile *.cpp 0r ~/comp_programming/code/template.cpp
autocmd BufEnter * :SoftPencil

"set clipboard=unnamedplus
nnoremap  <silent>   <tab>  :if &modifiable && !&readonly && &modified <CR> :write<CR> :endif<CR>:bnext<CR>
nnoremap  <silent> <s-tab>  :if &modifiable && !&readonly && &modified <CR> :write<CR> :endif<CR>:bprevious<CR>
set backspace=indent,eol,start termguicolors softtabstop=4 shiftwidth=4 tabstop=4 expandtab number relativenumber ruler showcmd scrolloff=35 splitright splitbelow title nojoinspaces mouse=a background=light signcolumn=yes encoding=UTF-8
colo NeoSolarized
set shortmess+=c
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

command! -nargs=0 CompileAndRunWithFlags call TermWrapper(printf('g++ -H -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 %s -o ~/./a.out && ~/./a.out', expand('%:p')))
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
    require'nvim-treesitter.configs'.setup {
      ensure_installed = "maintained", -- one of "all", "maintained" (parsers with maintainers), or a list of languages
      ignore_install = { "javascript" }, -- List of parsers to ignore installing
      highlight = {
        enable = true,              -- false will disable the whole extension
        -- Setting this to true will run `:h syntax` and tree-sitter at the same time.
        -- Set this to `true` if you depend on 'syntax' being enabled (like for indentation).
        -- Using this option may slow down your editor, and you may see some duplicate highlights.
        -- Instead of true it can also be a list of languages
        additional_vim_regex_highlighting = false,
      },
      indent = {
          enable = false
      },
    }
    require'lspinstall'.setup() -- important

    local servers = require'lspinstall'.installed_servers()
    for _, server in pairs(servers) do
      require'lspconfig'[server].setup{}
    end
    local capabilities = vim.lsp.protocol.make_client_capabilities()
    capabilities.textDocument.completion.completionItem.snippetSupport = true
    capabilities.textDocument.completion.completionItem.resolveSupport = {
      properties = {
        'documentation',
        'detail',
        'additionalTextEdits',
      }
    }
    require'lspconfig'.clangd.setup {
        cmd = { "clangd", "--background-index", "--header-insertion=never"},
        capabilities = capabilities,
    }
    vim.lsp.handlers["textDocument/publishDiagnostics"] = vim.lsp.with(
      vim.lsp.diagnostic.on_publish_diagnostics, {
        update_in_insert = true,
      }
    )
    require'colorizer'.setup()
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

    local map = vim.api.nvim_set_keymap
    local opts = { noremap = true, silent = true }

    map('n', '<A-i>', '<CMD>lua require("FTerm").toggle()<CR>', opts)
    map('t', '<A-i>', '<C-\\><C-n><CMD>lua require("FTerm").toggle()<CR>', opts)

    require('compe').setup {
      enabled = true,
      autocomplete = true,
      documentation = true,

      source = {
        path = true,
        vsnip = true,
        buffer = true,
        nvim_lsp = true,
      }
    }

    require('nvim-autopairs').setup({
      disable_filetype = { "TelescopePrompt" , "vim" },
      enable_check_bracket_line = true,
    })

    require("nvim-autopairs.completion.compe").setup({
      map_cr = true, --  map <CR> on insert mode
      map_complete = true -- it will auto insert `(` after select function or method item
    })

    --- Auto-space rules
    local npairs = require'nvim-autopairs'
    local Rule   = require'nvim-autopairs.rule'

    npairs.add_rules {
      Rule(' ', ' ')
        :with_pair(function (opts)
          local pair = opts.line:sub(opts.col, opts.col + 1)
          return vim.tbl_contains({ '()', '[]', '{}' }, pair)
        end),
    }
EOF

nmap <C-t> <CMD>lua require("FTerm").toggle()<CR>
tmap <C-t> <C-\><C-n> <CMD>lua require("FTerm").toggle()<CR>

autocmd BufEnter * set cindent

imap <expr> <C-j>   vsnip#expandable()  ? '<Plug>(vsnip-expand)'         : '<C-j>'
smap <expr> <C-j>   vsnip#expandable()  ? '<Plug>(vsnip-expand)'         : '<C-j>'

imap <expr> <C-l>   vsnip#available(1)  ? '<Plug>(vsnip-expand-or-jump)' : '<C-l>'
smap <expr> <C-l>   vsnip#available(1)  ? '<Plug>(vsnip-expand-or-jump)' : '<C-l>'

imap <expr> <Tab>   vsnip#jumpable(1)   ? '<Plug>(vsnip-jump-next)'      : '<Tab>'
smap <expr> <Tab>   vsnip#jumpable(1)   ? '<Plug>(vsnip-jump-next)'      : '<Tab>'
imap <expr> <S-Tab> vsnip#jumpable(-1)  ? '<Plug>(vsnip-jump-prev)'      : '<S-Tab>'
smap <expr> <S-Tab> vsnip#jumpable(-1)  ? '<Plug>(vsnip-jump-prev)'      : '<S-Tab>'

nmap        s   <Plug>(vsnip-select-text)
xmap        s   <Plug>(vsnip-select-text)
nmap        S   <Plug>(vsnip-cut-text)
xmap        S   <Plug>(vsnip-cut-text)

let g:vsnip_filetypes = {}
let g:vsnip_filetypes.javascriptreact = ['javascript']
let g:vsnip_filetypes.typescriptreact = ['typescript']
