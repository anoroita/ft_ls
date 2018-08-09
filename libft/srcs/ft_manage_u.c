/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:57:32 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:57:34 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_manage_uu(t_pf *ft, va_list *ag)
{
	ft->ll = 0;
	ft->h = 0;
	ft->hh = 0;
	ft->j = 0;
	ft->z = 0;
	ft->l = 1;
	ft_manage_u(ft, ag);
}

void	ft_manage_u(t_pf *ft, va_list *ag)
{
	uintmax_t nbr;

	nbr = ft_get_uint(ft, ag);
	ft_remove_zero(ft);
	ft_manage_width_left(ft, ft_baselen_precision(ft, nbr, 10));
	ft_manage_zero(ft, ft_baselen_precision(ft, nbr, 10));
	ft_putbase(ft, nbr, "0123456789");
	ft_manage_width_right(ft, ft_baselen_precision(ft, nbr, 10));
	ft->ready = ft->index;
}
