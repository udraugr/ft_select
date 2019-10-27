/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_end_work.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:32:32 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/27 18:49:48 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		ft_output_ans(t_vector *files)
{
	int			words;

	words = 0;
	if (files != NULL)
	{
		while (files->previous)
			files = files->previous;
		while (files)
		{
			if (((t_arg *)files->content)->chose)
			{
				if (words)
					ft_putchar(' ');
				ft_printf("%s", ((t_arg *)files->content)->file_name);
				++words;
			}
			files = files->next;
		}
	}
}

void			ft_end_work(int sign)
{
	t_setting	**sets;
	t_vector	*files;

	sets = ft_take_my_setting(0);
	ft_putstr_fd((*sets)->ve, 2);
	ft_putstr_fd((*sets)->cl, 2);
	files = (*sets)->lst_file;
	if ((*sets)->output)
		ft_output_ans(files);
	set_setting(&((*sets)->def_sets));
	if ((*sets)->lst_file)
	{
		ft_delall_vector(&((*sets)->lst_file), ft_destroy_t_arg);
	}
	ft_bzero((void *)(*sets), sizeof(t_setting));
	ft_memdel((void **)(sets));
	exit(sign);
}
