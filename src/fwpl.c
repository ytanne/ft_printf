/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwpl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 01:03:20 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/14 22:32:42 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int     flag_check(char *str, t_print **t)
{
    char    *flags;
    char    *tmp;

    flags = "-+ #0";
    tmp = str;
    while (*str && ft_strchr(flags, *str) == 0)
        str++;
	if (*str == '\0')
		return (0);
    else if (*str == '-')
		(*t)->f_m = 1;
    else if (*str == '+')
		(*t)->f_p = 1;
    else if (*str == ' ')
		(*t)->f_s = 1;
    else if (*str == '#')
        (*t)->f_h = 1;
    else if (*str == '0')
        if (*(str - 1) && !ft_isdigit(*(str - 1)) && *(str - 1) != '.')
            (*t)->f_z = 1;
    return (flag_check(++str, t));
}

int     width_check(char *str, t_print **t)
{
    int     n;
    char    *tmp;
    char    *dexz;

    n = 0;
    dexz = "123456789";
    tmp = str;
	while (*str && *str != '.' && ft_strchr(dexz, *str) == 0)
		str++;
    while (ft_isdigit(*str))
        n = n * 10 + *(str++) - '0';
    (*t)->w_n = n;
    return (str - tmp);
}

int     precision_check(char *str, t_print **t)
{
    int     n;
    char    *tmp;

    n = 0;
    tmp = str;
	while (*str != '\0' && *str != '.')
		str++;
    if (*str == '\0')
        return (0);
    while (ft_isdigit(*(++str)))
        n = n * 10 + (*str - '0');
    (*t)->p_n = n;
    return (ft_strlen(ft_itoa(n)) + 1);
}

int     length_check(char *str, t_print **t)
{
    char    *tmp;

    tmp = str;
	while (*str && ft_strchr("hlzL", *str) == 0)
		str++;
	if (*str == '\0')
		return (0);
	else if (*str == 'h')
	{
		(*t)->s_l =\
		(*(++str) != '\0' && *str == 'h') ? 0 : 1;
	}
	else if (*str == 'l')
	{
		(*t)->s_l =\
		(*(++str) != '\0' && *str == 'l') ? 3 : 2;
	}
	else if (*str == 'z')
		(*t)->s_l = 4;
	else if (*str == 'L')
		(*t)->s_l = 5;
	return (str - tmp);
}

/*
**  hh -> 0
**  h -> 1
**  l -> 2
**  ll -> 3
**  z -> 4
**  L -> 5
**  none -> -1
*/
