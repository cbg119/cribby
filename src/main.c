/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:16:46 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/14 17:55:15 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cribby.h"

static void		reset(void)
{
	reset_default_terminal();
	ft_putstr(tgetstr("te", NULL));
}

static void		init_editor(void)
{
	g_config.row_offset = 0;
	g_config.row = NULL;
	g_config.row_count = 0;
	g_config.screen_data.data = NULL;
	g_config.screen_data.len = 0;
	ft_putstr(tgetstr("ti", NULL));
	ft_clear_screen();
	update_winsize();
	update_cursor_pos();
	atexit(reset);
}

int				main(int argc, char *argv[])
{
	if (!term_check())
		return (0);
	enable_raw_terminal();
	init_editor();
	if (argc > 2)
		cribby_error("Too many arguments!");
	else if (argc == 2)
		load_file(argv[1]);
	refresh_screen();
	input_loop();
	ft_putstr(tgetstr("te", NULL));
	return (0);
}
