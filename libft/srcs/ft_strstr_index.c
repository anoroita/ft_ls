/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 06:53:27 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 06:54:16 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strstr_index(char *big, char *little)
{
	int i;
	int n;
	int len;

	len = ft_strlen(little);
	if (len == 0)
		return (-1);
	i = 0;
	while (big[i])
	{
		n = 0;
		while (big[i + n] == little[n])
		{
			n++;
			if (n == len)
				return (i);
		}
		i++;
	}
	return (-1);
}
