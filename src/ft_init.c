/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:27:05 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/03 16:54:10 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			init_prst(t_printf **p)
{
	(*p)->f_minus = 0;
	(*p)->f_plus = 0;
	(*p)->f_space = 0;
	(*p)->f_hash = 0;
	(*p)->f_zero = 0;
	(*p)->w = 0;
	(*p)->p = 0;
	(*p)->l = 0;
}

t_printf		*new_prst(void)
{
	t_printf	*p;

	p = (t_printf *)malloc(sizeof(t_printf));
	init_prst(&p);
	return (p);
}

int				assign_specifier(char c)
{
	char	*s;
	int		i;

	i = -1;
	/*
	**	s = "diouxXfFeEgGaAcspnP";
	*/
	s = "diouxXfcsp%";
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

int				fill_struct(char c, va_list ap)
{
	int		i;

	i = assign_specifier(c);
	g_printable[i](ap);
	return (1);
}
