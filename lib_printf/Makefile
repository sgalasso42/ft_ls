# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/27 19:14:31 by sgalasso          #+#    #+#              #
#    Updated: 2018/11/13 14:10:59 by sgalasso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	srcs/ft_printf.c \
		srcs/ft_process.c \
		srcs/ft_itoa_base.c \
		srcs/ft_uitoa_base.c \
		srcs/ft_conversion.c \
		srcs/ft_parse_ty.c \
		srcs/ft_parse_fl.c \
		srcs/ft_parse_le.c \
		srcs/ft_parse_wi.c \
		srcs/ft_parse_pr.c \
		srcs/ft_bitlen.c \
		srcs/ft_unicode.c \
		srcs/ft_unicode_str.c \
		srcs/ft_is_nb.c \
		srcs/ft_prefix.c \
		srcs/ft_conv_size_alpha.c \
		srcs/ft_digit_prepa.c \
		utils/ft_purge.c \
		utils/ft_strlen.c \
		utils/ft_nbrlen.c \
		utils/ft_memset.c \
		utils/ft_bzero.c \
		utils/ft_gencat.c \
		utils/ft_strcat.c \
		utils/ft_ccat.c \
		utils/ft_atoi.c \
		utils/ft_str_up.c \
		utils/ft_memmove.c \
		utils/ft_memcpy.c \

OBJS =	$(SRCS:.c=.o)

INCLUDES = ../includes/

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS) && ranlib $(NAME)

%.o: %.c $(INCLUDES)ft_printf.h Makefile
	gcc -Wall -Wextra -Werror -o $@ -c $< -I $(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY : all clean fclean re
