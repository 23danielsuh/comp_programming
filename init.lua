local install_path = vim.fn.stdpath 'data' .. '/site/pack/packer/start/packer.nvim'

if vim.fn.empty(vim.fn.glob(install_path)) > 0 then
vim.fn.execute('!git clone https://github.com/wbthomason/packer.nvim ' .. install_path)
end

require('packer').startup(function(use)
use { 'windwp/nvim-ts-autotag' }
use('jose-elias-alvarez/null-ls.nvim')
use('MunifTanjim/prettier.nvim')
use { 'lewis6991/gitsigns.nvim' }
use { "sainnhe/gruvbox-material" }
use { "ellisonleao/gruvbox.nvim" }
use({
	"glepnir/lspsaga.nvim",
	branch = "main",
	config = function()
		local saga = require("lspsaga")

		saga.init_lsp_saga({
			-- your configuration
		})
	end,
})
use { "akinsho/toggleterm.nvim", tag = '*', config = function()
	require("toggleterm").setup()
end }
use {
	"ray-x/lsp_signature.nvim",
}
use {
	'nvim-lualine/lualine.nvim',
	requires = { 'nvim-tree/nvim-web-devicons', opt = true }
}
use 'seandewar/killersheep.nvim'
use {
	'm-demare/hlargs.nvim',
	requires = { 'nvim-treesitter/nvim-treesitter' }
}
use { "catppuccin/nvim", as = "catppuccin"
}
use {
	"windwp/nvim-autopairs",
	config = function() require("nvim-autopairs").setup {} end
}
use "lukas-reineke/indent-blankline.nvim"
use "seandewar/nvimesweeper"
use { 'edluffy/specs.nvim' }
use { 'nvim-treesitter/nvim-treesitter' }
use 'wbthomason/packer.nvim'
use {
	'numToStr/Comment.nvim',
	config = function()
		require('Comment').setup()
	end
}
use {
	'kyazdani42/nvim-tree.lua',
	requires = {
		'kyazdani42/nvim-web-devicons', -- optional, for file icons
	},
}
use { 'sindrets/diffview.nvim', requires = 'nvim-lua/plenary.nvim' }
use 'ThePrimeagen/vim-be-good'
use 'alec-gibson/nvim-tetris'
use {
	"williamboman/mason.nvim",
	"williamboman/mason-lspconfig.nvim",
	"neovim/nvim-lspconfig",
}
use { 'lifepillar/vim-gruvbox8' }
use {
	"max397574/better-escape.nvim",
	config = function()
		require("better_escape").setup()
	end,
}
use { 'akinsho/git-conflict.nvim', tag = "*", config = function()
	require('git-conflict').setup()
end }
use {
	'romgrk/barbar.nvim',
	requires = { 'kyazdani42/nvim-web-devicons' }
}
use {
	'kyazdani42/nvim-web-devicons'
}
use { 'rcarriga/nvim-notify' }
use {
	'hrsh7th/cmp-nvim-lsp',
	'hrsh7th/cmp-buffer',
	'hrsh7th/cmp-path',
	'hrsh7th/cmp-cmdline',
	'hrsh7th/nvim-cmp',
	'hrsh7th/cmp-vsnip',
	'hrsh7th/vim-vsnip',
}
use {
	'nvim-telescope/telescope.nvim', tag = '0.1.0',
	-- or                            , branch = '0.1.x',
	requires = { { 'nvim-lua/plenary.nvim' } }
}

use 'ggandor/leap.nvim'
use 'luisiacc/gruvbox-baby'

end)

require('nvim-ts-autotag').setup()
require('gitsigns').setup()

vim.cmd [[
let mapleader=" "
]]


local keymap = vim.keymap.set
local saga = require('lspsaga')

saga.init_lsp_saga(
{
	code_action_icon = "💡",
}
)

-- Lsp finder find the symbol definition implement reference
-- if there is no implement it will hide
-- when you use action in finder like open vsplit then you can
-- use <C-t> to jump back
keymap("n", "gh", "<cmd>Lspsaga lsp_finder<CR>", { silent = true })

-- Code action
keymap({ "n", "v" }, "<leader>ca", "<cmd>Lspsaga code_action<CR>", { silent = true })

