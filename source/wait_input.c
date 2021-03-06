/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:35:59 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/27 17:18:30 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int				ft_key_distribution(t_setting **sets,
												unsigned long long key)
{
	if ((key == F || key == F_SMALL) && !(*sets)->find_mode)
		(*sets)->find_mode = 1;
	else if ((*sets)->find_mode)
		ft_find_mode(sets, key);
	else if (key == ENTER || key == ESC)
	{
		if (key == ENTER)
			(*sets)->output = 1;
		return (EXIT);
	}
	else if (key == ARROW_LEFT || key == ARROW_RIGTH ||
			key == ARROW_DOWN || key == ARROW_UP)
		ft_moves(sets, key);
	else if (key == DELETE || key == BACKSPACE)
		return (ft_del_file(sets, key));
	else if (key == SPACE)
		ft_chose(sets);
	return (SUCCESS);
}

int						ft_check_size_window(t_setting **sets)
{
	if ((*sets)->column < 4 + (*sets)->max_len_file ||
		(*sets)->row < 2 +
		(*sets)->all_files / ((*sets)->column / ((*sets)->max_len_file + 4)))
		return (0);
	return (1);
}

void					ft_wait_input(void)
{
	unsigned char		buff[6];
	int					read_bite;
	unsigned long long	key;
	int					i;
	t_setting			**sets;

	ft_signal_intercept();
	sets = ft_take_my_setting(0);
	set_setting(&((*sets)->my_sets));
	ft_putstr_fd((*sets)->vi, 2);
	if (ft_check_size_window(sets))
		ft_drawing(sets);
	while (sets && (*sets)->lst_file &&
			(read_bite = read(STDIN_FILENO, buff, 5)))
	{
		buff[read_bite] = '\0';
		key = buff[0];
		i = 0;
		while (buff[++i] && i < 6)
			key = key * 256 + buff[i];
		if (ft_key_distribution(sets, key) == EXIT)
			break ;
		if (ft_check_size_window(sets))
			ft_drawing(sets);
	}
}
