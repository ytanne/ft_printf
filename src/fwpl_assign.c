/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwpl_assign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 10:03:48 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/03 16:44:43 by yorazaye         ###   ########.fr       */
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
