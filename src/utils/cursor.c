/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:54:09 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 20:06:10 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void		update_cursor_pos(void)
{
	int			i;
	char		pos[20];

	ft_bzero(pos, 20);
	ft_putstr_fd("\e[6n", 0);
	i = read(0, pos, 20);
	pos[i] = 0;
	i = 2;
	g_config.cursor.row = ft_atoi(pos + i);
	while (IS_DIGIT(pos[i]))
		i++;
	g_config.cursor.col = ft_atoi(pos + i + 1);
}

void		move_cursor(void)
{
	ft_putstr(tgoto(tgetstr("cm", NULL), g_config.cursor.col - 1,
	g_config.cursor.row - 1));
}
