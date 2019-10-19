/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:39:20 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/19 13:35:49 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int				ft_del_file(t_setting **sets, int key)
{
	t_vector	*files;

	if (!sets || !(*sets) || !(*sets)->lst_file)
		return (EXIT);
	files = (*sets)->lst_file;
	ft_printf("%p && %p\n", files, files->next);
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
		for (t_vector *tmp = files; tmp; tmp = tmp->next)
			ft_printf("%s\n", ((t_arg *)tmp->content)->file_name);
		if (files == 0)
			return (EXIT);
	}
	else if (key == DELETE && files->next)
	{
		for (t_vector *tmp = files; tmp; tmp = tmp->next)
			ft_printf("%s\n", ((t_arg *)tmp->content)->file_name);
		files = files->next;
		ft_del_vector(&files, ft_destroy_t_arg);
		//ft_del_vector(&(files->next), ft_destroy_t_arg);
	}
	return (SUCCESS);
}
