/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cribby_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 15:16:33 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/13 15:16:48 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	cribby_error(char *str)
{
	ft_putstr_fd("cribby: erro: ", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}
