/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:20:53 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/20 14:52:54 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_numlen_base(uintmax_t nb, int base)
{
	int		l;

	if (nb <= 0)
	{
		l = 1;
		nb *= -1;
	}
	else
		l = 0;
	while (nb)
	{
		l++;
		nb /= base;
	}
	return (l);
}

int				ft_putnbr_base(uintmax_t value, int base, int xl)
{
	char	*c;
	int		l[2];

	if (base == 10)
	{
		l[0] = ft_numlen_uim(value);
		ft_putnbr_uim(value);
		return (l[0]);
	}
	l[0] = ft_numlen_base(value, base);
	l[1] = l[0];
	if (!(c = ft_strnew(l[0])))
		return (0);
	c[l[0]] = '\0';
	while (--l[0] >= 0)
	{
		c[l[0]] = (value % base <= 9) ? value % base + '0' :\
		value % base - 10 + ('a' - xl * 32);
		value /= base;
	}
	ft_putstr(c);
	free(c);
	return (l[1]);
}

int				ft_putnbr_u(uintmax_t value, int xl)
{
	char	*c;
	int		l;

	l = ft_numlen_base(value, 10);
	c = ft_strnew(l);
	c[l] = '\0';
	while (l >= 0)
	{
		c[--l] = value % 10 + '0';
		value /= 10;
	}
	ft_putstr(c);
	ft_strdel(&c);
	return (l);
}
