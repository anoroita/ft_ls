/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 08:59:49 by anoroita          #+#    #+#             */
/*   Updated: 2018/06/05 12:22:57 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	reatoi(int n)
{
	if (n == -1)
		return (0);
	return (-1);
}

int			ft_atoi(const char *str)
{
	int	n;
	int	a;
	int	sign;

	n = 0;
	a = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	if (*str == '+' || *str == '-')
		sign = (*str++ == '-') ? -1 : 1;
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str++ - '0');
		if (a > 18)
			return (reatoi(sign));
		a++;
	}
	return (n * sign);
}
