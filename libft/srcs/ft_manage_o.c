/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_o.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:59:49 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:59:51 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t	ft_get_uint(t_pf *ft, va_list *ag)
{
	uintmax_t	nbr;

	if (ft->z == 1)
		nbr = va_arg(*ag, size_t);
	else if (ft->j == 1)
		nbr = va_arg(*ag, uintmax_t);
	else if (ft->ll == 1)
		nbr = va_arg(*ag, unsigned long long);
	else if (ft->l == 1)
		nbr = va_arg(*ag, unsigned long);
	else if (ft->h == 1)
		nbr = (unsigned short)va_arg(*ag, unsigned int);
	else if (ft->hh == 1)
		nbr = (unsigned char)va_arg(*ag, unsigned int);
	else
		nbr = va_arg(*ag, unsigned int);
	return (nbr);
}

void		ft_manage_uo(t_pf *ft, va_list *ag)
{
	ft->ll = 0;
	ft->h = 0;
	ft->hh = 0;
	ft->j = 0;
	ft->z = 0;
	ft->l = 1;
	ft_manage_o(ft, ag);
}

void		ft_manage_o(t_pf *ft, va_list *ag)
{
	uintmax_t	nbr;
	int			len;

	nbr = ft_get_uint(ft, ag);
	ft_remove_zero(ft);
	len = 0;
	if (nbr != 0 && ft->hash == 1 && ft->precision <= ft_baselen(ft, nbr, 8))
		len = 1;
	if (ft->hash == 1 && ft_baselen(ft, nbr, 8) == 0)
		len = 1;
	ft_manage_width_left(ft, ft_baselen_precision(ft, nbr, 8) + len);
	ft_manage_zero(ft, ft_baselen_precision(ft, nbr, 8) + len);
	if (ft->hash == 1)
	{
		ft_putbuf(ft, '0');
		if (nbr != 0)
			ft->neg++;
	}
	if (ft->hash == 0 || nbr != 0)
		ft_putbase(ft, nbr, "01234567");
	else
		ft_manage_precision(ft, 1);
	ft_manage_width_right(ft, ft_baselen_precision(ft, nbr, 8) + len);
	ft->ready = ft->index;
}
