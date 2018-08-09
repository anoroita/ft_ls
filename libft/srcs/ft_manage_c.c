/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:59:31 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:59:34 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_manage_uc(t_pf *ft, va_list *ag)
{
	wchar_t c;

	c = (wchar_t)va_arg(*ag, wint_t);
	if (ft_wcharlen(c) == -1 || ft_wcharlen(c) > MB_CUR_MAX)
		return (ft_error_printf(ft));
	ft_manage_width_left(ft, ft_wcharlen(c));
	ft_manage_zero(ft, ft_wcharlen(c));
	ft_putwchar_pf(ft, c);
	ft_manage_width_right(ft, ft_wcharlen(c));
	ft->ready = ft->index;
}

void	ft_manage_c(t_pf *ft, va_list *ag)
{
	char c;

	if (ft->l == 1)
		return (ft_manage_uc(ft, ag));
	c = (char)va_arg(*ag, int);
	ft_manage_width_left(ft, 1);
	ft_manage_zero(ft, 1);
	ft_putbuf(ft, c);
	ft_manage_width_right(ft, 1);
	ft->ready = ft->index;
}
