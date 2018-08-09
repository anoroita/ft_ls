/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:00:34 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 09:00:36 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_new_precision(t_pf *ft, int len, intmax_t nbr)
{
	if (len > ft->precision)
	{
		ft->precision = len;
		if (nbr < 0)
			ft->neg = 1;
	}
	else if (nbr < 0)
	{
		ft->precision++;
		ft->neg++;
	}
}

void	ft_manage_zero(t_pf *ft, int len)
{
	if (ft->zero == 0)
		return ;
	while (len < ft->width)
	{
		ft_putbuf(ft, '0');
		len++;
	}
}

void	ft_manage_width_left(t_pf *ft, int len)
{
	if (ft->minus == 1)
		return ;
	if (ft->zero == 1)
		return ;
	while (len < ft->width)
	{
		ft_putbuf(ft, ' ');
		len++;
	}
}

void	ft_manage_width_right(t_pf *ft, int len)
{
	if (ft->minus == 0)
		return ;
	while (len < ft->width)
	{
		ft_putbuf(ft, ' ');
		len++;
	}
}

void	ft_manage_precision(t_pf *ft, int len)
{
	while (len < ft->precision - ft->neg && ft->done == 0)
	{
		ft_putbuf(ft, '0');
		len++;
	}
	ft->done = 1;
}
