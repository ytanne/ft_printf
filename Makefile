# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 18:05:44 by yorazaye          #+#    #+#              #
#    Updated: 2019/10/30 21:50:15 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprinf.a

SRC = src

INC = includes

OUT = bin

F_N = ft_printf ft_printf_struct string_spec main

F_H = ft_printf.h

F_C = $(patsubst %, $(SRC)/%, $(addsuffix .c, $(F_N)))

F_O = $(patsubst %, $(OUT)/%, $(addsuffix .o, $(F_N)))

all: $(NAME)

$(NAME):
	@make -C libft/
	gcc -o test $(F_C) -I $(INC) -L libft -lft

compile:
	@make -C libft/
	@gcc -c $(F_C) -I $(INC)
	ar rc $(NAME) $(F_O)
	@ranlib $(NAME)

debug: fclean
	@make -C libft/
	gcc -o test $(F_C) -I $(INC) -L libft -lft -g
	lldb test

clean:
	@rm -f libft/*.o
	rm -f $(F_O)

fclean: clean
	@rm -rf test*
	@rm -f libft/libft.a
	rm -f $(NAME)

re: fclean all
