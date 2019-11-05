/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scdi_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:37:03 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/04 20:59:24 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		s_spec(va_list ap, t_printf *t)
{
	char	*str;

	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	deal_width(ft_strlen(str), t);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		c_spec(va_list ap, t_printf *t)
{
	char	c;

	deal_width(1, t);
	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int		d_spec(va_list ap, t_printf *t)
{
	int		i;

	i = va_arg(ap, signed int);
	deal_width(ft_numlen(i, 10), t);
	if (t->f_plus == 1 && i >= 0)
		ft_putchar('+');
	ft_putnbr(i);
	return (ft_numlen(i, 10));
}

int		i_spec(va_list ap, t_printf *t)
{
	int		i;

	i = va_arg(ap, signed int);
	deal_width(ft_numlen(i, 10), t);
	if (t->f_plus == 1 && i > 0)
		ft_putchar('+');
	ft_putnbr(i);
	return (ft_numlen(i, 10));
}

int		p_spec(va_list ap, t_printf *t)
{
	void	*b;

	if (t->f_zero)
		ft_putstr("0x");
	deal_width(14, t);
	if (!t->f_zero)
		ft_putstr("0x");
	b = va_arg(ap, void *);
	return (ft_putaddress_ll(b));
}
