/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:42:38 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 20:01:58 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	refresh_screen(void)
{
	ft_clear_screen();
	draw_rows();
	ft_putstr(tgetstr("vi", NULL));
	write(1, g_config.screen_data.data, g_config.screen_data.len);
	ft_putstr(tgetstr("ve", NULL));
	if (g_config.screen_data.data)
		free(g_config.screen_data.data);
	move_cursor();
}
