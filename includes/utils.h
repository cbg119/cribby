/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:14:08 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 19:58:45 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cribby.h"

/*
**	UTILS
*/

void					cribby_error(char *str);
unsigned long			ft_getch(void);
void					ft_clear_screen(void);

/*
**	CURSOR STUFF
*/

void					update_cursor_pos(void);
void					move_cursor(void);

#endif
