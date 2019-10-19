/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 14:32:51 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/19 13:09:47 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	while (*str1 || *str2)
	{
		if (*str1 != *str2)
			return (*((unsigned char*)str1) - *((unsigned char*)str2));
		str1++;
		str2++;
	}
	return (*((unsigned char*)str1) - *((unsigned char*)str2));
}
