/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:17:36 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/27 16:34:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int			ft_up(int file_in_line, int all, int now_pos)
{
	int				ans;

	if (now_pos - file_in_line > 0)
		ans = now_pos - file_in_line;
	else if (all % file_in_line >= now_pos)
		ans = all - (all % file_in_line) + now_pos;
	else
		ans = all - (all % file_in_line) - file_in_line + now_pos;
	return (ans);
}

static int			ft_down(int file_in_line, int all, int now_pos)
{
	int				ans;

	if (now_pos + file_in_line <= all)
		ans = now_pos + file_in_line;
	else if (now_pos % file_in_line)
		ans = now_pos % file_in_line;
	else
		ans = file_in_line;
	return (ans);
}

static int			ft_change_place(t_setting *sets, int now_pos, int all,
										int key)
{
	int				ans;
	int				file_in_line;

	file_in_line = sets->column / ((sets)->max_len_file + 4);
	ans = now_pos;
	if (key == ARROW_LEFT)
		ans = (now_pos > 1) ? now_pos - 1 : all;
	else if (key == ARROW_RIGTH)
		ans = (now_pos < all) ? now_pos + 1 : 1;
	else if (key == ARROW_UP)
		ans = ft_up(file_in_line, all, now_pos);
	else if (key == ARROW_DOWN)
		ans = ft_down(file_in_line, all, now_pos);
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
