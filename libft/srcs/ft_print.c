/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 08:49:17 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 08:49:19 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_putstr_pf(t_pf *ft, char *str, int len)
{
	int i;

	i = 0;
	while (str[i] && i < len)
	{
		ft_putbuf(ft, str[i]);
		i++;
	}
}

void	ft_putwstr_pf(t_pf *ft, wchar_t *str, int len)
{
	int i;
	int x;

	i = 0;
	x = 0;
	while (str[i] && x + ft_wcharlen(str[i]) <= len)
	{
		ft_putwchar_pf(ft, str[i]);
		x += ft_wcharlen(str[i]);
		i++;
	}
}

void	ft_putnbr_pf(t_pf *ft, intmax_t nbr)
{
	if (ft->precision == 0 && ft->point == 1 && nbr == 0)
		return ;
	if (nbr < 0)
	{
		ft_manage_precision(ft, ft_nbrlen(nbr) - 1);
		if (nbr < -9)
		{
			ft_putnbr_pf(ft, (nbr / 10) * -1);
			ft_putnbr_pf(ft, (nbr % 10) * -1);
		}
		else
			ft_putnbr_pf(ft, -nbr);
		return ;
	}
	ft_manage_precision(ft, ft_nbrlen(nbr));
	if (nbr > 9)
	{
		ft_putnbr_pf(ft, nbr / 10);
		ft_putnbr_pf(ft, nbr % 10);
	}
	else
		ft_putbuf(ft, nbr + 48);
}

void	ft_putbase(t_pf *ft, uintmax_t nbr, char *base)
{
	if (ft->precision == 0 && ft->point == 1 && nbr == 0)
		return ;
	ft_manage_precision(ft, ft_baselen(ft, nbr, ft_strlen(base)));
	if (nbr / ft_strlen(base) > 0)
		ft_putbase(ft, nbr / ft_strlen(base), base);
	ft_putbuf(ft, base[nbr % ft_strlen(base)]);
}
