/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rows.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:33:05 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 22:06:55 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		buffer_append(char *to_append, int length)
{
	char	*temp;

	if (!g_config.screen_data.data)
	{
		g_config.screen_data.data = ft_strdup(to_append);
		g_config.screen_data.len = length;
	}
	else
	{
		temp = ft_strnew(g_config.screen_data.len + length);
		ft_strcpy(temp, g_config.screen_data.data);
		ft_strncat(temp, to_append, length);
		free(g_config.screen_data.data);
		g_config.screen_data.data = temp;
		g_config.screen_data.len += length;
	}

}

void		draw_rows(void)
{
	t_row		*curr;

	curr = g_config.row;
	for (int i = 0; i < g_config.window.ws_row; i++)
	{
		if (i < g_config.row_count && curr)
		{
			buffer_append(curr->line, curr->length);
			buffer_append("\n", 1);
			curr = curr->next;
		}
		else if (i == g_config.window.ws_row / 3 && !g_config.row_count)
			buffer_append("Hello, World\n", 14);
		else if (i + 1 < g_config.window.ws_row)
			buffer_append("~\n", 2);
		else
			buffer_append("~", 1);
	}
}
