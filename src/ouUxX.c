/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ouUxX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:20:59 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/13 18:31:46 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				o_spec(va_list av, t_print *t)
{
    return (1);
}

int				u_spec(va_list av, t_print *t)
{
    uintmax_t	nbr;
	int			l[3];
	char		sp;
	int			c;

	ft_ls_uox(&nbr, t, av);
	sp = (t->f_z == 1 && t->p_n == -1) ? '0' : ' ';
	l[0] = ft_numlen_uim(nbr);
	l[2] = (t->p_n != -1 && t->p_n > l[0]) ? t->p_n : l[0];
	t->f_s = (t->f_p == 1 && t->f_s == 1) ? 0 : t->f_s;
	t->w_n += -t->f_p - l[2] - t->f_s;
	l[1] = t->w_n;
	u_av25(t, sp, &nbr, &(l[0]));
	(nbr == 0 && t->p_n == -1) ? ft_putstr("") : ft_putnbr_uim(nbr);
	while ((t->f_m == 1) && t->w_n-- > 0)
		ft_putchar(sp);
	return (l[1] + l[0]);
}

int				U_spec(va_list av, t_print *t)
{
    return (1);
}

int				x_spec(va_list av, t_print *t)
{
    return (1);
}

int				X_spec(va_list av, t_print *t)
{
    return (1);
}