/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:39:20 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/18 14:10:42 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int				ft_del_file(t_setting **sets, int key)
{
	t_vector	*files;

	if (!sets || !(*sets) ||
			!(*sets)->lst_file)
		return (EXIT);
	files = (*sets)->lst_file;
	if (key == BACKSPACE)
	{
		if (files->previous)
		{
			files = files->previous;
			ft_del_vector(&(files->next), ft_destroy_t_arg);
		}
		else if (files->next)
		{
			files = files->next;
			ft_del_vector(&(files->previous), ft_destroy_t_arg);
		}
		else
		{
			ft_del_vector(&files, ft_destroy_t_arg);
			return (EXIT);
		}
		(*sets)->lst_file = files;
	}
	else if (key == DELETE && files->next)
		ft_del_vector(&(files->next), ft_destroy_t_arg);
	return (SUCCESS);
}
