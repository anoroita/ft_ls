/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:59:07 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:59:10 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_baselen(t_pf *ft, uintmax_t nbr, int base)
{
	int x;

	if (ft->precision == 0 && ft->point == 1 && nbr == 0)
		return (0);
	if (nbr == 0)
		return (1);
	x = 0;
	while (nbr != 0)
	{
		nbr = nbr / base;
		x++;
	}
	return (x);
}

int		ft_baselen_precision(t_pf *ft, uintmax_t nbr, int base)
{
	if (ft->point == 1 && ft->precision > ft_baselen(ft, nbr, base))
		return (ft->precision);
	return (ft_baselen(ft, nbr, base));
}

void	ft_manage_p(t_pf *ft, va_list *ag)
{
	uintmax_t nbr;

	nbr = va_arg(*ag, unsigned long long);
	ft_manage_width_left(ft, ft_baselen_precision(ft, nbr, 16) + 2);
	ft_putstr_pf(ft, "0x", 2);
	ft_manage_zero(ft, ft_baselen_precision(ft, nbr, 16) + 2);
	ft_putbase(ft, nbr, "0123456789abcdef");
	ft_manage_width_right(ft, ft_baselen_precision(ft, nbr, 16) + 2);
	ft->ready = ft->index;
}
