# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/23 20:13:16 by oelazzou          #+#    #+#              #
#    Updated: 2019/12/10 15:55:00 by oelazzou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
LIBFT_PATH = libft/
INC = -I ./includes/ -I $(LIBFT_PATH)
SRC_DIR = ./src/
OBJ_DIR = ./obj/
FLAGS = -Wall -Wextra -Werror

SRC_NAME = 	arguments.c \
		get_time.c \
		create_path.c \
		error.c \
		file_mode.c \
		flag_a.c \
		freeing.c \
		get_ids.c \
		get_file_info.c \
		l_permissions.c \
		ls_l.c \
		ls_simple.c \
		main.c \
		node.c \
		print_free.c \
		printing.c \
		print_align.c \
		sort_directories.c \
		sort_error.c \
		is_exist.c \
		color.c \
		ft_capr.c \
		reg_files.c \
		stock_dirs.c \
		stack_functions.c

SRCS = $(addprefix $(SRC_DIR), $(SRC_NAME))
OBJS = $(addprefix $(OBJ_DIR), $(SRC_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJS) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p obj
	@gcc -c $(INC) $^ -o $@
clean:
	@make clean -C $(LIBFT_PATH)
	@rm -rf $(OBJ_DIR)
fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@rm -f $(NAME)
re: fclean all
