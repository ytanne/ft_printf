/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:20:53 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/30 21:37:07 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int nb, int base)
{
	int		l;

	l = 0;
	while (nb)
	{
		l++;
		nb /= base;
	}
	return (l);
}

void		ft_putnb_base(int value, int base)
{
	char	*c;
	int		l;

	l = ft_numlen(value, base);
	c = ft_strnew(l);
	c[l] = '\0';
	while (value && (l >= 0))
	{
		c[--l] = value % base + '0';
		value /= base;
	}
	ft_putstr(c);
	ft_strdel(&c);
}

int			main(void)
{
	ft_putnb_base(140, 8);
	return (0);
}
