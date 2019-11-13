/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   csdi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 00:53:28 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/12 14:01:50 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			c_spec(va_list av, t_print *t)
{
	char	c;
	char	sp;

	c = va_arg(av, int);
	sp = (t->f_z == 1 && t->f_m == -1) ? '0' : ' ';
	t->w_n -= 1;
	while ((t->f_m == -1) && t->w_n-- > 0)
		ft_putchar(sp);
	ft_putchar(c);
	while ((t->f_m == 1) && t->w_n-- > 0)
		ft_putchar(sp);
	return (1);			//Have to evaluate the output with all flags
}

int			s_spec(va_list av, t_print *t)
{
	char	*c;
	int		l[2];
	char	sp;

	if (!(c = va_arg(av, char *)))
		c = "(null)";
	l[0] = ft_strlen(c);
	l[1] = (t->p_n != -1 && l[0] > t->p_n) ? t->p_n : l[0];
	sp = (t->f_z == 1 && t->f_m == -1) ? '0' : ' ';
	t->w_n -= l[1];
	while (t->f_m == -1 && t->w_n-- > 0)
		ft_putchar(sp);
	if (t->p_n == -1)
		ft_putstr(c);
	else
		while (*c && t->p_n--)
			ft_putchar(*(c++));
	while ((t->f_m == 1) && t->w_n-- > 0)
		ft_putchar(sp);
	return (l[1]);
}

int			di_spec(va_list av, t_print *t)
{
	intmax_t	nbr;
	int			l[4];
	char		sp;
	int			c;

	ft_ls_di(&nbr, t, av);
	sp = (t->f_z == 1 && t->p_n == -1) ? '0' : ' ';
	l[0] = ft_numlen_im(nbr);
	l[2] = (t->p_n != -1 && t->p_n > l[0]) ? t->p_n : l[0];
	l[3] = (nbr < 0 && t->p_n != -1 && t->p_n > l[0]) ? 1 : 0;
	t->f_s = (t->f_p == 1 && t->f_s == 1) ? 0 : t->f_s;
	t->w_n += (nbr >= 0) ? -t->f_p - l[2] - l[3] - t->f_s :
	-l[2] - l[3];
	l[1] = t->w_n;
	di_av25(t, sp, &nbr, &(l[0]));
	ft_putnbr_im(nbr);
	while ((t->f_m == 1) && t->w_n-- > 0)
		ft_putchar(sp);
	return (l[1] + l[0]);
}
