/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_setting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 16:30:44 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/27 17:13:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			ft_get_max_len_file(t_setting *sets)
{
	t_vector	*cur_file;
	int			max;
	int			len_filename;

	cur_file = sets->lst_file;
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
	struct winsize	win_size;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &win_size);
	sets->row = win_size.ws_row;
	sets->column = win_size.ws_col;
	if (!ft_check_size_window(&sets))
		ft_putstr_fd("Win small!\n", 2);
}

static void		set_flags(t_setting **sets)
{
	char		*bp;

	bp = 0;
	if (tgetent(bp, getenv("TERM")) == -1)
		ft_putendl_fd("Fail with tgetent\n", 2);
	(*sets)->ve = tgetstr("ve", &bp);
	(*sets)->vi = tgetstr("vi", &bp);
	(*sets)->cl = tgetstr("cl", &bp);
}

/*
**	sets->my_sets.c_cc[VMIN] = 1; VMIN флаг по сколько символов
**	минимально считывается сивмолов
**	sets->my_sets.c_cc[VTIME] = 0; VTIME  фдаг который спрашивает
**	в какой промежуток времени нужно опрашивать клавиатуру
**	sets->my_sets.c_lflag &= ~(ECHO | ICANON) изменяет начальные настройки
*/

int				init_setting(t_setting **sets, t_vector *lst_file)
{
	if (getenv("TERM") == NULL ||
		((*sets) = (t_setting *)malloc(sizeof(t_setting))) == NULL)
		return (FAIL);
	(*sets)->lst_file = lst_file;
	(*sets)->all_files = ft_count_vector(lst_file);
	ft_get_max_len_file(*sets);
	ft_get_win_size(*sets);
	//(*sets)->output = 0;
	tcgetattr(STDIN_FILENO, &(*sets)->def_sets);
	tcgetattr(STDIN_FILENO, &(*sets)->my_sets);
	(*sets)->my_sets.c_lflag &= ~(ECHO | ICANON);
	(*sets)->my_sets.c_cc[VMIN] = 1;
	(*sets)->my_sets.c_cc[VTIME] = 0;
	ft_bzero((*sets)->find_file, 4096);
	(*sets)->find_mes = "";
	(*sets)->find_i = 0;
	(*sets)->find_mode = 0;
	set_flags(sets);
	return (SUCCESS);
}
