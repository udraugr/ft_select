/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:39:20 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/17 17:16:10 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

int				ft_del_file(t_setting **sets, int key)
{
	if (!sets || !(*sets) ||
			!(*sets)->lst_file || !*((*sets)->lst_file))
		return (EXIT);
	if (key == BACKSPACE)
	{
		if (*sets)->lst_file)
		ft_del_vector((*sets)->lst_file, ft_destroy_t_arg);
	}
	else if (key == DELETE && (*((*sets)->lst_file))->next)
		ft_del_vector(&((*((*sets)->lst_file))->next), ft_destroy_t_arg);
	return (SUCCESS);
}
