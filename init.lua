vim.g.mapleader = ' '
vim.g.maplocalleader = ' '
vim.g.have_nerd_font = false

-- OPTIONS --
vim.opt.number = true
vim.opt.relativenumber = true
vim.opt.showmode = true
vim.opt.breakindent = true
vim.opt.undofile = true
vim.opt.cursorline = true
vim.opt.scrolloff = 10
vim.opt.wrap = true
vim.opt.eb = false
vim.opt.shiftwidth = 4
vim.opt.syn = 'on'

-- KEYMAPS --

vim.keymap.set('n', 'j', 'gj')
vim.keymap.set('n', 'k', 'gk')

vim.keymap.set('n', '<Esc>', '<cmd>nohlsearch<CR>')
vim.keymap.set('n', '<leader>w', '<cmd>w<CR>')
vim.keymap.set('n', '<leader>q', '<cmd>q<CR>')
vim.keymap.set('n', '<leader>ai', '=G')
vim.keymap.set('n', '<leader>l', ':')
vim.keymap.set('n', '<leader>r', ':%s/')
vim.keymap.set('n', '<leader>y', '"+y')
vim.keymap.set('n', ';', '%')

vim.keymap.set('n', '<leader>e', '<cmd>Neotree filesystem reveal left<CR>')

-- AUTOCMDS --

vim.api.nvim_create_autocmd('TextYankPost', {
    desc = 'Highlight when yanking (copying) text',
    group = vim.api.nvim_create_augroup('kickstart-highlight-yank', { clear = true }),
    callback = function()
	vim.highlight.on_yank()
    end,
})

-- LAZY PACKAGE MANAGER --

local lazypath = vim.fn.stdpath("data") .. "/lazy/lazy.nvim"
if not (vim.uv or vim.loop).fs_stat(lazypath) then
    local lazyrepo = "https://github.com/folke/lazy.nvim.git"
    local out = vim.fn.system({ "git", "clone", "--filter=blob:none", "--branch=stable", lazyrepo, lazypath })
    if vim.v.shell_error ~= 0 then
	vim.api.nvim_echo({
	    { "Failed to clone lazy.nvim:\n", "ErrorMsg" },
	    { out, "WarningMsg" },
	    { "\nPress any key to exit..." },
	}, true, {})
	vim.fn.getchar()
	os.exit(1)
    end
end
vim.opt.rtp:prepend(lazypath)

require("lazy").setup("plugins")

local builtin = require("telescope.builtin")
vim.keymap.set('n', '<leader>p', builtin.find_files, {})
vim.keymap.set('n', '<leader>fg', builtin.live_grep, {})

local config = require("nvim-treesitter.configs")
config.setup({
    ensure_installed = {"lua", "c", "python"},
    highlight = { enable = true },
    indent = { enable = false },
})

require("mason").setup()
require("mason-lspconfig").setup({
    ensure_installed = { "lua_ls", "clangd", "ruff" }
})

require("lspconfig").lua_ls.setup({})
require("lspconfig").clangd.setup({})
require("lspconfig").ruff.setup({})

vim.keymap.set('n', 'K', vim.lsp.buf.hover, {})
vim.keymap.set('n', 'gd', vim.lsp.buf.definition, {})
vim.keymap.set('n', '<leader>ca', vim.lsp.buf.code_action, {})

vim.cmd[[colorscheme tokyodark]]
