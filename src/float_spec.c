/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 23:38:09 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/03 14:10:56 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			f_spec(va_list va)
{
	int		r;

	r = ft_putfloat((double)va_arg(va, double), 6);
	return (r);
}