-- Rename
keymap("n", "<leader>rn", "<cmd>Lspsaga rename<CR>", { silent = true })

-- Peek Definition
-- you can edit the definition file in this flaotwindow
-- also support open/vsplit/etc operation check definition_action_keys
-- support tagstack C-t jump back
keymap("n", "gd", "<cmd>Lspsaga peek_definition<CR>", { silent = true })

-- Show line diagnostics
keymap("n", "<leader>cd", "<cmd>Lspsaga show_line_diagnostics<CR>", { silent = true })

-- Show cursor diagnostic
keymap("n", "<leader>cd", "<cmd>Lspsaga show_cursor_diagnostics<CR>", { silent = true })

-- Diagnsotic jump can use `<c-o>` to jump back
keymap("n", "[e", "<cmd>Lspsaga diagnostic_jump_prev<CR>", { silent = true })
keymap("n", "]e", "<cmd>Lspsaga diagnostic_jump_next<CR>", { silent = true })

-- Only jump to error
keymap("n", "[E", function()
require("lspsaga.diagnostic").goto_prev({ severity = vim.diagnostic.severity.ERROR })
end, { silent = true })
keymap("n", "]E", function()
require("lspsaga.diagnostic").goto_next({ severity = vim.diagnostic.severity.ERROR })
end, { silent = true })

-- Outline
keymap("n", "<leader>o", "<cmd>LSoutlineToggle<CR>", { silent = true })

-- Hover Doc
keymap("n", "K", "<cmd>Lspsaga hover_doc<CR>", { silent = true })

-- Float terminal
keymap("n", "<A-d>", "<cmd>Lspsaga open_floaterm<CR>", { silent = true })
-- if you want pass somc cli command into terminal you can do like this
-- open lazygit in lspsaga float terminal
keymap("n", "<A-d>", "<cmd>Lspsaga open_floaterm lazygit<CR>", { silent = true })
-- close floaterm
keymap("t", "<A-d>", [[<C-\><C-n><cmd>Lspsaga close_floaterm<CR>]], { silent = true })

require('leap').set_default_keymaps()

require('lualine').setup()

vim.opt.list = true
vim.opt.listchars:append "space:⋅"
vim.opt.listchars:append "eol:↴"

cfg = {
hint_prefix = "🫠 ", -- Panda for parameter, NOTE: for the terminal not support emoji, might crash
}
require "lsp_signature".setup(cfg)
require("nvim-treesitter.configs").setup({ highlight = { enable = true } })

require("indent_blankline").setup {
space_char_blankline = " ",
show_current_context = true,
show_current_context_start = true,
}

vim.g.loaded = 1
vim.g.loaded_netrwPlugin = 1

-- empty setup using defaults
require("nvim-tree").setup()

require('Comment').setup()

require("better_escape").setup {
mapping = { "jk", "jj" }, -- a table with mappings to use
timeout = vim.o.timeoutlen, -- the time in which the keys must be hit in ms. Use option timeoutlen by default
clear_empty_lines = false, -- clear line after escaping if there is only whitespace
keys = "<Esc>", -- keys used for escaping, if it is a function will use the result everytime
-- example(recommended)
-- keys = function()
--   return vim.api.nvim_win_get_cursor(0)[2] > 1 and '<esc>l' or '<esc>'
-- end,
}

vim.api.nvim_create_user_command("DiffviewToggle", function(e)
local view = require("diffview.lib").get_current_view()

if view then
	vim.cmd("DiffviewClose")
else
	vim.cmd("DiffviewOpen " .. e.args)
end
end, { nargs = "*" })

vim.cmd [[
nnoremap <leader>f <cmd>lua require('telescope.builtin').find_files()<cr>
nnoremap <leader>n <cmd>NvimTreeToggle<cr>
nnoremap <leader>g <cmd>lua require('telescope.builtin').live_grep()<cr>
nnoremap <leader>b <cmd>lua require('telescope.builtin').buffers()<cr>
nnoremap <leader>ht <cmd>lua require('telescope.builtin').help_tags()<cr>
nnoremap <leader>D <cmd>DiffviewToggle<cr>
set completeopt=menu,menuone,noselect
]]

