/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_star.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:58:03 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:58:06 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_manage_star(t_pf *ft, const char *format, va_list *ag, int *i)
{
	int nbr;

	nbr = va_arg(*ag, int);
	if (format[ft->i - 1] == '.')
	{
		if (nbr >= 0)
			ft->precision = nbr;
		else
			ft->point = 0;
	}
	else
	{
		if (nbr < 0)
		{
			ft->width = nbr * -1;
			ft->minus = 1;
		}
		else
			ft->width = nbr;
	}
	*i = -1;
	ft->i++;
}
