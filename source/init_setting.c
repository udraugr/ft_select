/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:30:44 by udraugr-          #+#    #+#             */
/*   Updated: 2019/09/13 16:53:25 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			ft_get_max_len_file(t_setting *sets)
{
	t_vector	*cur_file;
	int		max;
	int		len_filename;

	cur_file = *sets->lst_file;
	max = 1;
	while (cur_file)
	{
		len_filename = ft_strlen(((t_arg *)cur_file->content)->file_name);
		if (len_filename > max)
			max = len_filename;
		cur_file = cur_file->next;
	}
	sets->max_len_file = max;
}

void			ft_get_win_size(t_setting *sets)
{
	struct winsize	win_size;;

	ioctl(STDOUT_FILENO, TIOCWINSZ, &win_size);
	sets->row = win_size.ws_row;
	sets->column = win_size.ws_col;
}



int				init_setting(t_setting *sets, t_vector **lst_file)
{
	if (getenv("TERM") == NULL ||
		(sets = (t_setting *)malloc(sizeof(t_setting))) == NULL)
		return (FAIL);
	sets->cur_pos = 0;
	sets->lst_file = lst_file;
	ft_get_max_len_file(sets);
	ft_get_win_size(sets);
	tcgetattr(STDIN_FILENO, &sets->def_sets);
	tcgetattr(STDIN_FILENO, &sets->my_sets);
	sets->my_sets.c_lflag &= ~(ECHO | ICANON) // нужно еще почитать как это работает
	sets->my_sets.c_cc[VMIN] = 1;
	sets->my_sets.c_cc[VTIME] = 0;
	return (SUCCESS);
}
