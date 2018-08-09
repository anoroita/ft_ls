/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:31:11 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:31:16 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_print_acl(t_path *file, char *path)
{
	char	*name;
	ssize_t	xattr;
	acl_t	acl;

	name = ft_getname(file->name, path);
	acl = acl_get_file(name, ACL_TYPE_EXTENDED);
	xattr = 0;
	xattr = listxattr(name, NULL, 0, XATTR_NOFOLLOW);
	if (acl)
		ft_putchar('+');
	else if (xattr > 0)
		ft_putchar('@');
	else
		ft_putchar(' ');
	acl_free((void*)acl);
	free(name);
}

void	ft_print_i(t_path *file, t_option *call)
{
	t_path	*me;
	int		max;

	if (call->i == 0)
		return ;
	max = -1;
	me = file;
	while (file->previous)
		file = file->previous;
	while (file)
	{
		if ((int)file->stats.st_ino > max)
			max = file->stats.st_ino;
		file = file->next;
	}
	ft_printf("%*-d", ft_nbrlen(max) + 1, me->stats.st_ino);
}

int		ft_nbrlen(int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

void	ft_print_user_uid(t_path *file, int x)
{
	int				max;

	while (file->previous)
		file = file->previous;
	max = 0;
	while (file)
	{
		if ((int)file->stats.st_uid > max)
			max = file->stats.st_uid;
		if (file->next == NULL)
			break ;
		file = file->next;
	}
	ft_printf("%*d", ft_nbrlen(max) + 1, x);
}

void	ft_print_group_gid(t_path *file, int x)
{
	int				max;

	while (file->previous)
		file = file->previous;
	max = 0;
	while (file)
	{
		if ((int)file->stats.st_gid > max)
			max = file->stats.st_gid;
		if (file->next == NULL)
			break ;
		file = file->next;
	}
	ft_printf("%*d", ft_nbrlen(max) + 2, x);
}
