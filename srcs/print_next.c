/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:33:31 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:33:49 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_print_size(t_path *file, struct stat stats)
{
	int max;

	max = -1;
	while (file->previous)
		file = file->previous;
	while (file)
	{
		if (S_ISCHR(file->stats.st_mode) || S_ISBLK(file->stats.st_mode))
		{
			if (minor(file->stats.st_rdev) > max)
				max = minor(file->stats.st_rdev);
		}
		else if (file->stats.st_size > max)
			max = file->stats.st_size;
		file = file->next;
	}
	if (max == -1)
		return ;
	if (S_ISCHR(stats.st_mode) || S_ISBLK(stats.st_mode))
		ft_printf("%*d ", ft_nbrlen(max) + 2, minor(stats.st_rdev));
	else
		ft_printf("%*d ", ft_nbrlen(max) + 2, stats.st_size);
}

void	ft_print_date(t_path *file, int h)
{
	time_t	now;
	char	*tmp;
	char	*str;

	now = time(0);
	str = ctime(&file->stats.st_mtime);
	if (h == 1 || (file->stats.st_mtime <= now &&
		file->stats.st_mtime >= now - 15778800))
	{
		if ((tmp = ft_strsub(str, 4, 12)) == NULL)
			ft_error("Malloc error");
		ft_printf("%s ", tmp);
		free(tmp);
	}
	else
	{
		if ((tmp = ft_strsub(str, 4, 6)) == NULL)
			ft_error("Malloc error");
		ft_printf("%s ", tmp);
		free(tmp);
		if ((tmp = ft_strsub(str, 19, 5)) == NULL)
			ft_error("Malloc error");
		ft_printf("%s ", tmp);
	}
}

void	ft_print_lnk(t_path *file, char *path)
{
	char	buf[4096];
	int		x;
	char	*name;

	name = ft_getname(file->name, path);
	x = (int)readlink(name, buf, 4096);
	free(name);
	if (x == -1)
		return ;
	buf[x] = 0;
	ft_printf(" -> %s", buf);
}

void	ft_print_major(t_path *file, struct stat stats)
{
	int max;

	max = -1;
	while (file->previous)
		file = file->previous;
	while (file)
	{
		if (S_ISCHR(file->stats.st_mode) || S_ISBLK(file->stats.st_mode))
			if (major(file->stats.st_rdev) > max)
				max = major(file->stats.st_rdev);
		file = file->next;
	}
	if (max == -1)
		return ;
	if (S_ISCHR(stats.st_mode) || S_ISBLK(stats.st_mode))
		ft_printf("%*d,", ft_nbrlen(max) + 2, major(stats.st_rdev));
	else
		ft_printf("%*c", ft_nbrlen(max) + 3, ' ');
}

void	ft_print_file(t_path *file, t_option *call, char *path)
{
	ft_print_i(file, call);
	if (call->l == 1)
	{
		ft_print_type(file->stats);
		ft_print_rights(file->stats);
		ft_print_acl(file, path);
		ft_print_nbrlnks(file, file->stats.st_nlink);
		ft_print_user(file, file->stats.st_uid, call->n);
		ft_print_group(file, file->stats.st_gid, call->n);
		ft_print_major(file, file->stats);
		ft_print_size(file, file->stats);
		ft_print_date(file, call->h);
	}
	if (call->g == 1)
		ft_setcolor(file->stats);
	ft_printf("%s", file->name);
	if (call->g == 1)
		ft_printf("{reset}");
	if (call->l == 1 && S_ISLNK(file->stats.st_mode))
		ft_print_lnk(file, path);
	if (call->l == 1 && call->e == 1)
		ft_print_e(ft_getname(file->name, path));
	if (call->l == 1 && call->v == 1)
		ft_print_v(ft_getname(file->name, path));
	ft_putchar('\n');
}
