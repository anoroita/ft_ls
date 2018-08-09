/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:29:27 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:29:35 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_handle_r(t_path *path, t_option *call)
{
	while (path)
	{
		ft_printf("\n%s:", path->name);
		ft_start_print(path, call, 0);
		if (path->next == NULL)
			break ;
		path = path->next;
	}
	ft_free_path(path);
}

void	ft_add_folder(t_option *opt, struct dirent *file,
		t_option *call, char *str)
{
	char		*name;
	char		*tmp;
	struct stat	stats;

	if (ft_strcmp(file->d_name, ".") == 0 || ft_strcmp(file->d_name, "..") == 0)
		return ;
	if (call->u == 0 || (call->a == 0 && file->d_name[0] == '.'))
		return ;
	if ((name = ft_strjoin(str, "/")) == NULL)
		ft_error("Malloc error");
	tmp = name;
	if ((name = ft_strjoin(name, file->d_name)) == NULL)
		ft_error("Malloc error");
	free(tmp);
	if (lstat(name, &stats) == -1 && stat(name, &stats) == -1)
		return (ft_error_ls(name, 1));
	if (S_ISDIR(stats.st_mode) == 0)
		free(name);
	if (S_ISDIR(stats.st_mode) == 0)
		return ;
	ft_add_path(name, opt);
	if (lstat(name, &opt->path->stats) == -1 &&
		stat(name, &opt->path->stats) == -1)
		return (ft_error_ls(name, 1));
	free(name);
}

void	ft_add_file(t_option *opt, struct dirent *file,
		t_option *call, char *str)
{
	char		*name;
	char		*tmp;

	if (call->a == 0 && file->d_name[0] == '.')
		return ;
	if ((name = ft_strjoin(str, "/")) == NULL)
		ft_error("Malloc error");
	tmp = name;
	if ((name = ft_strjoin(name, file->d_name)) == NULL)
		ft_error("Malloc error");
	free(tmp);
	ft_add_path(file->d_name, opt);
	if (lstat(name, &opt->path->stats) == -1 &&
		stat(name, &opt->path->stats) == -1)
		return (ft_error_ls(name, 1));
	free(name);
}

char	*ft_getname(char *str, char *path)
{
	char		*name;
	char		*tmp;

	if ((name = ft_strjoin(path, "/")) == NULL)
		ft_error("Malloc error");
	tmp = name;
	if ((name = ft_strjoin(name, str)) == NULL)
		ft_error("Malloc error");
	free(tmp);
	return (name);
}

void	ft_handle_file(t_path *file, t_path *folder, t_option *call, char *path)
{
	while (file && file->previous)
		file = file->previous;
	ft_order(file, call);
	while (file)
	{
		ft_print_file(file, call, path);
		if (file->next == NULL)
			break ;
		file = file->next;
	}
	while (folder && folder->previous)
		folder = folder->previous;
	ft_order(folder, call);
	if (folder != NULL)
		ft_handle_r(folder, call);
	ft_free_path(file);
}
