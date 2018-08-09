/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:33:06 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:33:11 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_print_type(struct stat stats)
{
	if (S_ISDIR(stats.st_mode))
		ft_printf("d");
	else if (S_ISLNK(stats.st_mode))
		ft_printf("l");
	else if (S_ISCHR(stats.st_mode))
		ft_printf("c");
	else if (S_ISFIFO(stats.st_mode))
		ft_printf("p");
	else if (S_ISBLK(stats.st_mode))
		ft_printf("b");
	else if (S_ISSOCK(stats.st_mode))
		ft_printf("s");
	else
		ft_printf("-");
}

void	ft_print_rights(struct stat stats)
{
	int i;
	int where;

	i = 256;
	where = 8;
	while (i > 0)
	{
		if (i & stats.st_mode)
		{
			if (where == 0 || where == 3 || where == 6)
				ft_printf("x");
			else if (where == 1 || where == 4 || where == 7)
				ft_printf("w");
			else if (where == 2 || where == 5 || where == 8)
				ft_printf("r");
		}
		else
			ft_printf("-");
		where--;
		i = i >> 1;
	}
}

void	ft_print_nbrlnks(t_path *file, int x)
{
	int max;

	while (file->previous)
		file = file->previous;
	max = 0;
	while (file)
	{
		if (file->stats.st_nlink > max)
			max = file->stats.st_nlink;
		if (file->next == NULL)
			break ;
		file = file->next;
	}
	ft_printf("%*d", ft_nbrlen(max) + 1, x);
}

void	ft_print_user(t_path *file, int x, int n)
{
	struct passwd	*pwd;
	int				max;

	if (n == 1)
		return (ft_print_user_uid(file, x));
	while (file->previous)
		file = file->previous;
	max = 0;
	while (file)
	{
		if ((pwd = getpwuid(file->stats.st_uid)) == NULL)
			return (ft_error_ls(file->name, 0));
		if ((int)ft_strlen(pwd->pw_name) > max)
			max = ft_strlen(pwd->pw_name);
		if (file->next == NULL)
			break ;
		file = file->next;
	}
	if ((pwd = getpwuid(x)) == NULL)
		return (ft_error_ls(file->name, 0));
	ft_printf("%*s", max + 1, pwd->pw_name);
}

void	ft_print_group(t_path *file, int x, int n)
{
	struct group	*pwd;
	int				max;

	if (n == 1)
		return (ft_print_group_gid(file, x));
	while (file->previous)
		file = file->previous;
	max = 0;
	while (file)
	{
		if ((pwd = getgrgid(file->stats.st_gid)) == NULL)
			return (ft_error_ls(file->name, 0));
		if ((int)ft_strlen(pwd->gr_name) > max)
			max = ft_strlen(pwd->gr_name);
		if (file->next == NULL)
			break ;
		file = file->next;
	}
	if ((pwd = getgrgid(x)) == NULL)
		return (ft_error_ls(file->name, 0));
	ft_printf("%*s", max + 2, pwd->gr_name);
}
