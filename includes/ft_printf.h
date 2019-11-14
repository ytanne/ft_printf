/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yorazaye <yorazaye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 18:14:35 by yorazaye          #+#    #+#             */
/*   Updated: 2019/11/13 20:42:51 by yorazaye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <stdlib.h>

/*
**	Flags width precision length checks
*/

typedef struct		s_print
{
	int				f_m;
	int				f_p;
	int				f_s;
	int				f_h;
	int				f_z;
	int				w_n;
	int				p_n;
	int				s_l;
}					t_print;

typedef int			t_fwpl(char *str, t_print **t);

int					flag_check(char *str, t_print **t);
int					width_check(char *str, t_print **t);
int					precision_check(char *str, t_print **t);
int					length_check(char *str, t_print **t);

static t_fwpl		*g_fwpl[] =
{
	flag_check,
	width_check,
	precision_check,
	length_check
};

/*
**	Specifiers check
*/

typedef int			t_specifier(va_list av, t_print *t);

int					c_spec(va_list av, t_print *t);
int					s_spec(va_list av, t_print *t);
int					di_spec(va_list av, t_print *t);
int					D_spec(va_list av, t_print *t);
int					o_spec(va_list av, t_print *t);
int					u_spec(va_list av, t_print *t);
int					U_spec(va_list av, t_print *t);
int					x_spec(va_list av, t_print *t);
int					xl_spec(va_list av, t_print *t);
int					f_spec(va_list av, t_print *t);
int					pr_spec(va_list av, t_print *t);

/*
**	Second 'd_spec' is for 'i' specifier. Because 'i' specifier acts in the
**	same way as 'd' specifier.
*/

static t_specifier	*g_f_table[] =
{
	c_spec,
	s_spec,
	di_spec,
	D_spec,
	di_spec,
	o_spec,
	u_spec,
	U_spec,
	x_spec,
	xl_spec,
	f_spec,
	pr_spec
};

/*
**	General functions
*/

int					ft_printf(const char *str, ...);

/*
**	Structure functions
*/

t_print				*new_str(void);
void				reset_str(t_print **t);
void				delete_str(t_print **t);

/*
**	Additional functions
*/

int					ft_numlen(uintmax_t nbr, int base);
int					ft_numlen_im(intmax_t nbr);
int					ft_numlen_uim(uintmax_t nbr);
int					ft_numlen_base(uintmax_t nb, int base);
int					ft_putnbr_base(uintmax_t value, int base, int xl);
void				ft_ls_di(intmax_t *nbr, t_print *t, va_list av);
void				ft_ls_uox(uintmax_t *nbr, t_print *t, va_list av);
void				ft_putnbr_im(intmax_t nbr);
void				ft_putnbr_uim(uintmax_t nbr);
void				di_av25(t_print *t, char sp, intmax_t *nbr, int *l);
void				u_av25(t_print *t, char sp, uintmax_t *nbr, int *l);
void				x_av25(t_print *t, char sp, uintmax_t *nbr, int *l, int u);



#endif
