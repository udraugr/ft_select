/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:35:59 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/16 16:50:08 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

/*static int				ft_key_distribution(t_setting **sets,
												unsigned long long key)
{
	if (key == ENTER || key == ESC)
		return (EXIT);
	else if (key == ARROW_LEFT || key == ARROW_RIGTH ||
			key == ARROW_DOWN || key == ARROW_UP)
	{	
		ft_moves(sets, key);
		return (SUCCESS);
	}
	else if (key == DELETE || key == BACKSPACE)
		return (ft_del_file(sets, key));
	else
	{
		ft_find_mode();
		return (SUCCESS);
	}
}*/

void					ft_wait_input(void)
{
	unsigned char		buff[1024];
	int					read_bite;
	unsigned long long	key;
	int					i;
	t_setting			**sets;

	sets = ft_take_my_setting(NULL);
	set_setting(&((*sets)->my_sets));
	//drawing(sets);
	while (sets && (*sets)->lst_file &&
			(read_bite = read(STDOUT_FILENO, buff, 4)))
	{
		buff[read_bite] = '\0';
		key = buff[i];
		i = 0;
		while (buff[++i])
			key = key * 128 + buff[i];
		ft_printf("%llu\n", key);
		/*if (ft_key_distribution(sets, key) == EXIT)
		{
			ft_end_work();
		}*/
		//drawing(sets);
	}
}
