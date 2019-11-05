/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwpl_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 15:18:11 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/04 16:52:59 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		fl_check(char *c, t_printf **t)
{
	char	*flags;
	int		i;
	int		r;

	i = 0;
	r = 0;
	c++;
	flags = "-+ #0";
	while (ft_strchr(flags, *c) > 0)
	{
		fsearch_prst(t, *(c++));
		r++;
	}
	return (r);
}

int		w_check(char *c, t_printf **t)
{
	int		width;
	int		r;

	width = 0;
	r = 0;
	c++;
	while (ft_isdigit(*c))
	{
		width = width * 10 + (*(c++) - '0');
		r++;
	}
	if (width != 0)
		(*t)->w = width;
	return (r);
}
/*
int		p_check(char c, int fl)
{
	if (ft_isdigit((int)c) || (c == '*'))
		return (1);
	return (0);
}

int		l_check(char c, int fl)
{
	char	*flags;
	int		i;

	i = 0;
	flags = "hljztL";
	while (i < 5)
		if (c == flags[i])
			return (1);
	return (0);
}
*/
