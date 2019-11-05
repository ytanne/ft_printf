/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_deal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 20:35:05 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/04 20:37:04 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		deal_width(int l, t_printf *t)
{
	int		sp;
	char	fill;

	sp = t->w - l - t->f_plus;
	fill = (t->f_zero) ? '0' : ' ';
	while (sp-- > 0)
		ft_putchar(fill);
}