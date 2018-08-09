/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:30:05 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:30:13 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_setcolor(struct stat stats)
{
	if (S_ISDIR(stats.st_mode))
		ft_printf("{blue}");
	else if (S_ISLNK(stats.st_mode))
		ft_printf("{magenta}");
	else if (S_ISCHR(stats.st_mode))
		ft_printf("{blue}");
	else if (S_ISFIFO(stats.st_mode))
		ft_printf("{yellow}");
	else if (S_ISBLK(stats.st_mode))
		ft_printf("{blue}");
	else if (S_ISSOCK(stats.st_mode))
		ft_printf("{green}");
	else if (stats.st_mode & S_IXUSR)
		ft_printf("{red}");
}

int		ft_get_total(t_path *path, t_option *call)
{
	DIR				*folder;
	struct dirent	*file;
	struct stat		stats;
	int				x;
	char			*str;

	x = 0;
	if ((folder = opendir(path->name)) == NULL)
		ft_error_ls(path->name, 0);
	while (folder != NULL && (file = readdir(folder)) != NULL)
	{
		if (file->d_name[0] == '.' && call->a == 0)
			continue ;
		str = ft_getname(file->d_name, path->name);
		if (lstat(str, &stats) == -1 && stat(str, &stats) == -1)
			ft_error_ls(str, 0);
		free(str);
		x += stats.st_blocks;
	}
	if (folder != NULL && (closedir(folder)) == -1)
		ft_error_ls(path->name, 0);
	return (x);
}

int		ft_name(t_path *path, t_option *call, int x)
{
	DIR				*folder;

	if (call->x > 1)
		ft_printf("%s:\n", path->name);
	if (S_ISDIR(path->stats.st_mode) == 1 &&
		((folder = opendir(path->name)) == NULL
			|| closedir(folder) == -1))
	{
		ft_error_ls(path->name, 0);
		return (1);
	}
	if (call->l == 1 && (ft_get_total(path, call) > 0 || x == 1))
		ft_printf("total %d\n", ft_get_total(path, call));
	return (0);
}

void	ft_error_ls(char *str, int x)
{
	ft_printf("ft_ls: %s: %s\n", str, strerror(errno));
	if (x == 1)
		free(str);
}

void	ft_free_path(t_path *path)
{
	t_path	*next;

	if (path == NULL)
		return ;
	while (path->previous)
		path = path->previous;
	while (path)
	{
		next = path->next;
		free(path->name);
		free(path);
		path = next;
	}
}
