# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 18:05:44 by yorazaye          #+#    #+#              #
#    Updated: 2019/11/13 15:34:52 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src

INC = includes

F_N = ft_printf print_struct csdi fwpl ouUxX ft_ls_do others
F_H = ft_printf.h

F_C = $(patsubst %, $(SRC)/%, $(addsuffix .c, $(F_N)))

F_O = $(addsuffix .o, $(F_N))

all: $(NAME)

$(NAME):
	@make -C libft/
	gcc -o test $(F_C) -I $(INC) -L libft -lft

compile:
	@make -C libft/
	@gcc -c $(F_C) -I $(INC)
	ar rc $(NAME) $(F_O) libft/*.o
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
