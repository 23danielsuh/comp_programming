local wezterm = require 'wezterm';
return {
	default_prog = {"wsl"},
	font = wezterm.font("Hack Nerd Font"),
	default_cwd = "\\\\wsl$\\Ubuntu\\home\\danielsuh",
	color_scheme = "Builtin Solarized Light",
	enable_tab_bar = false,
	window_padding = {
		left = 4,
		right = 0, 
		top = 0,
		bottom = 0
	}
}
