/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:58:44 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:58:50 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_check_null_str(t_pf *ft, char **str, int *len)
{
	if (ft->point == 1 && ft->precision < 1)
	{
		*len = 0;
		return ;
	}
	if (*str == NULL)
		*str = "(null)";
	if (ft->point == 1 && (int)ft_strlen(*str) > ft->precision)
		*len = ft->precision;
	else
		*len = (int)ft_strlen(*str);
}

void	ft_manage_s(t_pf *ft, va_list *ag)
{
	char	*str;
	int		len;

	if (ft->l == 1)
		return (ft_manage_us(ft, ag));
	str = va_arg(*ag, char*);
	ft_check_null_str(ft, &str, &len);
	ft_manage_width_left(ft, len);
	ft_manage_zero(ft, len);
	if (len > 0)
		ft_putstr_pf(ft, str, len);
	ft_manage_width_right(ft, len);
	ft->ready = ft->index;
}
