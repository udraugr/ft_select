/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:17:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/17 16:38:46 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int			ft_change_place(t_setting *sets, int now_pos, int all,
										int key)
{
	int				ans;
	int				

	ans = 0;
	if (key == ARROW_LEFT)
		ans = (now_pos) ? 0 : ;
	else if (key == ARROW_RIGTH)
	else if (key == ARROW_UP)
	else if (key == ARROW_DOWN)
	return (now + (t_vector *)ans);
}

void				ft_moves(t_setting **sets, unsigned long long key)
{
	t_vector		*begin;
	int				len_vect;
	int				now_pos;
	int				shift;
	
	begin = *((*sets)->lst_file);
	now_pos = 1;
	while (begin->previous)
	{
		++now_pos;
		begin = begin->previous;
	}
	len_vect = ft_count_vector(begin);
	shift = ft_change_place(*sets, now_pos, len_vect, key);
	*((*sets)->lst_file) = *((*sets)->lst_file) +
		(t_vector *)(shift * sizeof(t_vector *));
}
