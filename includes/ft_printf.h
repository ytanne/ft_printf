/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:14:35 by yorazaye          #+#    #+#             */
/*   Updated: 2019/10/31 09:55:55 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_printf
{
	char			specifier;
	char			*str;
	struct s_printf	*next;
}				t_printf;

typedef int		t_printp(va_list ap);

/*
**	Number formatting
*/

int				d_spec(va_list ap);
int				i_spec(va_list ap);
int				o_spec(va_list ap);
/*
int				u_spec(va_list ap);
int				x_spec(va_list ap);
int				xl_spec(va_list ap);
int				f_spec(va_list ap);
int				fl_spec(va_list ap);
int				e_spec(va_list ap);
int				el_spec(va_list ap);
int				g_spec(va_list ap);
int				gl_spec(va_list ap);
int				a_spec(va_list ap);
int				al_spec(va_list ap);
*/
/*
**	Text formatting
*/

int				c_spec(va_list ap);
int				s_spec(va_list ap);

/*
**	Other stuff formatting
*/
/*
int				n_spec(va_list ap);
int				p_spec(va_list ap);
int				pc_spec(va_list ap);
*/
/*
**	Function dispatch table
*/

static t_printp	*g_printable[] =
{
	d_spec,
	i_spec,
	/*
	o_spec,
	u_spec,
	x_spec,
	xl_spec,
	f_spec,
	fl_spec,
	e_spec,
	el_spec,
	g_spec,
	gl_spec,
	a_spec,
	al_spec,
	*/
	c_spec,
	s_spec
	/*
	p_spec,
	n_spec,
	pc_spec,*/
};

/*
**	Data structure functions
*/

t_printf		*new_prst(void);
int				fill_struct(char c, va_list ap);
int				ft_printf(const char *str, ...);

#endif
