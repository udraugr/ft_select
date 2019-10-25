/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chose.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 20:11:24 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/25 20:14:36 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void			ft_chose(t_setting **sets)
{
	t_vector	*tmp;

	((t_arg *)((*sets)->lst_file->content))->chose =
		!((t_arg *)((*sets)->lst_file->content))->chose;
	tmp = (*sets)->lst_file;
	if (tmp->next)
		tmp = tmp->next;
	else
		while (tmp->previous)
			tmp = tmp->previous;
	(*sets)->lst_file = tmp;
}
