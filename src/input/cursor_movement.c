/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 20:27:54 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/15 23:31:57 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

static void			match_movement_key(unsigned long key)
{
	if (key == K_UP)
		move_up();
	else if (key == K_DOWN)
		move_down();
	else if (key == K_LEFT)
		move_left();
	else if (key == K_RIGHT)
		move_right();
	move_cursor();
}

void				input_loop(void)
{
	unsigned long	key;

	key = 0;
	while (1)
	{
		key = ft_getch();
		if (key == 'q' || key == 'Q')
			break ;
		else if (key == K_HOME)
		{
			g_config.cursor.row = 1;
			g_config.row_offset = 0;
			refresh_screen();
			move_cursor();
		}
		else if (key == K_END)
		{
			if (g_config.row_count <= g_config.window.ws_row)
				g_config.cursor.row = g_config.row_count;
			else
			{
				g_config.cursor.row = g_config.window.ws_row;
				g_config.row_offset = g_config.row_count % g_config.window.ws_row;
			}
			refresh_screen();
			move_cursor();
		}
		else
			match_movement_key(key);
	}
}
