/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:20:04 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/27 17:00:13 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void				change_color(t_arg *current)
{
	if (current->file_type == NOT_FIL)
		write(2, "\033[31;1m", 7);
	else if (current->file_type == DIR_FIL)
		write(2, "\033[36m", 5);
	else if (current->file_type == SFT_LNK)
		write(2, "\033[35m", 5);
	else if (current->file_type == SOKET)
		write(2, "\033[31m", 5);
	else if (current->file_type == FIFO)
		write(2, "\033[34m", 5);
	else if (current->file_type == BLK_DEV)
		write(2, "\033[32m", 5);
	else if (current->file_type == CHR_DEV)
		write(2, "\033[33m", 5);
}

static void				ft_set_print_setting(t_vector *file,
											t_arg *current, t_setting *sets)
{
	change_color(current);
	if (current->chose && sets->lst_file == file)
		write(2, "\033[7;4m", 6);
	else if (current->chose)
		write(2, "\033[7;m", 5);
	else if (sets->lst_file == file)
		write(2, "\033[4m", 4);
}

static void				ft_unset_print_setting(void)
{
	write(2, "\033[0m", 4);
}

static void				print_files(t_vector *file,
							t_setting *sets)
{
	char				*tmp;
	t_arg				*current;

	tmp = (char *)malloc(sets->max_len_file + 5);
	ft_memset(tmp + 1, ' ', sets->max_len_file + 2);
	tmp[0] = '|';
	tmp[sets->max_len_file + 3] = '|';
	tmp[sets->max_len_file + 4] = '\0';
	current = (t_arg *)file->content;
	ft_strncpy(tmp + 2, current->file_name, ft_strlen(current->file_name));
	ft_set_print_setting(file, current, sets);
	ft_putstr_fd(tmp, 2);
	ft_unset_print_setting();
	ft_strdel(&tmp);
}

void					ft_drawing(t_setting **sets)
{
	t_vector			*lst;
	int					free_space_in_line;

	ft_putstr_fd((*sets)->cl, 2);
	ft_putendl_fd((*sets)->find_file, 2);
	ft_putendl_fd((*sets)->find_mes, 2);
	lst = (*sets)->lst_file;
	while (lst->previous)
		lst = lst->previous;
	free_space_in_line = (*sets)->column;
	while (lst)
	{
		if (free_space_in_line < ((*sets)->max_len_file + 4))
		{
			write(2, "\n", 1);
			free_space_in_line = (*sets)->column;
		}
		print_files(lst, *sets);
		lst = lst->next;
		free_space_in_line -= ((*sets)->max_len_file + 4);
	}
}
