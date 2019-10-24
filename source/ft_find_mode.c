/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 12:48:53 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/24 12:40:30 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void				ft_find_filename(t_setting **sets)
{
	t_vector			*files;

	if (!sets || !(*sets) || !((*sets)->lst_file))
		return ;
	files = (*sets)->lst_file;
	while (files->previous)
		files = files->previous;
	while (files)
	{
		if (ft_strncmp((*sets)->find_file,
					((t_arg *)files->content)->file_name,
					(*sets)->find_i) == 0)
		{
			(*sets)->lst_file = files;
			(*sets)->find_mes = "Find result: \033[32;1mOK!\033[0m";
			return ;
		}
		(*sets)->find_mes = "Find result: \033[31;1mNOT FOUND!\033[0m";
		files = files->next;
	}
}

void					ft_find_mode(t_setting **sets,
										unsigned long long key)
{
	if (PRINTABLE(key))
	{
		((*sets)->find_file)[(*sets)->find_i] = key;
		(*sets)->find_i = ((*sets)->find_i < 4095) ?
			(*sets)->find_i + 1 : 4095;
	}
	else if (key == BACKSPACE)
	{
		(*sets)->find_i = ((*sets)->find_i > 0) ?
			(*sets)->find_i - 1 : 0;
		((*sets)->find_file)[(*sets)->find_i] = '\0';
	}
	else if (key == ENTER || key == ESC)
	{
		if (key == ENTER)
			ft_find_filename(sets);
		(*sets)->find_mode = 0;
		(*sets)->find_i = 0;
		ft_bzero((*sets)->find_file, 4096);
	}
}
