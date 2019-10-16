/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:16:43 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/16 15:44:16 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libftprintf/ft_printf/printf.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <termios.h>
# include <sys/ioctl.h>

# define FAIL 1
# define SUCCESS 0
# define EXIT 1000

# define NOT_FIL 40
# define REG_FIL 50
# define DIR_FIL 60
# define SFT_LNK 70
# define SOKET 80
# define FIFO 90
# define BLK_DEV 100
# define CHR_DEV 110

# define ENTER 10
# define BACKSPACE 127
# define ARROW_LEFT 454084
# define ARROW_RIGTH 454083
# define ARROW_UP 454081
# define ARROW_DOWN 454082
# define SPACE 32
# define DELETE 58120702
# define ESC 27

typedef struct		s_arg
{
	char			*file_name;
	int				file_type;
	int				chose;
}					t_arg;

typedef struct		s_setting
{
	t_vector		**lst_file;
	int				column;
	int				row;
	int				cur_pos;
	int				max_len_file;
	struct termios	def_sets;
	struct termios	my_sets;
}					t_setting;

t_arg				*ft_create_t_arg(char *value);
void				ft_destroy_t_arg(void **old_void);

void				ft_get_win_size(t_setting *sets);
void				ft_get_max_len_name(t_setting *sets);
int					init_setting(t_setting **sets, t_vector **lst_file);

void				ft_wait_input(void);

void				set_setting(struct termios *sets);

t_setting			**ft_take_my_setting(t_setting **sets);

#endif
