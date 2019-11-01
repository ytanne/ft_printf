/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:42:08 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/31 16:34:25 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		o_spec(va_list ap)
{
	int	r;

	r = 1;
	ft_putnb_base(va_arg(ap, unsigned int), 8);
	return (r);
}

int		x_spec(va_list ap)
{
	int	r;

	r = 1;
	ft_putnb_base(va_arg(ap, unsigned int), 16);
	return (r);
}

int		u_spec(va_list ap)
{
	int	r;

	r = 1;
	ft_putnb_base(va_arg(ap, unsigned int), 16);
	return (r);
}
