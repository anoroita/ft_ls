/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 14:55:43 by anoroita          #+#    #+#             */
/*   Updated: 2018/05/31 12:38:47 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	sum;
	char	*d;

	i = 0;
	j = 0;
	if (!(s1 && s2))
		return (0);
	sum = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(d = (char *)malloc(sizeof(char) * sum + 1)))
		return (0);
	while (s1[i])
	{
		d[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		d[i] = s2[j];
		i++;
		j++;
	}
	d[i] = '\0';
	return (d);
}
