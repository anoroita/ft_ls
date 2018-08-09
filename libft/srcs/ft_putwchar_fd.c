/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 06:40:47 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 06:42:02 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(int c, int fd)
{
	char buf[4];

	if (c <= 0x7F)
		write(fd, &c, 1);
	else if (c <= 0x7FF)
	{
		buf[0] = 0xC0 | (c >> 6);
		buf[1] = 0x80 | (c & 0x3F);
		write(fd, buf, 2);
	}
	else if (c <= 0xFFFF)
	{
		buf[0] = 0xE0 | (c >> 12);
		buf[1] = 0x80 | ((c >> 6) & 0x3F);
		buf[2] = 0x80 | (c & 0x3F);
		write(fd, buf, 3);
	}
	else if (c <= 0x10FFFF)
	{
		buf[0] = 0xF0 | (c >> 18);
		buf[1] = 0x80 | ((c >> 12) & 0x3F);
		buf[2] = 0x80 | ((c >> 6) & 0x3F);
		buf[3] = 0x80 | (c & 0x3F);
		write(fd, buf, 4);
	}
}
