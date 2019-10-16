/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:19:07 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/16 15:35:39 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static void		ft_usage(void)
{
	ft_putstr("./ft_select [list of files]!\n");
}

static int		ft_parse_argv(char **argv, int argc, t_vector **lst_file)
{
	int			i;
	t_arg		*cur_file;

	i = 0;
	while (i < argc)
	{
		if ((cur_file = ft_create_t_arg(argv[i])) == NULL)
		{
			ft_delall_vector(lst_file, ft_destroy_t_arg);
		}
		*lst_file = ft_add_vector(*lst_file, cur_file);
		++i;
	}
	return (SUCCESS);
}

int				main(int argc, char **argv)
{
	t_vector	*lst_file;
	t_setting	*sets;

	lst_file = 0;
	sets = 0;
	if (argc == 1)
		ft_usage();
	else if (argc > 1)
	{
		if (ft_parse_argv(&argv[1], argc - 1, &lst_file) == FAIL ||
				init_setting(&sets, &lst_file) == FAIL)
			return (FAIL);
		ft_take_my_setting(&sets);
		ft_wait_input();
	}
	return (0);
}
