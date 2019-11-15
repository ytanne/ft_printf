/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:19:37 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/14 22:37:17 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_pow_ui(int ap)
{
	long double	r;

	r = 1.0;
	while (ap--)
		r *= 10.0;
	return (r);
}

static void			ft_roundup(long double *n, int afterpoint)
{
	long double	pwr;
	long double	numbs;

	pwr = ft_pow_ui(afterpoint + 1);
	numbs = (long double)((uintmax_t)(*n * pwr / 10) * 10);
	numbs = *n * pwr - numbs;
	if (numbs > 5.0)
		*n = ((*n * (long double)(pwr / 10)) + 1) * 10 / pwr;
}

int					ft_putdouble(long double n, int afterpoint, int h1, int h2)
{
	int			temp;
	int			first;
	long double	remainder;

	temp = afterpoint;
	if (n < 0 && (n *= -1) && h2 == 0)
		ft_putchar('-');
	first = (int)n;
	if ((remainder = n - (long double)first) < 0)
		remainder *= -1;
	ft_roundup(&remainder, afterpoint);
	first += (int)remainder;
	remainder -= ((int)remainder > 0) ? 1.0 : 0.0;
	ft_putnbr(first);
	if (afterpoint == 0 && h1 == -1)
		return (ft_numlen(first, 10));
	ft_putchar('.');
	while (afterpoint--)
	{
		remainder *= 10;
		first = (int)remainder;
		remainder -= (long double)first;
		ft_putnbr(first);
	}
	return (ft_numlen(first, 10) + 1 + temp);
}

/*
int				ft_putdouble(long double n, int afterpoint)
{
	int			temp;
	int			first;
	long double	remainder;

	temp = afterpoint;
	first = (int)n;
	if ((remainder = n - (long double)first) < 0)
		remainder *= -1;
	remainder = ft_roundup(remainder, afterpoint);
	ft_putnbr(first);
	if (afterpoint == 0)
		return (ft_numlen(first, 10));
	ft_putchar('.');
	while (afterpoint--)
	{
		remainder *= 10;
		first = (int)remainder;
		remainder -= (long double)first;
		ft_putnbr(first);
	}
	return (ft_numlen(first, 10) + 1 + temp);
}
*/