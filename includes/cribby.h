/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cribby.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:26:03 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 21:54:25 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CRIBBY_H
# define CRIBBY_H

/*
**	INCLUDES
*/

# include <unistd.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>
# include "keys.h"
# include "libft.h"
# include "terminal.h"
# include "utils.h"
# include "window.h"
# include "draw.h"
# include "input.h"
# include "file.h"

/*
**	STRUCTS
*/

typedef struct				s_row
{
	struct s_row			*prev;
	char					*line;
	int						length;
	struct s_row			*next;
}							t_row;


typedef struct 				s_cursor
{
	int						row;
	int						col;
}							t_cursor;

typedef struct				s_screen_data
{
	char					*data;
	int						len;
}							t_screen_data;

typedef struct				s_terminal
{
	struct termios			old_terminal;
	struct termios			new_terminal;
}							t_terminal;

typedef struct				s_config
{
	t_row					*row;
	int						row_count;
	t_cursor				cursor;
	t_screen_data			screen_data;
	t_terminal				terminal;
	struct winsize			window;
}							t_config;

t_config					g_config;

#endif
