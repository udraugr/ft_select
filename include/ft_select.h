/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:16:43 by udraugr-          #+#    #+#             */
/*   Updated: 2019/10/24 12:56:41 by udraugr-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include "../libftprintf/ft_printf/printf.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <termios.h>
# include <term.h>
# include <sys/ioctl.h>
# include <signal.h>

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
# define ARROW_LEFT 1792836
# define ARROW_RIGTH 1792835
# define ARROW_UP 1792833
# define ARROW_DOWN 1792834
# define SPACE 32
# define BACKSPACE 127
# define DELETE 458961790
# define ESC 27
# define F 70
# define F_SMALL 102
# define PRINTABLE(x) (x >= 32 && x <= 126) ? 1 : 0

typedef struct		s_arg
{
	char			*file_name;
	int				file_type;
	int				chose;
}					t_arg;

typedef struct		s_setting
{
	t_vector		*lst_file;
	int				column;
	int				row;
	int				all_files;
	int				max_len_file;
	int				find_mode;
	int				find_i;
	char			find_file[4096];
	char			*find_mes;
	struct termios	def_sets;
	struct termios	my_sets;
	char			*ve;
	char			*vi;
	char			*cl;
}					t_setting;

t_arg				*ft_create_t_arg(char *value);
void				ft_destroy_t_arg(void **old_void);

void				ft_get_win_size(t_setting *sets);
void				ft_get_max_len_name(t_setting *sets);
int					init_setting(t_setting **sets, t_vector *lst_file);

int					ft_check_size_window(t_setting **sets);

void				ft_drawing(t_setting **sets);
void				ft_wait_input(void);
void				ft_signal_intercept(void);

int					ft_del_file(t_setting **sets, int key);
void				ft_moves(t_setting **sets, unsigned long long key);
void				ft_find_mode(t_setting **sets, unsigned long long key);

void				ft_end_work(int sign);

void				set_setting(struct termios *sets);

t_setting			**ft_take_my_setting(t_setting **sets);

#endif
