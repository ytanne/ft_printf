/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uox_spec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:42:08 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/03 15:44:55 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		o_spec(va_list ap)
{
	int	r;

	r = 1;
	ft_putnbr_base(va_arg(ap, unsigned int), 8, 0);
	return (r);
}

int		x_spec(va_list ap)
{
	int	r;

	r = 1;
	ft_putnbr_base(va_arg(ap, unsigned int), 16, 0);
	return (r);
}

int		xl_spec(va_list ap)
{
	int	r;

	r = 1;
	ft_putnbr_base(va_arg(ap, unsigned int), 16, 1);
	return (r);
}

int		u_spec(va_list ap)
{
	int	r;

	r = 1;
	ft_putnbr_u(va_arg(ap, unsigned int), 0);
	return (r);
}
