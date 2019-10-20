/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:20:04 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/19 15:09:59 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_selcet.h"

static void				print_files(t_vector *file,
							t_setting *sets)
{
	char				*tmp;
	t_arg				current;

	tmp = (char *)malloc(sets->max_len_file + 2);
	ft_memset(tmp, ' ', sets->max_len_size + 1);
	current = (t_arg *)file->content;
	ft_strncpy(tmp, current->file_name, ft_strlen(current->file_name));
	
	write(2, tmp, ft_strlen(tmp));
	
}

void					ft_drawing(t_setting **sets)
{
	t_vector			*lst;
	int				free_space_in_line;

	ft_putendl_fd((*sets)->cl, 2);
	ft_putendl_fd((*sets)->find_file, 2);
	//ft_putendl_fd((*sets)->find_mes, 2);
	ft_putendl_fd("", 2);
	lst = (*sets)->lst_file;
	while (lst->previous)
		lst = lst->previous;
	while (lst)
	{
		print_files(lst, *sets);
		lst = lst->next;
	}
}
