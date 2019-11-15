/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:06:21 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/14 16:02:32 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				D_spec(va_list av, t_print *t)
{
    return (1);
}

int				f_spec(va_list av, t_print *t)
{
    return (1);
}

int				pr_spec(va_list av, t_print *t)
{
    char	pc;
	char	sp;

	pc = '%';
	sp = (t->f_z == 1 && t->f_m == -1) ? '0' : ' ';
	t->w_n -= 1;
	while ((t->f_m == -1) && t->w_n-- > 0)
		ft_putchar(sp);
	ft_putchar(pc);
	while ((t->f_m == 1) && t->w_n-- > 0)
		ft_putchar(sp);
	return (1);
}

int             ft_numlen(uintmax_t nbr, int base)
{
    int			l;

	l = 0;
	while (nbr && l++)
		nbr /= base;
    return (l);
}
/*
void            ft_ls_d(intmax_t *nbr, t_print *t, va_list av)
{
    if (t->s_l == 0)
		(*nbr) = (signed char)va_arg(av, int);
	else if (t->s_l == 1)
		(*nbr) = (short int)va_arg(av, int);
	else if (t->s_l == 2)
		(*nbr) = va_arg(av, long int);
	else if (t->s_l == 3)
		(*nbr) = va_arg(av, long long int);
	else if (t->s_l == 4)
		(*nbr) = (size_t)va_arg(av, unsigned long long int);
	else
		(*nbr) = (int)va_arg(av, int);
}
*/

void			ft_putnbr_im(intmax_t nbr)
{
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr_im(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

void			ft_putnbr_uim(uintmax_t nbr)
{
	if (nbr > 9)
		ft_putnbr_uim(nbr / 10);
	ft_putchar((nbr % 10) + '0');
}

int				ft_numlen_im(intmax_t nbr)
{
	int			l;

	l = (nbr > 0) ? 0 : 1;
	while (nbr)
	{
		nbr /= 10;
		l++;
	}
	return (l);
}

int				ft_numlen_uim(uintmax_t nbr)
{
	int			l;

	l = (nbr > 0) ? 0 : 1;
	while (nbr)
	{
		nbr /= 10;
		l++;
	}
	return (l);
}
