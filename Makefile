# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/14 15:38:31 by sgalasso          #+#    #+#              #
#    Updated: 2018/11/14 02:42:43 by sgalasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = srcs/main.c \
	  srcs/ft_srt_paths.c \
	  srcs/ft_srt_dircontent.c \
	  srcs/ft_set_dircontent.c \
	  srcs/ft_get_dircontent.c \
	  srcs/ft_rec_dircontent.c \
	  srcs/ft_get_perms.c \
	  srcs/ft_syscall.c \
	  srcs/ft_create_dir.c \
	  srcs/ft_parse_entry.c \
	  srcs/ft_free_exit.c \

OBJ = $(SRC:.c=.o)

INCLUDES = includes/

all: lib $(NAME)

$(NAME):	$(OBJ)
	gcc -Wall -Wextra -Werror -o $(NAME) \
	libft/libft.a lib_printf/libftprintf.a $(OBJ) \
   	-I $(INCLUDES)

lib:
	make -C libft/ && make -C lib_printf/

%.o: %.c $(INCLUDES)ft_ls.h Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJ) && make -C libft/ clean && make -C lib_printf/ clean

fclean:		clean
	rm -f $(NAME) && make -C libft/ fclean && make -C lib_printf/ fclean

re:			fclean all

.PHONY : all clean fclean re
