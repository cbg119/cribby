/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:42:10 by cbagdon           #+#    #+#             */
/*   Updated: 2019/03/22 01:22:25 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static char						*c_u(unsigned long long num, t_opts options)
{
	int		len;
	char	*result;

	if (num == 0 && options.precision == 0)
		return (ft_strdup(""));
	len = ft_numlen(num);
	if (options.precision > len)
	{
		len = options.precision;
		result = ft_strnew(len);
		ft_memset(result, '0', len);
		ft_intmove(result, len, num, 0);
		return (result);
	}
	result = ft_strnew(len);
	ft_intmove(result, len, num, 0);
	return (result);
}

static void						zero_pad(char *str)
{
	int		i;

	i = 0;
	while (str[i] == ' ')
		str[i++] = '0';
}

int								convert_u(t_opts options, va_list ap)
{
	unsigned long long	number;
	char				*result;

	number = fetch_number(options.length, ap);
	result = c_u(number, options);
	result = ft_pad(result, options.field_width, ft_strlen(result),
			options.flags.minus);
	if (options.flags.zero == 1 && options.flags.minus == 0)
		zero_pad(result);
	ft_putstr(result);
	number = ft_strlen(result);
	free(result);
	return ((int)number);
}
