/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_vector2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:51:48 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/21 14:04:59 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_swap_vector(t_vector *v1, t_vector *v2)
{
	void		*tmp;

	if (!v1 || !v2)
		return ;
	tmp = v1->content;
	v1->content = v2->content;
	v2->content = tmp;
}

void			ft_delall_vector(t_vector **chain, void (*f)(void **))
{
	t_vector	*next;
	t_vector	*previous;

	if (!chain || !*chain)
		return ;
	next = (*chain)->next;
	previous = (*chain)->previous;
	ft_del_vector(chain, f);
	if (next)
		ft_delall_vector(&next, f);
	else
		ft_delall_vector(&previous, f);
}
