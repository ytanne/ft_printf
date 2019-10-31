/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 17:31:14 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/31 10:23:26 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int				ft_printf(const char *str, ...)
{
	va_list		ap;

	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			fill_struct(*(++str), ap);
		}
		else
			ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (0);
}
