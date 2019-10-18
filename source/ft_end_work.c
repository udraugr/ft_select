/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:32:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/18 15:49:36 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			ft_end_work(int sign)
{
	t_setting	**sets;
	t_vector	*files;

	sets = ft_take_my_setting(0);
	files = (*sets)->lst_file;
	if (sign == 0 && files != NULL)
	{
		while (files->previous)
			files = files->previous;
		while (files)
		{
			if (((t_arg *)files->content)->chose)
				ft_printf("%s ", ((t_arg *)files->content)->file_name);
			files = files->next;
		}
	}
	set_setting(&((*sets)->def_sets));
	if ((*sets)->lst_file)
	{
		ft_delall_vector(&((*sets)->lst_file), ft_destroy_t_arg);
	}
	ft_bzero((void *)(*sets), sizeof(t_setting));
	ft_memdel((void **)(sets));
	exit(sign);
}
