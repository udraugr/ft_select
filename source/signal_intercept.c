/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_intercept.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:02:34 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/17 16:08:36 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void			ft_stop_work(int sign)
{
	t_setting	**sets;

	sets = 0;
	if (sign == SIGTSTP)
	{
		sets = ft_take_my_setting(0);
		set_setting(&((*sets)->def_sets));
	}
}

static void			ft_cont_work(int sign)
{
	if (sign == SIGCONT)
	{
		ft_wait_input();
	}
}

static void			ft_change_size(int sign)
{
	t_setting	**sets;

	sets = 0;
	if (sign == SIGWINCH)
	{
		sets = ft_take_my_setting(0);
		if (sets)
		{
			ft_get_win_size(*sets);
		}
		signal(SIGWINCH, ft_change_size);
	}
}

void				ft_signal_intercept(void)
{
	signal(SIGQUIT, ft_end_work);
	signal(SIGINT, ft_end_work);
	signal(SIGABRT, ft_end_work);
	signal(SIGTERM, ft_end_work);
	signal(SIGTSTP, ft_stop_work);
	signal(SIGCONT, ft_cont_work);
	signal(SIGWINCH, ft_change_size);
}
