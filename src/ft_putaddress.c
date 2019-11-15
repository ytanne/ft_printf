/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddress.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 13:27:59 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/14 11:30:10 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_numlen_ll(unsigned long long int nb, int base)
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

int				ft_putaddress(uintmax_t value)
{
	char					*c;
	int						l;

	if (value == 0)
	{
		ft_putstr("0");
		return (1);
	}
	l = ft_numlen_ll(value, 16);
	c = ft_strnew(l);
	c[l] = '\0';
	while (l >= 0)
	{
		if (value % 16 <= 9)
			c[--l] = value % 16 + '0';
		else
			c[--l] = value % 16 - 10 + 'a';
		value /= 16;
	}
	ft_putstr(c);
	ft_strdel(&c);
	return (l);
}
