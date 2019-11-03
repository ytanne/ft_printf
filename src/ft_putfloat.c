/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:19:37 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/02 23:34:06 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static double	ft_roundup(double n, int afterpoint)
{
	double	pwr;
	double	numbs;

	pwr = ft_pow(10, afterpoint + 1);
	numbs = n * pwr - (double)((int)(n * pwr / 10) * 10);
	if (numbs > 5.0)
		n = ((n * (double)(pwr / 10)) + 1) * 10 / pwr;
	return (n);
}

int				ft_putfloat(float n, int afterpoint)
{
	int		first;
	int		fl;
	float	remainder;
	int		temp;

	temp = afterpoint;
	first = (int)n;
	fl = 0;
	remainder = n - (float)first;
	ft_putnbr(first);
	if (afterpoint == 0)
		return (ft_numlen(first, 10));
	ft_putchar('.');
	while (afterpoint--)
	{
		remainder *= 10;
		first = (int)remainder;
		remainder -= (float)first;
		ft_putnbr(first);
		if (fl == 0 && (fl = 1))
			remainder = ft_roundup(remainder, afterpoint);
	}
	return (ft_numlen(first, 10) + 1 + temp);
}

int				ft_putdouble(double n, int afterpoint)
{
	int		first;
	double	remainder;
	int		temp;

	temp = afterpoint;
	first = (int)n;
	remainder = n - (double)first;
	remainder = ft_roundup(remainder, afterpoint);
	ft_putnbr(first);
	if (afterpoint == 0)
		return (ft_numlen(first, 10));
	ft_putchar('.');
	while (afterpoint--)
	{
		remainder *= 10;
		first = (int)remainder;
		remainder -= (double)first;
		ft_putnbr(first);
	}
	return (ft_numlen(first, 10) + 1 + temp);
}
