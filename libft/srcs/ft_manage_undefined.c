/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_undefined.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:57:02 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:57:04 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_manage_undefined(t_pf *ft, char c)
{
	ft_manage_width_left(ft, 1);
	ft_manage_zero(ft, 1);
	ft_putbuf(ft, c);
	ft_manage_width_right(ft, 1);
	ft->ready = ft->index;
}
