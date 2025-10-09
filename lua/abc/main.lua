-- xNix #!/usr/local/bin/lua
-- Window #!/

local name = "LazyVim User"

if pcall(require, "vim") then
	vim.notify("Welcome, " .. name .. "!", vim.log.levels.INFO)
else
	print("[I]" .. "Welcome, " .. name .. "!")
end
