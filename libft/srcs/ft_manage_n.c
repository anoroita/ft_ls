/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 09:01:14 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 09:01:16 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_error_printf(t_pf *ft)
{
	ft->print = -1;
}

void	ft_manage_n(t_pf *ft, va_list *ag)
{
	void *ptr;

	ptr = va_arg(*ag, void*);
	if (ptr == NULL)
		return (ft_error_printf(ft));
	if (ft->z == 1)
		*(size_t*)ptr = (size_t)ft->print;
	else if (ft->j == 1)
		*(intmax_t*)ptr = (intmax_t)ft->print;
	else if (ft->ll == 1)
		*(long long*)ptr = (long long)ft->print;
	else if (ft->l == 1)
		*(long*)ptr = (long)ft->print;
	else if (ft->h == 1)
		*(short*)ptr = (short)ft->print;
	else if (ft->hh == 1)
		*(char*)ptr = (char)ft->print;
	else
		*(int*)ptr = (int)ft->print;
}
