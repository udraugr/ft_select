/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_vector.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:00:39 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/27 17:52:44 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector		*ft_create_vector(void *content)
{
	t_vector	*new_vector;

	if (!(new_vector = (t_vector *)malloc(sizeof(t_vector))))
		return (0);
	new_vector->next = 0;
	new_vector->previous = 0;
	new_vector->content = content;
	return (new_vector);
}

int				ft_count_vector(t_vector *begin)
{
	int			ans;

	if (!begin)
		return (0);
	ans = 1;
	while (begin->next)
	{
		++ans;
		begin = begin->next;
	}
	return (ans);
}

void			ft_del_vector(t_vector **chain, void (*f)(void **))
{
	t_vector	*del;

	if (!chain || !(*chain))
		return ;
	del = *chain;
	if (del->previous)
		(del->previous)->next = del->next;
	if (del->next)
		(del->next)->previous = del->previous;
	del->next = 0;
	del->previous = 0;
	if (del->content != 0)
		f((void **)(&(del->content)));
	ft_memdel((void **)&del);
}

t_vector		*ft_add_vector(t_vector *begin, void *content)
{
	t_vector	*tmp;
	t_vector	*new;

	if (!(new = ft_create_vector(content)))
		return (NULL);
	if (!begin)
		return (new);
	tmp = begin;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->previous = tmp;
	return (begin);
}
