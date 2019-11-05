/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:14:35 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/04 20:37:20 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_printf
{
	int			f_minus;
	int			f_plus;
	int			f_space;
	int			f_hash;
	int			f_zero;
	int			w;
	int			p;
	int			l;
}				t_printf;

void			fsearch_prst(t_printf **t, char c);
typedef int		t_printp(va_list ap, t_printf *t);
typedef int		t_fwpl(char *c, t_printf **t);

/*
**	Number formatting
*/

int				d_spec(va_list ap, t_printf *t);
int				i_spec(va_list ap, t_printf *t);
int				o_spec(va_list ap, t_printf *t);
int				u_spec(va_list ap, t_printf *t);
int				x_spec(va_list ap, t_printf *t);
int				xl_spec(va_list ap, t_printf *t);
int				f_spec(va_list ap, t_printf *t);
/*
int				fl_spec(va_list ap, t_printf *t);
int				e_spec(va_list ap, t_printf *t);
int				el_spec(va_list ap, t_printf *t);
int				g_spec(va_list ap, t_printf *t);
int				gl_spec(va_list ap, t_printf *t);
int				a_spec(va_list ap, t_printf *t);
int				al_spec(va_list ap, t_printf *t);
*/
/*
**	Text formatting
*/

int				c_spec(va_list ap, t_printf *t);
int				s_spec(va_list ap, t_printf *t);

/*
**	Other stuff formatting
*/

//int				n_spec(va_list ap, t_printf *t);

/*
**	Address and percentage printing. Located in ft_putaddress.c
*/

int				p_spec(va_list ap, t_printf *t);
int				pc_spec(va_list ap, t_printf *t);

/*
**	Functions for flags, width, precision and length check
*/

int				fl_check(char *c, t_printf **t);
int				w_check(char *c, t_printf **t);
int				p_check(char *c, t_printf **t);
int				l_check(char *c, t_printf **t);

/*
**	Function dispatch table for specifiers
*/

static t_printp	*g_printable[] =
{
	d_spec,
	i_spec,
	o_spec,
	u_spec,
	x_spec,
	xl_spec,
	f_spec,
	/*
	fl_spec,
	e_spec,
	el_spec,
	g_spec,
	gl_spec,
	a_spec,
	al_spec,
	*/
	c_spec,
	s_spec,
	p_spec,
	//n_spec,
	pc_spec
};

/*
**	Function dispatch table for flags, width, precision and length
*/

static t_fwpl *g_fwpl[] =
{
	fl_check,
	w_check/*,
	p_check,
	l_check
	*/
};

/*
**	Data structure functions
*/

t_printf		*new_prst(void);
void			init_prst(t_printf **p);
int				fill_struct(char c, va_list ap, t_printf *t);
int				ft_printf(const char *str, ...);
int				ft_numlen(unsigned int nb, int base);
int				ft_putnbr_base(unsigned int value, int base, int c);
int				ft_putaddress_ll(void *address);
int				ft_putfloat(float nbr, int afterpoint);
int				ft_putdouble(double nbr, int afterpoint);
int				ft_putnbr_u(unsigned int value, int xl);
void			deal_width(int l, t_printf *t);

#endif
