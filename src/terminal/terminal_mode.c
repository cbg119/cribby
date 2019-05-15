/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal_mode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:53:41 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/14 16:31:09 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "terminal.h"

int				term_check(void)
{
	char	*term_type;
	char	buffer[2048];

	term_type = getenv("TERM");
	if (!term_type)
		cribby_error("$TERM variable not found!");
	else if (!tgetent(buffer, term_type))
		cribby_error("terminfo not found!");
	else
		return (1);
	return (0);
}

void			enable_raw_terminal(void)
{
	tcgetattr(STDERR_FILENO, &g_config.terminal.old_terminal);
	tcgetattr(STDERR_FILENO, &g_config.terminal.new_terminal);
	g_config.terminal.new_terminal.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDERR_FILENO, TCSAFLUSH, &g_config.terminal.new_terminal);
}

void			reset_default_terminal(void)
{
	tcsetattr(STDERR_FILENO, TCSAFLUSH, &g_config.terminal.old_terminal);
}
