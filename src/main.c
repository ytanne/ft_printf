/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:48:32 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/31 16:35:33 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	char *str = "He%s W\\rld of %+-0d. OK%c\n";
	ft_printf(str, "llo", 42, 63);
	ft_printf("----------------\n");
	printf ("Real - Characters: %c %c \n", 'a', 65);
	ft_printf ("Mine - Characters: %c %c \n", 'a', 65);
	ft_printf("----------------\n");
	printf ("Real - Decimals: %d %ld\n", 1977, 650000L);
	ft_printf("----------------\n");
	printf ("Real - Preceding with blanks: %10d \n", 1977);
	ft_printf("----------------\n");
	printf ("Real - Preceding with zeros: %010d \n", 1977);
	ft_printf("----------------\n");
	printf ("Real - Some different radices: %d %x %o %#x %#o \n", 100, 13, 100, 100, 100);
	printf ("Mine - Some different radices: %d %x %o -- --\n", 100, 13, 100, 100, 100);
	ft_printf("----------------\n");
	printf ("Real - floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	ft_printf("----------------\n");
	printf ("Real - Width trick: %*d \n", 5, 10);
	ft_printf("----------------\n");
	printf ("Real - %10s \n", "A string");
	ft_printf("----------------\n");
	printf ("Real - goo job %05d very well\n", 123);
	return (0);
}
