/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:56:45 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/14 17:40:19 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		print_init(const char *str, t_print *t, va_list av)
{
	char		*specifiers;
	int			i;
	int			l;

	i = -1;
	specifiers = "cspdiouxXf%";
	while (++i < 11)
		if (*str == specifiers[i])
			break ;
	if (i == 11)
		exit(0);
	l = g_f_table[i](av, t);
	return (l);
}

static int		find_spec(const char *str)
{
	int			i;
	char		*specifiers;

	i = -1;
	specifiers = "cspdiouxXf%";
	while (str[++i] && (ft_strchr(specifiers, str[i]) == 0))
		;
	if (str[i] == '\0')
		return (-1);
	return (i);
}

static void		get_fwpl(char *str, t_print **t)
{
	int		i;

	i = -1;
	while (++i < 4)
		g_fwpl[i]((char *)str, t);
}

static int		end_it_pls(va_list av, t_print **t, int numb)
{
	delete_str(t);
	va_end(av);
	return (numb);
}

int				ft_printf(const char *str, ...)
{
	va_list		av;
	t_print		*t;
	int			count[2];
	char		*flags;

	count[0] = 0;
	va_start(av, str);
	t = new_str();
	while (*str != '\0')
	{
		if (*str == '%' && (str++))
		{
			reset_str(&t);
			if ((count[1] = find_spec(str)) >= 0)
			{
				flags = ft_strsub(str, 0, count[1]);
				get_fwpl(flags, &t);
				str += count[1];
				count[0] += print_init((str++), t, av);
				ft_strdel(&flags);
			}
		}
		else
			ft_putchar(*(str++));
		count[0]++;
	}
	return (end_it_pls(av, &t, count[0]));
}
