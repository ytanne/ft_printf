/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:31:14 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/02 23:36:51 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		ap;
	int			i;
	int			sh;
	t_printf	*t;

	t = new_prst();
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			init_prst(&t);
			i = 0;
			while (i < 1)
				if ((sh = g_fwpl[i++]((char *)(str), &t)))
					str += sh;
			fill_struct(*(++str), ap);
		}
		else
			ft_putchar(*str);
		str++;
	}
	ft_memdel((void **)&t);
	va_end(ap);
	return (0);
}
