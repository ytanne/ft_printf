/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scdip_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:38:43 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/06 00:24:36 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		s_spec(va_list ap, t_printf *t)
{
	char	*str;

	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	t->f_plus = 0;
	deal_width(ft_strlen(str), t);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		c_spec(va_list ap, t_printf *t)
{
	char	c;

	t->f_plus = 0;
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
	if (i < 0)
		t->f_plus = 0;
	ft_putnbr(i);
	return (ft_numlen(i, 10));
}

int		i_spec(va_list ap, t_printf *t)
{
	int		i;
	int		l;

	i = va_arg(ap, signed int);
	l = ft_numlen(i, 10);
	if (i < 0)
		t->f_plus = 0;
	deal_width(l, t);
	ft_putnbr(i);
	return (l);
}

int		p_spec(va_list ap, t_printf *t)
{
	void	*b;
	char	fill;
	int		l;
	int		w;
	int		pc;

	pc = t->p - 12;
	w = (t->p > 0) ? t->w - 14 - pc :\
	t->w - 14;
	if (t->f_zero && (t->p < 0))
		ft_putstr("0x");
	fill = (t->f_zero && (t->p < 0)) ? '0' : ' ';
	while (w-- > 0)
		ft_putchar(fill);
	if (!t->f_zero || (t->p >= 0))
		ft_putstr("0x");
	while (pc-- > 0)
		ft_putchar('0');
	/*
	t->f_plus = 0;
	if (t->f_zero || !(t->p > 0))
		ft_putstr("0x");
	l = (t->p > 0) ? 12 : 14;
	deal_width(l, t);
	if (!t->f_zero)
		ft_putstr("0x");
	*/
	b = va_arg(ap, void *);
	return (ft_putaddress_ll(b));
}
