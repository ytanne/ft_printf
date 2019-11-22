# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 18:05:44 by yorazaye          #+#    #+#              #
#    Updated: 2019/11/19 16:54:53 by yorazaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = src

INC = includes

F_N = ft_printf print_struct cspdi fwpl oufxxl ft_ls_do ft_base\
	ft_putaddress dipuxo_av25 ft_putdouble ft_putdouble_l\
	others ft_extra

F_H = ft_printf.h

F_C = $(patsubst %, $(SRC)/%, $(addsuffix .c, $(F_N)))

F_O = $(addsuffix .o, $(F_N))

all: $(NAME)

$(NAME):
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
