/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:42:38 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/14 17:49:42 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void	refresh_screen(void)
{
	ft_putstr(tgetstr("ho", NULL));
	ft_clear_screen();
	if (g_config.screen_data.data)
		ft_strdel(&g_config.screen_data.data);
	draw_rows();
	ft_putstr(tgetstr("vi", NULL));
	write(1, g_config.screen_data.data, g_config.screen_data.len);
	ft_putstr(tgetstr("ve", NULL));
	move_cursor();
}
