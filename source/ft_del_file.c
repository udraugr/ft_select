/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:39:20 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/24 12:48:19 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int				ft_del_file(t_setting **sets, int key)
{
	t_vector	*files;

	if (!sets || !(*sets) || !(*sets)->lst_file)
		return (EXIT);
	files = (*sets)->lst_file;
	if (key == BACKSPACE)
	{
		if (files->previous)
			files = files->previous;
		else if (files->next)
			files = files->next;
		else
			files = 0;
		ft_del_vector(&((*sets)->lst_file), ft_destroy_t_arg);
		(*sets)->lst_file = files;
		--((*sets)->all_files);
		if (files == 0)
			return (EXIT);
	}
	else if (key == DELETE && files->next)
	{
		files = files->next;
		ft_del_vector(&files, ft_destroy_t_arg);
		--((*sets)->all_files);
		//ft_del_vector(&(files->next), ft_destroy_t_arg);
	}
	return (SUCCESS);
}
