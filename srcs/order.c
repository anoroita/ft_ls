/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:32:43 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:32:49 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_invert(t_path *one, t_path *two)
{
	char		*tmp;
	struct stat	stats;

	tmp = one->name;
	one->name = two->name;
	two->name = tmp;
	stats = one->stats;
	one->stats = two->stats;
	two->stats = stats;
}

void	ft_size_order(t_path *path, t_path *other, int r)
{
	if ((path->stats.st_size > other->stats.st_size && r == 0) ||
		(path->stats.st_size < other->stats.st_size && r == 1))
		ft_invert(path, other);
}

void	ft_time_order(t_path *path, t_path *other, int r)
{
	if ((path->stats.st_ctime > other->stats.st_ctime && r == 0) ||
		(path->stats.st_ctime < other->stats.st_ctime && r == 1))
		ft_invert(path, other);
}

void	ft_order_basic(t_path *path, t_path *other, t_option *opt)
{
	if (opt->t == 1 && path->stats.st_ctime != other->stats.st_ctime)
		return ;
	if (opt->s && path->stats.st_size != other->stats.st_size)
		return ;
	if ((ft_strcmp(other->name, path->name) > 0 && opt->r == 0) ||
		(ft_strcmp(other->name, path->name) < 0 && opt->r == 1))
		ft_invert(path, other);
}

void	ft_order(t_path *path, t_option *opt)
{
	t_path	*start;
	t_path	*other;

	if (path == NULL)
		return ;
	while (path->previous)
		path = path->previous;
	start = path;
	path = path->next;
	while (path)
	{
		other = start;
		while (other != path)
		{
			if (opt->t == 1)
				ft_time_order(path, other, opt->r);
			else if (opt->s == 1)
				ft_size_order(path, other, opt->r);
			ft_order_basic(path, other, opt);
			other = other->next;
		}
		path = path->next;
	}
}
