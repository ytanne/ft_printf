/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:48:32 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/04 17:01:17 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				main(void)
{
	int		a;
	char	*str = "He%s W\\rld of %+-0d. OK%c\n";

	a = 1;
	ft_printf(str, "llo", -42, 63);
	ft_printf("----------------\n");
	printf("Real: width test %5d\n", 18);
	ft_printf("Real: width test %5i\n", 18);
	ft_printf("----------------\n");
	printf("Real: test of width %s. Hello\n", 0);
	ft_printf("Mine: test of width %s. Hello\n", 0);
	ft_printf("----------------\n");
	printf("Real: test # for octal %#o for %o\n", 12, 12);
	ft_printf("Mine: test # for octal %#o for %o\n", 12, 12);
	printf("Real: test # for hex %#x for %x\n", 12, 12);
	ft_printf("Mine: test # for hex %#x for %x\n", 12, 12);
	printf("Real: test # for HEX %#X for %X\n", 12, 12);
	ft_printf("Mine: test # for HEX %#X for %X\n", 12, 12);
	printf("Real: test # for float %#f for %f\n", (double)7.123, (double)7.123);
	ft_printf("Mine: test # for float %#f for %f\n", (double)7.123, (double)7.123);
	ft_printf("----------------\n");
	printf("Real: check of sign %i and %s\n", 1, "12");
	ft_printf("----------------\n");
	printf("Real: unsigned int %u\n", 4294967295);
	ft_printf("Mine: unsinged int %u\n", 4294967295);
	ft_printf("----------------\n");
	printf("Real: percentage %%\n");
	ft_printf("Mine: percantage %%\n");
	ft_printf("----------------\n");
	ft_printf("Printing memory stuff\n");
	printf("Real: %p\n", (void *)&a);
	ft_printf("Mine: %p\n", (void *)&a);
	ft_printf("----------------\n");
	printf ("Real - Characters: %c %c \n", 'a', 65);
	ft_printf ("Mine - Characters: %c %c \n", 'a', 65);
	ft_printf("----------------\n");
	printf ("Real - Decimals: %d %ld\n", 1977, 650000L);
	ft_printf("----------------\n");
	printf ("Real - Preceding with blanks: %d \n", 1977);
	ft_printf("----------------\n");
	printf ("Real - Preceding with zeros: %010d \n", 1977);
	ft_printf("----------------\n");
	printf ("Real - Some different radices: %d %x %o %#x %#o \n", 100, 13, 100, 100, 100);
	ft_printf("Mine - Some different radices: %d %x %o -- --\n", 100, 13, 100);
	ft_printf("----------------\n");
	//printf ("Real - floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416);
	printf ("Real - floats: %+f\n", 3.1416146);
	ft_printf("Mine - floats: %+f\n", 3.1416146);
	ft_printf("----------------\n");
	printf ("Real - Width trick: %*d \n", 5, 10);
	ft_printf("----------------\n");
	printf ("Real - %10s \n", "A string");
	ft_printf("----------------\n");
	printf ("Real - goo job %05d very well\n", 123);
	return (0);
}
