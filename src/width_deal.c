/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_deal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:35:05 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/05 22:03:19 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		deal_width(int l, t_printf *t)
{
	int		sp;
	int		prc;
	char	fill;

	prc = t->p - l;
	sp = (t->p) ? t->w - l - t->f_plus - prc :\
	t->w - l - t->f_plus;
	fill = (t->f_zero && (t->p < 0)) ? '0' : ' ';
	while (sp-- > 0)
		ft_putchar(fill);
	if (t->f_plus == 1)
		ft_putchar('+');
	while (prc-- > 0)
		ft_putchar('0');
}