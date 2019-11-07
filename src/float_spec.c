/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:38:09 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/05 20:00:39 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			f_spec(va_list va, t_printf *t)
{
	int		r;
	double	nbr;
	int		prc;

	nbr = (double)va_arg(va, double);
	prc = t->p;
	if (nbr >= 0 && t->f_plus == 1)
		ft_putchar('+');
	r = ft_putfloat(nbr, prc);
	return (r);
}
