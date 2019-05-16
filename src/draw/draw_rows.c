/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:33:05 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/15 23:02:40 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void			buffer_append(char *to_append, int length)
{
	char	*temp;

	if (!g_config.screen_data.data)
	{
		g_config.screen_data.data = ft_strndup(to_append, length);
		g_config.screen_data.len = length;
	}
	else
	{
		temp = ft_strnjoin(g_config.screen_data.data, to_append, length);
		if (g_config.screen_data.data)
			free(g_config.screen_data.data);
		g_config.screen_data.data = temp;
		g_config.screen_data.len += length;
	}
}

static void		append_greeting(char *greeting)
{
	int		i;
	int		len;
	int		padding;

	len = ft_strlen(greeting);
	padding = (g_config.window.ws_col - len) / 2;
	i = 0;
	while (i < padding)
	{
		buffer_append(" ", 1);
		i++;
	}
	buffer_append(greeting, len);
	i = 0;
	while (i < padding)
	{
		buffer_append(" ", 1);
		i++;
	}
	buffer_append("\n", 1);
}

static void		append_tilde(int i)
{
	if (i + 1 < g_config.window.ws_row)
		buffer_append("~\n", 2);
	else
		buffer_append("~", 1);
}

void			draw_rows(void)
{
	int			i;
	t_row		*curr;

	i = -1;
	curr = g_config.row;
	while (++i < g_config.row_offset && curr)
		curr = curr->next;
	i = -1;
	while (++i < g_config.window.ws_row)
	{
		if (i < g_config.row_count && curr)
		{
			if (g_config.col_offset < curr->length)
				buffer_append((curr->line + g_config.col_offset),
				(curr->length - g_config.col_offset <= g_config.window.ws_col)
				? curr->length - g_config.col_offset : g_config.window.ws_col);
			if (i + 1 < g_config.window.ws_row)
				buffer_append("\n", 1);
			curr = curr->next;
		}
		else if (i == g_config.window.ws_row / 3 && !g_config.row_count)
			append_greeting("cribby - v1.0");
		else if (i + 1 < g_config.window.ws_row)
			append_tilde(i);
	}
}
