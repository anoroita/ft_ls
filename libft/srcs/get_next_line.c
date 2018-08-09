/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 07:14:43 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/09 07:18:49 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		nl(char *buf)
{
	int	i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
		return (1);
	return (0);
}

int		read_line(const int fd, char *buf, char *s[fd])
{
	int		ret;
	char	*tmp;

	while ((nl(buf) != 1) && ((ret = read(fd, buf, BUFF_SIZE)) > 0))
	{
		buf[ret] = '\0';
		tmp = s[fd];
		s[fd] = ft_strjoin(tmp, buf);
		ft_strdel(&tmp);
	}
	ft_strdel(&buf);
	if (ret < 0)
		return (-1);
	return (1);
}

int		get_next_line(const int fd, char **line)
{
	static char		*s[420];
	char			*tmp;
	char			*str;
	char			*buf;
	size_t			ret;

	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	buf = ft_strnew(BUFF_SIZE);
	if (!s[fd])
		s[fd] = ft_strnew(0);
	if ((ret = read_line(fd, buf, s)) == -1)
		return (-1);
	if ((str = ft_strchr(s[fd], '\n')))
	{
		*line = ft_strsub(s[fd], 0, str - s[fd]);
		tmp = s[fd];
		s[fd] = ft_strdup(str + 1);
		ft_strdel(&tmp);
		return (1);
	}
	*line = ft_strdup(s[fd]);
	ft_strdel(&s[fd]);
	return (ft_strlen(*line) > 0 ? 1 : 0);
}
