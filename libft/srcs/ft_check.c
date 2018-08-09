/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:21:55 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/16 15:29:11 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_set_precision(t_pf *ft, const char *format)
{
	ft->point = 1;
	if (ft_isdigit(format[ft->i + 1]) == 1)
	{
		ft->precision = ft_atoi(format + ft->i + 1);
		ft->i += ft_nbrlen(ft->precision);
	}
	else
		ft->precision = 0;
}

void	ft_set_h(t_pf *ft, const char *format)
{
	(void)format;
	if (ft->h == 0 && ft->hh == 0)
		ft->h = 1;
	else
	{
		ft->h = 0;
		ft->hh = 1;
	}
}

void	ft_set_l(t_pf *ft, const char *format)
{
	(void)format;
	if (ft->l == 0 && ft->ll == 0)
		ft->l = 1;
	else
	{
		ft->l = 0;
		ft->ll = 1;
	}
}

void	ft_set_j(t_pf *ft, const char *format)
{
	(void)format;
	ft->j = 1;
}

void	ft_set_z(t_pf *ft, const char *format)
{
	(void)format;
	ft->z = 1;
}
