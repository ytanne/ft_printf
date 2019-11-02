/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 01:20:53 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/01 15:05:10 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	#include "libft.h"
*/

int		ft_numlen(int nb, int base)
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

int		ft_putnbr_base(int value, int base, int xl)
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
	while (value && (l >= 0))
	{
		c[--l] = (value % base <= 9) ? value % base + '0' :\
		value % base - 10 + ('a' - xl * 32);
		value /= base;
	}
	ft_putstr(c);
	ft_strdel(&c);
	return (l);
}

/*
**	int			main(void)
**	{
**		ft_putnb_base(2147483647, );
**		return (0);
**	}
*/
