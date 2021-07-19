# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wtaylor <wtaylor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 21:40:19 by wtaylor           #+#    #+#              #
#    Updated: 2020/12/22 15:24:40 by wtaylor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	libftprintf.a

SRC		=	src/ft_printf.c \
			src/ft_displaychar.c \
			src/ft_displayhex_upper.c \
			src/ft_displaynumber.c \
			src/ft_displaystr.c \
			src/ft_getnumber.c \
			src/ft_putpad.c \
			src/ft_width.c \
			src/ft_displayhex_lower.c \
			src/ft_displayint.c \
			src/ft_displaypointer.c \
			src/ft_displayui.c \
			src/ft_getwidth.c \
			src/ft_tabinit.c \
			src/int_putchar.c \

OBJ		=	$(SRC:.c=.o)

FLAGS	=	-Wall -Werror -Wextra

%.o: %.c src/ft_printf.h
	gcc $(FLAGS) -c $< -o $@

$(NAME):	$(OBJ) 
			make -C ./ft_libft/
			cp ./ft_libft/libft.a $(NAME)
			ar rcs $(NAME) $?


all:	$(NAME)

clean:
			rm -rf $(OBJ)
			make clean -C ./ft_libft/
	
clean_nolib:
			rm -rf $(OBJ)

fclean: clean_nolib
			make fclean -C ./ft_libft/
			rm -rf $(NAME)
	
re: fclean all

.PHONY: clean_nolib
