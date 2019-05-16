/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbagdon <cbagdon@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 21:27:30 by cbagdon           #+#    #+#             */
/*   Updated: 2019/05/15 22:53:01 by cbagdon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, int n)
{
	int				i;
	int				j;
	unsigned int	len;
	char			*string;

	i = -1;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	string = ft_strnew(len);
	while (s1[++i])
		string[i] = s1[i];
	while (j < n && s2[j])
		string[i++] = s2[j++];
	return (string);
}
