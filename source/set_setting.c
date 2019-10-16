/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_setting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:02:59 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/16 14:52:48 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

void		set_setting(struct termios *sets)
{
	tcsetattr(STDIN_FILENO, TCSADRAIN, sets);
}
