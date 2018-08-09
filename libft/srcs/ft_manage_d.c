/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:00:10 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 09:00:12 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_get_int(t_pf *ft, va_list *ag)
{
	intmax_t nbr;

	if (ft->z == 1)
		nbr = va_arg(*ag, size_t);
	else if (ft->j == 1)
		nbr = va_arg(*ag, intmax_t);
	else if (ft->ll == 1)
		nbr = va_arg(*ag, long long);
	else if (ft->l == 1)
		nbr = va_arg(*ag, long);
	else if (ft->h == 1)
		nbr = (short)va_arg(*ag, int);
	else if (ft->hh == 1)
		nbr = (char)va_arg(*ag, int);
	else
		nbr = va_arg(*ag, int);
	return (nbr);
}

void		ft_manage_ud(t_pf *ft, va_list *ag)
{
	ft->ll = 0;
	ft->h = 0;
	ft->hh = 0;
	ft->j = 0;
	ft->z = 0;
	ft->l = 1;
	ft_manage_d(ft, ag);
}

void		ft_remove_zero(t_pf *ft)
{
	if (ft->point == 1 && ft->precision >= 0)
		ft->zero = 0;
}

void		ft_manage_d(t_pf *ft, va_list *ag)
{
	intmax_t	nbr;
	int			len;

	nbr = ft_get_int(ft, ag);
	ft_remove_zero(ft);
	if (nbr != 0 || ft->point != 1 || ft->precision != 0)
		ft_new_precision(ft, ft_nbrlen(nbr), nbr);
	len = ft->precision;
	if (nbr >= 0)
		len += ft->space + ft->plus;
	ft_manage_width_left(ft, len);
	if (ft->space == 1 && nbr >= 0)
		ft_putbuf(ft, ' ');
	if (ft->plus == 1 && nbr >= 0)
		ft_putbuf(ft, '+');
	if (nbr < 0)
		ft_putbuf(ft, '-');
	ft_manage_zero(ft, len);
	ft_putnbr_pf(ft, nbr);
	ft_manage_width_right(ft, len);
	ft->ready = ft->index;
}
