/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/29 21:27:05 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/31 09:56:23 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		init_prst(t_printf **p)
{
	(*p)->specifier = (char)NULL;
	(*p)->str = (char *)NULL;
	(*p)->next = NULL;
}

t_printf		*new_prst()
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
	s = "dics";
	while (s[++i])
		if (s[i] == c)
			return (i);
	return (-1);
}

int				fill_struct(char c, va_list ap)
{
	int		i;
	char	*str;

	str = NULL;
	i = assign_specifier(c);
	//(*p)->str = va_arg(ap, char *);
	g_printable[i](ap);
	return (1);
}
