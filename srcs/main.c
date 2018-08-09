/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:32:10 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:32:19 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_initiate(t_option *opt, t_option *list, t_path *path, int x)
{
	(*opt).path = NULL;
	(*list).path = NULL;
	if (path->previous && S_ISDIR(path->stats.st_mode) == 1)
		ft_putchar('\n');
	else if (x == 0)
		ft_putchar('\n');
}

void	ft_start_print(t_path *path, t_option *call, int x)
{
	DIR				*folder;
	struct dirent	*file;
	t_option		opt;
	t_option		list;

	if (call->d == 0)
		ft_initiate(&opt, &list, path, x);
	if (S_ISDIR(path->stats.st_mode) == 0 || call->d == 1)
		ft_print_file(path, call, "");
	else if (call->d == 0)
	{
		if (ft_name(path, call, x) == 1)
			return ;
		if ((folder = opendir(path->name)) == NULL)
			return (ft_error_ls(path->name, 0));
		while ((file = readdir(folder)) != NULL)
		{
			ft_add_file(&list, file, call, path->name);
			ft_add_folder(&opt, file, call, path->name);
		}
		if ((closedir(folder)) == -1)
			return (ft_error_ls(path->name, 0));
		ft_handle_file(list.path, opt.path, call, path->name);
	}
}

t_path	*ft_check(t_path *path)
{
	t_path		*start;
	t_path		*next;

	while (path->previous)
		path = path->previous;
	start = NULL;
	while (path)
	{
		next = path->next;
		if ((lstat(path->name, &path->stats) == -1 &&
			stat(path->name, &path->stats) == -1))
		{
			ft_error_ls(path->name, 0);
			if (path->previous)
				path->previous->next = path->next;
			if (path->next)
				path->next->previous = path->previous;
			free(path->name);
			free(path);
		}
		else if (start == NULL)
			start = path;
		path = next;
	}
	return (start);
}

int		main(int argc, char **argv)
{
	t_option	opt;

	ft_get_opt(argc, argv, &opt);
	opt.path = ft_check(opt.path);
	ft_order(opt.path, &opt);
	while (opt.path)
	{
		if (opt.path->name != NULL)
			ft_start_print(opt.path, &opt, 1);
		if (opt.path->next == NULL)
			break ;
		opt.path = opt.path->next;
	}
	ft_free_path(opt.path);
	return (0);
}
