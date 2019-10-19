/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:17:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/19 12:47:02 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int			ft_change_place(t_setting *sets, int now_pos, int all,
										int key)
{
	int				ans;
	int				file_in_line;

	file_in_line = sets->row / ((sets)->max_len_file + 1);
	ans = now_pos;
	if (key == ARROW_LEFT && now_pos > 1)
		ans = now_pos - 1;
	else if (key == ARROW_RIGTH && now_pos < all)
		ans = now_pos + 1;
	else if (key == ARROW_UP && (now_pos - file_in_line) > 0)
		now_pos = now_pos - file_in_line;
	else if (key == ARROW_DOWN && (now_pos + file_in_line) < all)
		now_pos = now_pos + file_in_line;
	return (ans);
}

void				ft_moves(t_setting **sets, unsigned long long key)
{
	t_vector		*begin;
	int				len_vect;
	int				now_pos;
	int				new_pos;

	begin = (*sets)->lst_file;
	now_pos = 1;
	while (begin->previous)
	{
		++now_pos;
		begin = begin->previous;
	}
	len_vect = ft_count_vector(begin);
	new_pos = ft_change_place(*sets, now_pos, len_vect, key);
	while (--new_pos)
		begin = begin->next;
	(*sets)->lst_file = begin;
}
