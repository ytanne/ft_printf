/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:48:32 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/05 23:29:13 by yorazaye         ###   ########.fr       */
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
	ft_printf("GENERAL PRECISION TEST\n");
	printf("Real: Digit %+09.0d\n", 1);
	ft_printf("Mine: Digit %+09.0d\n", 1);
	printf("Real: Int %+6.3i\n", 1);
	ft_printf("Mine: Int %+6.3i\n", 1);
	printf("Real: Octal %+6.3o\n", 10);
	ft_printf("Mine: Octal %+6.3o\n", 10);
	printf("Real: hex %+6.3x\n", 12);
	ft_printf("Mine: hex %+6.3x\n", 12);
	printf("Real: Hex %+6.3X\n", 12);
	ft_printf("Mine: Hex %+6.3X\n", 12);
	printf("Real: Address %+018.0p\n", &a);
	ft_printf("Mine: Address %+018.0p\n", &a);
	printf("Real: Unsigned %+6.3u\n", 1);
	ft_printf("Mine: Unsigned %+6.3u\n", 1);
	printf("Real: String %+8.7s\n", "Hi");
	ft_printf("Mine: String %+8.7s\n", "Hi");
	printf("Real: Character %+8.7c\n", 'H');
	ft_printf("Mine: Character %+8.7c\n", 'H');
	printf("Real: Float %+8.3f\n", 3.2);
	ft_printf("Mine: Float %+8.3f\n", 3.2);
	/*
	ft_printf("----------------\n");
	ft_printf("GENERAL WIDTH TEST\n");
	printf("Digit %03d\n", 1);
	ft_printf("Digit %03d\n", 1);
	printf("Int %03i\n", 1);
	ft_printf("Int %03i\n", 1);
	printf("Octal %03o\n", 10);
	ft_printf("Octal %03o\n", 10);
	printf("hex %03x\n", 12);
	ft_printf("hex %03x\n", 12);
	printf("Hex %03X\n", 12);
	ft_printf("Hex %03X\n", 12);
	printf("Address %30p\n", &a);
	ft_printf("Address %30p\n", &a);
	printf("Unsigned %011u\n", 1);
	ft_printf("Unsigned %011u\n", 1);
	printf("String %03s\n", "Hi");
	ft_printf("String %03s\n", "Hi");
	printf("Character %03c\n", 'H');
	ft_printf("Character %03c\n", 'H');
	printf("Float %021f\n", 3.2);
	ft_printf("Float %021f\n", 3.2);
	ft_printf("----------------\n");
	printf("Test of percent is %10% and %d\n", 42);
	ft_printf("Test of percent is %10% and %d\n", 42);
	ft_printf("----------------\n");
	printf("Real: width test %05d\n", 18);
	ft_printf("Test: width test %05d\n", 18);
	ft_printf("----------------\n");
	printf("Real: test of width %015s. Hello\n", 0);
	ft_printf("Mine: test of width %015s. Hello\n", 0);
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
	printf("Real: %020p\n", (void *)&a);
	ft_printf("Mine: %020p\n", (void *)&a);
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
	printf ("Real - goo job %05d very well\n", 123);*/
	return (0);
}