require("mason").setup()
require("mason-lspconfig").setup()

-- Mappings.
-- See `:help vim.diagnostic.*` for documentation on any of the below functions
local opts = { noremap = true, silent = true }
-- vim.keymap.set('n', '<space>e', vim.diagnostic.open_float, opts)
-- vim.keymap.set('n', '[e', vim.diagnostic.goto_prev, opts)
-- vim.keymap.set('n', ']e', vim.diagnostic.goto_next, opts)
-- vim.keymap.set('n', '<space>q', vim.diagnostic.setloclist, opts)

-- Use an on_attach function to only map the following keys
-- after the language server attaches to the current buffer
local on_attach = function(client, bufnr)
-- Enable completion triggered by <c-x><c-o>
vim.api.nvim_buf_set_option(bufnr, 'omnifunc', 'v:lua.vim.lsp.omnifunc')

-- Mappings.
-- See `:help vim.lsp.*` for documentation on any of the below functions
-- local bufopts = { noremap = true, silent = true, buffer = bufnr }
-- vim.keymap.set('n', 'gD', vim.lsp.buf.declaration, bufopts)
-- vim.keymap.set('n', 'gd', vim.lsp.buf.definition, bufopts)
-- vim.keymap.set('n', 'K', vim.lsp.buf.hover, bufopts)
-- vim.keymap.set('n', 'gi', vim.lsp.buf.implementation, bufopts)
-- vim.keymap.set('n', '<C-k>', vim.lsp.buf.signature_help, bufopts)
-- vim.keymap.set('n', '<space>wa', vim.lsp.buf.add_workspace_folder, bufopts)
-- vim.keymap.set('n', '<space>wr', vim.lsp.buf.remove_workspace_folder, bufopts)
-- vim.keymap.set('n', '<space>wl', function()
-- 	print(vim.inspect(vim.lsp.buf.list_workspace_folders()))
-- end, bufopts)
-- vim.keymap.set('n', '<space>D', vim.lsp.buf.type_definition, bufopts)
-- vim.keymap.set('n', '<space>rn', vim.lsp.buf.rename, bufopts)
-- vim.keymap.set('n', '<space>ca', vim.lsp.buf.code_action, bufopts)
-- vim.keymap.set('n', 'gr', vim.lsp.buf.references, bufopts)
-- vim.keymap.set('n', '<leader>cf', function() vim.lsp.buf.format { async = true } end, bufopts)
end

local lsp_flags = {
-- This is the default in Nvim 0.7+
debounce_text_changes = 150,
}

local has_words_before = function()
local line, col = unpack(vim.api.nvim_win_get_cursor(0))
return col ~= 0 and vim.api.nvim_buf_get_lines(0, line - 1, line, true)[1]:sub(col, col):match("%s") == nil
end

local feedkey = function(key, mode)
vim.api.nvim_feedkeys(vim.api.nvim_replace_termcodes(key, true, true, true), mode, true)
end

local cmp = require 'cmp'

cmp.setup({
snippet = {
	-- REQUIRED - you must specify a snippet engine
	expand = function(args)
		vim.fn["vsnip#anonymous"](args.body) -- For `vsnip` users.
		-- require('luasnip').lsp_expand(args.body) -- For `luasnip` users.
		-- require('snippy').expand_snippet(args.body) -- For `snippy` users.
		-- vim.fn["UltiSnips#Anon"](args.body) -- For `ultisnips` users.
	end,
},
window = {
	-- completion = cmp.config.window.bordered(),
	-- documentation = cmp.config.window.bordered(),
},
mapping = cmp.mapping.preset.insert({

	['<C-b>'] = cmp.mapping.scroll_docs(-4),
	['<C-f>'] = cmp.mapping.scroll_docs(4),
	['<C-Space>'] = cmp.mapping.complete(),
	['<C-e>'] = cmp.mapping.abort(),
	['<CR>'] = cmp.mapping.confirm({ select = false }), -- Accept currently selected item. Set `select` to `false` to only confirm explicitly selected items.
	["<Tab>"] = cmp.mapping(function(fallback)
		if cmp.visible() then
			feedkey("<Plug>(vsnip-expand-or-jump)", "")
		elseif vim.fn["vsnip#available"](1) == 1 then
			feedkey("<Plug>(vsnip-expand-or-jump)", "")
		elseif has_words_before() then
			cmp.complete()
		else
			fallback() -- The fallback function sends a already mapped key. In this case, it's probably `<Tab>`.
		end
	end, { "i", "s" }),

	["<S-Tab>"] = cmp.mapping(function()
		if cmp.visible() then
			feedkey("<Plug>(vsnip-expand-or-jump)", "")
		elseif vim.fn["vsnip#jumpable"](-1) == 1 then
			feedkey("<Plug>(vsnip-jump-prev)", "")
		end
	end, { "i", "s" }),
}),
sources = cmp.config.sources({
	{ name = 'nvim_lsp' },
	{ name = 'nvim_lsp_signature_help' },
	{ name = 'vsnip' }, -- For vsnip users.
	{ name = 'path' },
	-- { name = 'luasnip' }, -- For luasnip users.
	-- { name = 'ultisnips' }, -- For ultisnips users.
	-- { name = 'snippy' }, -- For snippy users.
}, {
	{ name = 'buffer' },
})
})

