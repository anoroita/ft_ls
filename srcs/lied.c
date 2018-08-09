/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lied.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 14:31:33 by anoroita          #+#    #+#             */
/*   Updated: 2018/08/09 14:31:40 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"

void	ft_next_check(char *str, int i, t_option *opt)
{
	if (str[i] == 'd')
		opt->d = 1;
	else if (str[i] == 'G')
		opt->g = 1;
	else if (str[i] == 'e')
		opt->e = 1;
	else if (str[i] == '@')
		opt->v = 1;
	else if (str[i] == 'h')
		opt->h = 1;
	else if (str[i] == 'S')
		opt->s = 1;
	else if (str[i] == 'i')
		opt->i = 1;
	else if (str[i] == 'n')
		opt->n = 1;
	else if (str[i] != '-')
	{
		ft_printf("ft_ls: illegal option -- %c\n", str[i]);
		ft_error("usage: ft_ls [-RalrtdGe@hSin] [file ...]");
	}
}

void	ft_print_e(char *path)
{
	acl_t	acl;
	char	*str;
	ssize_t	len;

	acl = acl_get_file(path, ACL_TYPE_EXTENDED);
	if (acl)
	{
		str = acl_to_text(acl, &len);
		ft_printf("\n%.*s", len - 9, str + 8);
		acl_free((void*)str);
	}
	acl_free((void*)acl);
	free(path);
}

void	ft_print_v(char *path)
{
	char	buf[4096];
	ssize_t	x;

	buf[0] = 0;
	buf[4095] = 0;
	listxattr(path, (void*)buf, 4096, XATTR_NOFOLLOW);
	x = getxattr(path, buf, NULL, 0, 0, XATTR_NOFOLLOW);
	free(path);
	if (x <= 0)
		return ;
	ft_printf("\n%s %d", buf, x);
}
