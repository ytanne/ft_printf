/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ouUxX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:20:59 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/14 16:21:16 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				o_spec(va_list av, t_print *t)
{
    uintmax_t	nbr;
	int			l[3];
	char		sp;
	int			c;

	ft_ls_uox(&nbr, t, av);
	sp = (t->f_z == 1 && t->p_n == -1) ? '0' : ' ';
	l[0] = ft_numlen_base(nbr, 8);
	l[2] = (t->p_n != -1 && t->p_n > l[0]) ? t->p_n : l[0];
	t->w_n += (t->f_h == 1 && nbr != 0 && l[2] == l[0])
	? - l[2] - 1: - l[2];
	l[1] = t->w_n;
	o_av25(t, sp, &nbr, &(l[0]));
    (nbr == 0 && t->p_n == -1 && t->f_h == -1) ? ft_putstr("") :
    ft_putnbr_base(nbr, 8, 0);
    while ((t->f_m == 1) && t->w_n-- > 0)
		ft_putchar(sp);
	return (l[1] + l[0]);
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

int				x_spec(va_list av, t_print *t)
{    
    uintmax_t	nbr;
	int			l[3];
	char		sp;
	int			c;

	ft_ls_uox(&nbr, t, av);
	sp = (t->f_z == 1 && t->p_n == -1) ? '0' : ' ';
	l[0] = ft_numlen_base(nbr, 16);
	l[2] = (t->p_n != -1 && t->p_n > l[0]) ? t->p_n : l[0];
	t->w_n += (t->f_h == 1 && nbr != 0) ? -t->f_p - l[2] - 2:
    -t->f_p - l[2];
	l[1] = t->w_n;
	x_av25(t, sp, &nbr, &(l[0]), 0);
    (nbr == 0 && t->p_n == -1) ? ft_putstr("") :
    ft_putnbr_base(nbr, 16, 0);
    while ((t->f_m == 1) && t->w_n-- > 0)
		ft_putchar(sp);
	return (l[1] + l[0]);
}

int				xl_spec(va_list av, t_print *t)
{    
    uintmax_t	nbr;
	int			l[3];
	char		sp;
	int			c;

	ft_ls_uox(&nbr, t, av);
	sp = (t->f_z == 1 && t->p_n == -1) ? '0' : ' ';
	l[0] = ft_numlen_base(nbr, 16);
	l[2] = (t->p_n != -1 && t->p_n > l[0]) ? t->p_n : l[0];
	t->f_s = (t->f_p == 1 && t->f_s == 1) ? 0 : t->f_s;
	t->w_n += (t->f_h == 1 && nbr != 0) ? -t->f_p - l[2] - t->f_s - 2:
    -t->f_p - l[2] - t->f_s;
	l[1] = t->w_n;
	x_av25(t, sp, &nbr, &(l[0]), 1);
    (nbr == 0 && t->p_n == -1) ? ft_putstr("") :
    ft_putnbr_base(nbr, 16, 1);
    while ((t->f_m == 1) && t->w_n-- > 0)
		ft_putchar(sp);
	return (l[1] + l[0]);
}

int			f_spec(va_list av, t_print *t)
{
	int		r;
	double	nbr;
	int		prc;
	int		l;

	nbr = (double)va_arg(av, double);
	l = ((prc = t->p_n) > 0) ?\
	t->w_n - ft_numlen((int)nbr, 10) - prc - t->f_p - 1 :\
	t->w_n - ft_numlen((int)nbr, 10) - t->f_p;
	while (l-- > 0)
		ft_putchar(' ');
	if (nbr >= 0 && t->f_p == 1)
		ft_putchar('+');
	r = ft_putfloat(nbr, prc);
	return (r);
}
