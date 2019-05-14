/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:16:46 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 22:11:28 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cribby.h"

static void		reset(void)
{
	reset_default_terminal();
	ft_clear_screen();
}

static void		init_editor(void)
{
	g_config.row = NULL;
	g_config.row_count = 0;
	g_config.screen_data.data = NULL;
	g_config.screen_data.len = 0;
	ft_clear_screen();
	update_winsize();
	update_cursor_pos();
	atexit(reset);
}

int				main(void)
{
	if (!term_check())
		return (0);
	enable_raw_terminal();
	init_editor();
	/*
	 * USE THIS TO BUFFERIZE A FILE LINE BY LINE
	*/
	//add_row("Test Row");
	refresh_screen();
	input_loop();
	return (0);
}
