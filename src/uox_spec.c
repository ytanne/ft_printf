/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uox_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:42:08 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/06 00:23:57 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		o_spec(va_list ap, t_printf *t)
{
	int	r;
	unsigned int oc;

	r = 1;
	t->f_plus = 0;
	oc = va_arg(ap, unsigned int);
	r = ft_numlen(oc, 8);
	deal_width(r, t);
	if (t->f_hash == 1)
		ft_putchar('0');
	ft_putnbr_base(oc, 8, 0);
	return (r);
}

int		x_spec(va_list ap, t_printf *t)
{
	int				r;
	unsigned int	x;

	t->f_plus = 0;
	x = va_arg(ap, unsigned int);
	r = ft_numlen(x, 16);
	deal_width(r, t);
	if (t->f_hash == 1)
		ft_putstr("0x");
	ft_putnbr_base(x, 16, 0);
	return (r);
}

int		xl_spec(va_list ap, t_printf *t)
{
	int	r;
	unsigned int	X;

	t->f_plus = 0;
	X = va_arg(ap, unsigned int);
	r = ft_numlen(X, 16);
	deal_width(r, t);
	if (t->f_hash == 1)
		ft_putstr("0x");
	ft_putnbr_base(X, 16, 1);
	return (r);
}

int		u_spec(va_list ap, t_printf *t)
{
	int				r;
	unsigned int	u;

	t->f_plus = 0;
	u = va_arg(ap, unsigned int);
	r = ft_numlen(u, 10);
	deal_width(r, t);
	ft_putnbr_u(u, 0);
	return (r);
}
