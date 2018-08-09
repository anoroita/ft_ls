/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 10:20:19 by anoroita          #+#    #+#             */
/*   Updated: 2018/06/08 10:20:26 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*next;
	t_list		*curr;

	if (del && alst)
	{
		curr = *alst;
		while (curr != NULL)
		{
			next = curr->next;
			(*del)(curr->content, curr->content_size);
			free(curr);
			curr = next;
		}
		*alst = NULL;
	}
}
