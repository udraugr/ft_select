/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_intercept.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:02:34 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/27 17:06:32 by udraugr-         ###   ########.fr       */
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
		ft_putstr_fd((*sets)->ve, 2);
		signal(SIGTSTP, SIG_DFL);
		ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
	}
}

static void			ft_cont_work(int sign)
{
	t_setting	**sets;

	sets = 0;
	if (sign == SIGCONT)
	{
		sets = ft_take_my_setting(0);
		set_setting(&((*sets)->my_sets));
		ft_putstr_fd((*sets)->vi, 2);
		ft_putstr_fd((*sets)->cl, 2);
		ft_get_win_size(*sets);
		if (ft_check_size_window(sets))
			ft_drawing(sets);
		signal(SIGCONT, ft_cont_work);
		signal(SIGTSTP, ft_stop_work);
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
			ft_putstr_fd((*sets)->cl, 2);
			ft_get_win_size(*sets);
			if (ft_check_size_window(sets))
				ft_drawing(sets);
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
