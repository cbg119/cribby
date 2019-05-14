/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 17:18:03 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 19:08:48 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"

void		update_winsize(void)
{
	ioctl(STDIN_FILENO, TIOCGWINSZ, &g_config.window);
}
