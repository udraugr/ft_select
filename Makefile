NAME := ft_select

GCC := clang -Wall -Wextra -Werror
INCLUDE := -I include
LIBFTPRINTF := -L libftprintf -lftprintf -ltermcap

SRC :=	\
	source/fts_t_arg.c\
	source/init_setting.c\
	source/main.c\
	source/set_setting.c\
	source/wait_input.c\
	source/ft_take_my_setting.c\
	source/ft_end_work.c\
	source/signal_intercept.c\
	source/ft_del_file.c\
	source/ft_moves.c\
	source/ft_find_mode.c\
	source/drawing.c\
	source/chose.c

OBJ := $(patsubst %.c, %.o, $(SRC))

all: $(NAME)

lib_create:
	@make -C libftprintf

$(NAME): lib_create $(OBJ)
	@$(GCC) $(LIBFTPRINTF) $(INCLUDE) $(OBJ) -o $(NAME)
	@printf "\rCreate $(NAME)!                           \n"
	@printf "\033[?25h"

%.o: %.c
	@$(GCC) -c $< -o $@
	@printf "\033[?25l"
	@printf "\rCompiling: $<                              "

clean:
	@/bin/rm -f $(OBJ)
	@make -C libftprintf fclean
	@printf "\rDell all objects and libs!\n"

fclean: clean
	@/bin/rm -f $(NAME)
	@printf "\rDell $(NAME)!\n"

re: fclean all
