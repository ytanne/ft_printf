/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:19:37 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/16 00:31:59 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_pow_ui(int ap)
{
	long double	r;
	long double ten;

	ten = 10.0;
	r = 1.0;
	while (ap--)
		r *= ten;
	return (r);
}

static void			ft_roundup(long double *n, int afterpoint)
{
	long double	pwr;
	long double	numbs;
	long double tmp;

	tmp = *n;
	pwr = ft_pow_ui(afterpoint);
	while (afterpoint--)
	{
		tmp *= 10.0;
		tmp = tmp - (long double)((int)tmp);
	}
	if (tmp > 0.5)
		*n = *n + 1.0 / pwr;
}

static void			deal_afterpoint(int ap, long double rr)
{
	int		first;

	ft_putchar('.');
	while (ap--)
	{
		rr *= 10.0;
		first = (int)rr;
		rr -= (long double)first;
		ft_putnbr(first);
	}
}

int					ft_putdouble(long double n, int ap, t_print *t, char sp)
{
	int			temp;
	int			first;
	long double	remainder;

	temp = ap;
	if (n >= 0 && t->f_p == 1 && sp == ' ')
		ft_putchar('+');
	if (n < 0 && (n *= -1) && sp == ' ')
		ft_putchar('-');
	first = (int)n;
	if ((remainder = n - (long double)first) < 0)
		remainder *= -1;
	ft_roundup(&remainder, ap);
	first += (int)remainder;
	remainder -= ((int)remainder > 0) ? 1.0 : 0.0;
	ft_putnbr(first);
	if (ap == 0 && t->f_h == -1)
		return (ft_numlen(first, 10));
	deal_afterpoint(ap, remainder);
	return (ft_numlen(first, 10) + 1 + temp);
}
