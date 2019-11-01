/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:27:05 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/01 10:02:44 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		fsearch_prst(t_printf **t, char c)
{
	if (c == '-' && (*t)->f_minus == 0)
		(*t)->f_minus = 1;
	else if (c == '+' && (*t)->f_plus == 0)
		(*t)->f_minus = 1;
	else if (c == ' ' && (*t)->f_space == 0)
		(*t)->f_minus = 1;
	else if (c == '#' && (*t)->f_hash == 0)
		(*t)->f_minus = 1;
	else if (c == '0' && (*t)->f_zero == 0)
		(*t)->f_minus = 1;
}

void		init_prst(t_printf **p)
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
	//s = "diouxXfFeEgGaAcspnP";
	s = "dioxcs";
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

int				fill_struct(char c, va_list ap)
{
	int		i;

	i = assign_specifier(c);
	//(*p)->str = va_arg(ap, char *);
	g_printable[i](ap);
	return (1);
}
