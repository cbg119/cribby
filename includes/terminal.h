/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:52:09 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 19:18:48 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERMINAL_H
# define TERMINAL_H

# include "cribby.h"

/*
**	TERMINAL SETUP
*/

int						term_check(void);
void					enable_raw_terminal(void);
void					reset_default_terminal(void);

#endif
