/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   row.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:18:18 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 21:53:53 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

static t_row	*new_row(char *line)
{
	t_row		*new;

	new = (t_row *)malloc(sizeof(t_row));
	new->prev = NULL;
	new->line = line;
	new->length = ft_strlen(line);
	new->next = NULL;
	return (new);
}

void			add_row(char *line)
{
	t_row		*to_add;
	t_row		*curr;

	to_add = new_row(line);
	if (!g_config.row)
		g_config.row = to_add;
	else
	{
		curr = g_config.row;
		while (curr && curr->next)
			curr = curr->next;
		curr->next = to_add;
		to_add->prev = curr->next;
	}
	g_config.row_count++;
}
