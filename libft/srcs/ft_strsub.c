/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:43:25 by anoroita          #+#    #+#             */
/*   Updated: 2018/05/31 12:23:27 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*d;

	i = 0;
	if (!(s))
		return (NULL);
	d = malloc(sizeof(char) * len + 1);
	if (!d)
		return (0);
	while (len > 0)
	{
		d[i] = s[start];
		i++;
		start++;
		len--;
	}
	d[i] = '\0';
	return (d);
}
