/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:47:51 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:47:53 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_manage_ub(t_pf *ft, va_list *ag)
{
	ft->ll = 0;
	ft->h = 0;
	ft->hh = 0;
	ft->j = 0;
	ft->z = 0;
	ft->l = 1;
	ft_manage_b(ft, ag);
}

void	ft_manage_b(t_pf *ft, va_list *ag)
{
	uintmax_t nbr;

	nbr = ft_get_uint(ft, ag);
	ft_remove_zero(ft);
	ft_manage_width_left(ft, ft_baselen_precision(ft, nbr, 2));
	ft_manage_zero(ft, ft_baselen_precision(ft, nbr, 2));
	ft_putbase(ft, nbr, "01");
	ft_manage_width_right(ft, ft_baselen_precision(ft, nbr, 2));
	ft->ready = ft->index;
}
