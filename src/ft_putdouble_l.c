/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdouble_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:19:37 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/16 16:11:52 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	ft_roundup(long double n, int afterpoint)
{
	long double	pwr;
	long double	numbs;
	long double tmp;

	tmp = n;
	pwr = ft_pow_ui(afterpoint);
	while (afterpoint--)
	{
		tmp *= 10.0;
		tmp = tmp - (long double)((int)tmp);
	}
	if (tmp > 0.5)
		n = n + 1.0 / pwr;
	return (n);
}

static void			deal_ap(int ap, long double *rr, int p)
{
	int			first;
	long double diff;
	long double cs;

	ft_putchar('.');
	if (rr[1] < rr[0])
		rr[0] = 0;
	diff = (rr[1] - rr[0]);
	diff /= (p == 6) ? 10 : 1;
	cs = 5 / ft_pow_ui(ap + 1);
	while (ap--)
	{
		rr[0] *= 10.0;
		diff *= 10.0;
		cs *= 10.0;
		first = (ap == 0 && diff > cs) ? (int)(rr[0] + 1.0) :
		(int)(rr[0] + diff);
		rr[0] -= (long double)(first);
		ft_putnbr(first);
	}
}

int					ft_putd_l(long double n, int ap,
t_print *t, char sp)
{
	int			temp;
	intmax_t	first;
	long double	remainder[2];

	temp = ap;
	if (n >= 0 && t->f_p == 1 && sp == ' ')
		ft_putchar('+');
	if (n < 0 && (n *= -1) && sp == ' ')
		ft_putchar('-');
	first = (intmax_t)n;
	if ((remainder[0] = n - (long double)first) < 0)
		remainder[0] *= -1;
	remainder[1] = ft_roundup(remainder[0], ap);
	first += (t->p_n != 6 || first != 0) ? (int)remainder[1] : 0;
	remainder[1] -= ((int)remainder[1] > 0
	&& (t->p_n != 6 || first != 0)) ? 1.0 : 0.0;
	ft_putnbr_im((intmax_t)first);
	if (ap == 0 && t->f_h == -1)
		return (ft_numlen(first, 10));
	deal_ap(ap, remainder, t->p_n);
	return (ft_numlen(first, 10) + 1 + temp);
}
