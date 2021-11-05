:autocmd VimResized * wincmd =

let mapleader=" "
inoremap <Esc> <space><BS><Esc>

call plug#begin()
Plug 'sainnhe/gruvbox-material'
Plug 'tomasiser/vim-code-dark'
Plug 'ludovicchabant/vim-gutentags'
Plug 'hrsh7th/vim-vsnip'
Plug 'nvim-treesitter/nvim-treesitter', {'do': ':TSUpdate'}
Plug 'neovim/nvim-lspconfig'
Plug 'norcalli/nvim-colorizer.lua'
Plug 'glepnir/lspsaga.nvim'
Plug 'onsails/lspkind-nvim'
Plug 'rstacruz/vim-closer'

Plug 'scrooloose/nerdcommenter'
Plug 'reedes/vim-pencil'
Plug 'kyazdani42/nvim-web-devicons'
Plug 'hrsh7th/nvim-cmp'
Plug 'akinsho/nvim-bufferline.lua'
Plug 'numToStr/FTerm.nvim'

Plug 'hrsh7th/cmp-nvim-lsp'
Plug 'hrsh7th/cmp-buffer'
Plug 'hrsh7th/cmp-path'
Plug 'hrsh7th/cmp-cmdline'

Plug 'hrsh7th/cmp-vsnip'
call plug#end()

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
set backspace=indent,eol,start termguicolors softtabstop=4 shiftwidth=4 tabstop=4 expandtab number relativenumber ruler showcmd scrolloff=35 splitright splitbelow title nojoinspaces mouse=a signcolumn=yes encoding=UTF-8 background=dark
colo gruvbox-material
syntax on
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

command! -nargs=0 CompileAndRunWithFlags call TermWrapper(printf('g++ -H -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 %s -o ~/./a.out && ~/./a.out', expand('%:p')))
command! -nargs=0 Run call TermWrapper(printf('~/./a.out'))

autocmd FileType cpp nnoremap gc :w <bar> :CompileAndRunWithFlags<CR>
autocmd FileType cpp nnoremap gr :w <bar> :Run<CR>

let bufferline = get(g:, 'bufferline', {})

lua <<EOF
  -- Setup nvim-cmp.
  local cmp = require'cmp'

  cmp.setup({
    snippet = {
      -- REQUIRED - you must specify a snippet engine
      expand = function(args)
        vim.fn["vsnip#anonymous"](args.body) -- For `vsnip` users.
        -- require('luasnip').lsp_expand(args.body) -- For `luasnip` users.
        -- vim.fn["UltiSnips#Anon"](args.body) -- For `ultisnips` users.
        -- require'snippy'.expand_snippet(args.body) -- For `snippy` users.
      end,
    },
    mapping = {
      ['<C-d>'] = cmp.mapping(cmp.mapping.scroll_docs(-4), { 'i', 'c' }),
      ['<C-f>'] = cmp.mapping(cmp.mapping.scroll_docs(4), { 'i', 'c' }),
      ['<C-Space>'] = cmp.mapping(cmp.mapping.complete(), { 'i', 'c' }),
      ['<C-y>'] = cmp.config.disable, -- Specify `cmp.config.disable` if you want to remove the default `<C-y>` mapping.
      ['<C-e>'] = cmp.mapping({
        i = cmp.mapping.abort(),
        c = cmp.mapping.close(),
      }),
      ['<CR>'] = cmp.mapping.confirm({ select = true }),
    },
    sources = cmp.config.sources({
      { name = 'nvim_lsp' },
      { name = 'vsnip' }, -- For vsnip users.
      -- { name = 'luasnip' }, -- For luasnip users.
      -- { name = 'ultisnips' }, -- For ultisnips users.
      -- { name = 'snippy' }, -- For snippy users.
    }, {
      { name = 'buffer' },
    })
  })

  -- Use buffer source for `/` (if you enabled `native_menu`, this won't work anymore).
  cmp.setup.cmdline('/', {
    sources = {
      { name = 'buffer' }
    }
  })

  -- Use cmdline & path source for ':' (if you enabled `native_menu`, this won't work anymore).
  cmp.setup.cmdline(':', {
    sources = cmp.config.sources({
      { name = 'path' }
    }, {
      { name = 'cmdline' }
    })
  })

  -- Setup lspconfig.
  local capabilities = require('cmp_nvim_lsp').update_capabilities(vim.lsp.protocol.make_client_capabilities())
  -- Replace <YOUR_LSP_SERVER> with each lsp server you've enabled.
  require('lspconfig')['clangd'].setup {
    capabilities = capabilities
  }

    local lspkind = require('lspkind')
    cmp.setup {
      formatting = {
        format = lspkind.cmp_format({with_text = false, maxwidth = 50})
      }
    }
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
