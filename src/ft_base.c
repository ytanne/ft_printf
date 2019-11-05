/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:20:53 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/04 10:53:53 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_numlen(unsigned int nb, int base)
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

int		ft_putnbr_base(unsigned int value, int base, int xl)
{
	char	*c;
	int		l;

	if (base == 10)
	{
		c = ft_itoa(value);
		ft_putstr(c);
		l = ft_strlen(c);
		ft_strdel(&c);
		return (l);
	}
	l = ft_numlen(value, base);
	c = ft_strnew(l);
	c[l] = '\0';
	while (l >= 0)
	{
		c[--l] = (value % base <= 9) ? value % base + '0' :\
		value % base - 10 + ('a' - xl * 32);
		value /= base;
	}
	ft_putstr(c);
	ft_strdel(&c);
	return (l);
}

int		ft_putnbr_u(unsigned int value, int xl)
{
	char	*c;
	int		l;

	l = ft_numlen(value, 10);
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
