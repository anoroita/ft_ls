/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 10:35:21 by anoroita          #+#    #+#             */
/*   Updated: 2018/05/31 12:09:39 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	if (!(as))
		return ;
	{
		free(*as);
		*as = 0;
	}
}
