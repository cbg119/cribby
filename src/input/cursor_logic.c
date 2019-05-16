/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor_logic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 21:36:02 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/15 22:55:59 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

void		move_up(void)
{
	if (g_config.cursor.row + g_config.row_offset > 1)
	{
		if (g_config.cursor.row == 1)
		{
			g_config.row_offset--;
			refresh_screen();
		}
		else
			g_config.cursor.row--;
	}
}

void		move_down(void)
{
	if (g_config.cursor.row + g_config.row_offset < g_config.row_count)
	{
		if (g_config.cursor.row == g_config.window.ws_row)
		{
			g_config.row_offset++;
			refresh_screen();
		}
		else
			g_config.cursor.row++;
	}
}

void		move_left(void)
{
	if (g_config.cursor.col == 1 && g_config.col_offset > 0)
	{
		g_config.col_offset--;
		refresh_screen();
	}
	else if (g_config.cursor.col > 1)
	{
		g_config.cursor.col--;
		move_cursor();
	}
}

void		move_right(void)
{
	int			i;
	t_row		*curr;

	i = -1;
	curr = g_config.row;
	while (++i < g_config.cursor.row + g_config.row_offset - 1)
		curr = curr->next;
	if (g_config.cursor.col == g_config.window.ws_col)
	{
		if (g_config.cursor.col + g_config.col_offset < curr->length)
		{
			g_config.col_offset++;
			refresh_screen();
		}
	}
	else if (g_config.cursor.col < curr->length)
	{
		g_config.cursor.col++;
		move_cursor();
	}
}
