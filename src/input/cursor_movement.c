/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:27:54 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/14 16:55:57 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static void			match_movement_key(unsigned long key)
{
	if (key == K_UP && g_config.cursor.row + g_config.row_offset > 1)
	{
		if (g_config.cursor.row == 1)
		{
			g_config.row_offset--;
			refresh_screen();
		}
		else
			g_config.cursor.row--;
	}
	else if (key == K_DOWN &&
	g_config.cursor.row + g_config.row_offset < g_config.row_count)
	{
		if (g_config.cursor.row == g_config.window.ws_row)
		{
			g_config.row_offset++;
			refresh_screen();
		}
		else
			g_config.cursor.row++;
	}
	else if (key == K_LEFT && g_config.cursor.col > 1)
		g_config.cursor.col--;
	else if (key == K_RIGHT && g_config.cursor.col < g_config.window.ws_col)
		g_config.cursor.col++;
	move_cursor();
}

void				input_loop(void)
{
	unsigned long	key;

	key = 0;
	while (1)
	{
		key = ft_getch();
		if (key == K_END)
			break ;
		else if (key == K_ENTER)
			refresh_screen();
		else
			match_movement_key(key);
	}
}
