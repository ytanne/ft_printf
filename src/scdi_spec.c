/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scdi_spec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 23:37:03 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/01 14:22:38 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		s_spec(va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	ft_putstr(str);
	return (ft_strlen(str));
}

int		c_spec(va_list ap)
{
	char	c;

	c = va_arg(ap, int);
	ft_putchar(c);
	return (1);
}

int		d_spec(va_list ap)
{
	int		i;

	i = va_arg(ap, signed int);
	ft_putnbr(i);
	return (ft_numlen(i, 10));
}

int		i_spec(va_list ap)
{
	int		i;

	i = va_arg(ap, signed int);
	ft_putnbr(i);
	return (ft_numlen(i, 10));
}

int		p_spec(va_list ap)
{
	void	*b;
	
	b = va_arg(ap, void *);
	return (ft_putaddress_ll(b));
}