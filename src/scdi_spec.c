/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scdi_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:37:03 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/04 19:38:17 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		s_spec(va_list ap, t_printf *t)
{
	char	*str;

	if (!(str = va_arg(ap, char *)))
	{
		ft_putstr("(null)");
		return (6);
	}
	ft_putstr(str);
	return (ft_strlen(str));
}

int		c_spec(va_list ap, t_printf *t)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int		d_spec(va_list ap, t_printf *t)
{
	int		i;
	int		sp;
	char	fill;

	i = va_arg(ap, signed int);
	sp = t->w - ft_numlen(i, 10) - t->f_plus;
	fill = (t->f_zero) ? '0' : ' ';
	while (sp-- > 0)
		ft_putchar(fill);
	if (t->f_plus == 1 && i >= 0)
		ft_putchar('+');
	ft_putnbr(i);
	return (ft_numlen(i, 10));
}

int		i_spec(va_list ap, t_printf *t)
{
	int		i;
	int		sp;
	char	fill;

	i = va_arg(ap, signed int);
	sp = t->w - ft_numlen(i, 10) - t->f_plus;
	fill = (t->f_zero) ? '0' : ' ';
	while (sp-- > 0)
		ft_putchar(fill);
	if (t->f_plus == 1 && i > 0)
		ft_putchar('+');
	ft_putnbr(i);
	return (ft_numlen(i, 10));
}

int		p_spec(va_list ap, t_printf *t)
{
	void	*b;
	int		sp;
	char	fill;

	sp = t->w - 14 - t->f_plus;
	fill = (t->f_zero) ? '0' : ' ';
	if (t->f_zero)
		ft_putstr("0x");
	while (sp-- > 0)
		ft_putchar(fill);
	if (!t->f_zero)
		ft_putstr("0x");
	b = va_arg(ap, void *);
	return (ft_putaddress_ll(b));
}