-- Set configuration for specific filetype.
cmp.setup.filetype('gitcommit', {
sources = cmp.config.sources({
	{ name = 'cmp_git' }, -- You can specify the `cmp_git` source if you were installed it.
}, {
	{ name = 'buffer' },
})
})

cmp.setup.cmdline({ '/', '?' }, {
mapping = cmp.mapping.preset.cmdline(),
sources = {
	{ name = 'buffer' }
}
})


-- Use buffer source for `/` and `?` (if you enabled `native_menu`, this won't work anymore).
--for _,v in pairs({ '/', '?' })
--cmp.setup.cmdline(v, {
--  mapping = cmp.mapping.preset.cmdline(),
--  sources = {
--	{ name = 'buffer' }
--  }
--})
--end
--
-- Use cmdline & path source for ':' (if you enabled `native_menu`, this won't work anymore).
cmp.setup.cmdline(':', {
mapping = cmp.mapping.preset.cmdline(),
sources = cmp.config.sources({
	{ name = 'path' }
}, {
	{ name = 'cmdline' }
})
})

local capabilities = require('cmp_nvim_lsp').default_capabilities(vim.lsp.protocol.make_client_capabilities())

require('lspconfig')['pyright'].setup {
on_attach = on_attach,
capabilities = capabilities,
flags = lsp_flags,
}

require('lspconfig')['emmet_ls'].setup {
on_attach = on_attach,
capabilities = capabilities,
flags = lsp_flags,
}
require('lspconfig')['clangd'].setup {
on_attach = on_attach,
capabilities = capabilities,
flags = lsp_flags,
}
require('lspconfig')['gopls'].setup {
on_attach = on_attach,
capabilities = capabilities,
flags = lsp_flags,
}
require('lspconfig')['jdtls'].setup {
on_attach = on_attach,
capabilities = capabilities,
flags = lsp_flags,
}
require('lspconfig')['cmake'].setup {
on_attach = on_attach,
capabilities = capabilities,
flags = lsp_flags,
}
require('lspconfig')['rust_analyzer'].setup {
on_attach = on_attach,
capabilities = capabilities,
flags = lsp_flags,
}
require('lspconfig')['sumneko_lua'].setup {
on_attach = on_attach,
capabilities = capabilities,
flags = lsp_flags,
}

-- If you want insert `(` after select function or method item
local cmp_autopairs = require('nvim-autopairs.completion.cmp')

cmp.event:on(
'confirm_done',
cmp_autopairs.on_confirm_done()
)

--Set highlight on search
vim.o.hlsearch = true

--Make line numbers default
vim.wo.number = true

--Enable mouse mode
vim.o.mouse = 'a'


local null_ls = require("null-ls")

local prettier = require("prettier")

prettier.setup({
bin = 'prettier', -- or `'prettierd'` (v0.22+)
filetypes = {
	"css",
	"graphql",
	"html",
	"javascript",
	"javascriptreact",
	"json",
	"less",
	"markdown",
	"scss",
	"typescript",
	"typescriptreact",
	"yaml",
},
})

null_ls.setup({
on_attach = function(client, bufnr)
	if client.server_capabilities.documentFormattingProvider then
		vim.cmd("nnoremap <silent><buffer> <leader>gf :lua vim.lsp.buf.formatting()<CR>")

		-- format on save
		vim.cmd("autocmd BufWritePost <buffer> lua vim.lsp.buf.formatting()")
	end

	if client.server_capabilities.documentRangeFormattingProvider then
		vim.cmd("xnoremap <silent><buffer> <leader>gf :lua vim.lsp.buf.range_formatting({})<CR>")
	end
end,
})


--Enable break indent
--vim.o.breakindent = true

--Save undo history
vim.opt.undofile = true

--Case insensitive searching UNLESS /C or capital in search
vim.o.ignorecase = true
vim.o.smartcase = true

--Decrease update time
vim.o.updatetime = 250
vim.wo.signcolumn = 'yes'


--Set colorscheme (order is important here)
vim.o.termguicolors = true
--Remap space as leader key

--Remap for dealing with word wrap
vim.api.nvim_set_keymap('n', 'k', "v:count == 0 ? 'gk' : 'k'", { noremap = true, expr = true, silent = true })
vim.api.nvim_set_keymap('n', 'j', "v:count == 0 ? 'gj' : 'j'", { noremap = true, expr = true, silent = true })
vim.api.nvim_set_keymap('n', 'Y', 'yy', { noremap = true, silent = true })

-- Highlight on yank
vim.cmd [[
augroup YankHighlight
	autocmd!
	autocmd TextYankPost * silent! lua vim.highlight.on_yank()
augroup end
]]

vim.cmd [[
colorscheme catppuccin
:autocmd VimResized * wincmd =
inoremap <Esc> <space><BS><Esc>
set sw=2 ts=2
nmap <C-h> <C-w>h
nmap <C-j> <C-w>j
nmap <C-k> <C-w>k
nmap <C-l> <C-w>l
nnoremap gA :%y+<CR>
nnoremap  <silent>   <tab>  <Cmd>BufferNext<CR>
nnoremap  <silent> <s-tab>  <Cmd>BufferPrevious<CR>
function! W()
	w
endfunction
command! W call W()
set encoding=utf-8
function! TermWrapper(command) abort
if !exists('g:split_term_style') | let g:split_term_style = 'vertical' | endif
if g:split_term_style ==# 'vertical'
	let buffercmd = 'botright vnew'
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
set relativenumber scrolloff=10
command! -nargs=0 CompileAndRunWithFlags call TermWrapper(printf('g++ -H -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -fsanitize=address -fsanitize=undefined -fno-sanitize-recover=all -fstack-protector -D_FORTIFY_SOURCE=2 %s -o ~/./a.out && ~/./a.out', expand('%:p')))
command! -nargs=0 CompileAndRunWithoutFlags call TermWrapper(printf('g++ -std=c++17 %s -o ~/./a.out && ~/./a.out', expand('%:p')))
command! -nargs=0 Run call TermWrapper(printf('~/./a.out'))
command! -nargs=0 CompilePython call TermWrapper(printf('python %s', expand('%:p')))
command! -nargs=0 CompileWithIdk call TermWrapper(printf('python %s', expand('%:p')))
autocmd FileType cpp nnoremap <leader>gc :w <bar> :CompileAndRunWithFlags<CR>
autocmd FileType cpp nnoremap <leader>gt :w <bar> :CompileAndRunWithoutFlags<CR>
" autocmd FileType cpp nnoremap <leader>gt :w <bar> :CompileWithIdk<CR>
" set
autocmd TermEnter term://*toggleterm#*
      \ tnoremap <silent><c-t> <Cmd>exe v:count1 . "ToggleTerm direction=float"<CR>

" By applying the mappings this way you can pass a count to your
" mapping to open a specific window.
" For example: 2<C-t> will open terminal 2
nnoremap <silent><c-t> <Cmd>exe v:count1 . "ToggleTerm direction=float"<CR>
inoremap <silent><c-t> <Esc><Cmd>exe v:count1 . "ToggleTerm direction=float"<CR>
]]

