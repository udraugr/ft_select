/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_my_setting.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:23:30 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/16 15:39:33 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

t_setting				**ft_take_my_setting(t_setting **sets)
{
	static t_setting	*save_sets = 0;

	if (sets == 0)
	{
		return (&save_sets);
	}
	else
	{
		save_sets = (*sets);
		return (0);
	}
}
