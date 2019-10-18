/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_t_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:32:53 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/18 13:16:09 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_select.h"

static int		ft_get_file_type(char *value)
{
	struct stat	cur_file;

	if (access(value, F_OK) == -1)
		return (NOT_FIL);
	lstat(value, &cur_file);
	if (S_ISLNK(cur_file.st_mode))
		return (SFT_LNK);
	else if (S_ISDIR(cur_file.st_mode))
		return (DIR_FIL);
	else if (S_ISCHR(cur_file.st_mode))
		return (CHR_DEV);
	else if (S_ISBLK(cur_file.st_mode))
		return (BLK_DEV);
	else
		return (REG_FIL);
}

t_arg			*ft_create_t_arg(char *value)
{
	t_arg		*new;

	if ((new = (t_arg *)malloc(sizeof(t_arg))) == NULL)
		return (NULL);
	ft_bzero((void *)new, sizeof(t_arg));
	if ((new->file_name = ft_strdup(value)) == NULL)
	{
		ft_destroy_t_arg((void **)&new);
		return (NULL);
	}
	new->file_type = ft_get_file_type(value);
	new->chose = 0;
	return (new);
}

void			ft_destroy_t_arg(void **old_void)
{
	t_arg		**old;

	old = (t_arg **)old_void;
	if (old == NULL || *old == NULL)
		return ;
	ft_strdel(&((*old)->file_name));
	ft_bzero((void *)(*old), sizeof(t_arg));
	ft_memdel((void **)old);
}
