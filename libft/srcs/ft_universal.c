/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_universal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:30:28 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/16 15:30:35 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*	MB_CUR_MAX is the maximum number of bytes in a multibyte character
	for the extended character set. ft_putwchar_pf puts wchar chararaters
	into buffer and prints to STDOUT by calling the ft_putbuf function
*/

void	ft_putwchar_pf(t_pf *ft, int c)
{
	if (MB_CUR_MAX == 1 && c >= 128 && c <= 255)
		ft_putbuf(ft, c);
	else if (c <= 0x7F)
		ft_putbuf(ft, c);
	else if (c <= 0x7FF)
	{
		ft_putbuf(ft, 0xC0 | (c >> 6));
		ft_putbuf(ft, 0x80 | (c & 0x3F));
	}
	else if (c <= 0xFFFF)
	{
		ft_putbuf(ft, 0xE0 | (c >> 12));
		ft_putbuf(ft, 0x80 | ((c >> 6) & 0x3F));
		ft_putbuf(ft, 0x80 | (c & 0x3F));
	}
	else if (c <= 0x10FFFF)
	{
		ft_putbuf(ft, 0xF0 | (c >> 18));
		ft_putbuf(ft, 0x80 | ((c >> 12) & 0x3F));
		ft_putbuf(ft, 0x80 | ((c >> 6) & 0x3F));
		ft_putbuf(ft, 0x80 | (c & 0x3F));
	}
}

/*	This function returns the size of wchar character that ranges from 1 - 4 bytes.
	Depending on the encoding catergory. 
*/
int		ft_wcharlen(int c)
{
	if (MB_CUR_MAX == 1 && c >= 128 && c <= 255)
		return (1);
	else if (c < 0)
		return (-1);
	else if (c > 0xD7FF && c < 0xE000)
		return (-1);
	else if (c <= 0x7F)
		return (1);
	else if (c <= 0x7FF)
		return (2);
	else if (c <= 0xFFFF)
		return (3);
	else if (c <= 0x10FFFF)
		return (4);
	return (-1);
}

/*	This function returns true if the string being parsed is unicode formatted
	or false (an error = -1) if thats not true.
*/
int		ft_check_unicode(wchar_t *str, int len)
{
	int i;
	int x;

	i = 0;
	x = 0;
	if (len == 0)
		return (1);
	while (str[i] && x + ft_wcharlen(str[i]) <= len)
	{
		if (ft_wcharlen(str[i]) == -1 || ft_wcharlen(str[i]) > MB_CUR_MAX)
			return (-1);
		x += ft_wcharlen(str[i]);
		i++;
	}
	if (x < len)
	{
		if (ft_wcharlen(str[i]) == -1 || ft_wcharlen(str[i]) > MB_CUR_MAX)
			return (-1);
	}
	return (1);
}
/*	This function returns the length of wchar string. Like the normal ft_strlen.
*/
int		ft_wstrlen(wchar_t *str)
{
	int x;
	int i;

	x = 0;
	i = 0;
	while (str[i])
	{
		x += ft_wcharlen(str[i]);
		i++;
	}
	return (x);
}
