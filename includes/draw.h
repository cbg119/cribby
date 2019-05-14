/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:30:29 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 19:45:57 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# include "cribby.h"

/*
**	BUFFER EDITING
*/

void				buffer_append(char *to_append, int length);
void				draw_rows(void);
void				refresh_screen(void);

#endif
