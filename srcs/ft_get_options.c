/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:30:47 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:30:53 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_initialize_opt(t_option *opt)
{
	opt->path = NULL;
	opt->l = 0;
	opt->u = 0;
	opt->a = 0;
	opt->r = 0;
	opt->t = 0;
	opt->x = 0;
	opt->d = 0;
	opt->g = 0;
	opt->e = 0;
	opt->v = 0;
	opt->h = 0;
	opt->s = 0;
	opt->i = 0;
	opt->n = 0;
}

void	ft_add_path(char *str, t_option *opt)
{
	t_path *new;

	while (opt->path && opt->path->next)
		opt->path = opt->path->next;
	if ((new = (t_path*)malloc(sizeof(t_path))) == NULL)
		ft_error("Malloc error");
	if ((new->name = ft_strdup(str)) == NULL)
		ft_error("Malloc error");
	new->next = NULL;
	new->previous = opt->path;
	if (opt->path)
		opt->path->next = new;
	opt->path = new;
	opt->x++;
}

void	ft_get_letter(char *str, t_option *opt)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'l')
			opt->l = 1;
		else if (str[i] == 'R')
			opt->u = 1;
		else if (str[i] == 'a')
			opt->a = 1;
		else if (str[i] == 'r')
			opt->r = 1;
		else if (str[i] == 't')
			opt->t = 1;
		else
			ft_next_check(str, i, opt);
		i++;
	}
}

void	ft_rewind_path(t_option *opt)
{
	while (opt->path->previous)
		opt->path = opt->path->previous;
}

void	ft_get_opt(int argc, char **argv, t_option *opt)
{
	int i;

	ft_initialize_opt(opt);
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
			ft_get_letter(argv[i], opt);
		else
			ft_add_path(argv[i], opt);
		i++;
	}
	if (opt->path == NULL)
		ft_add_path(".", opt);
	ft_rewind_path(opt);
}
