/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchanot <bchanot@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 00:34:04 by bchanot           #+#    #+#             */
/*   Updated: 2016/08/20 05:16:31 by bchanot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include "libft.h"

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define PURPLE "\033[0;35m"
# define CYAN "\033[0;36m"
# define GREY "\033[0;37m"
# define EOC "\033[0;m"

typedef struct		s_inf
{
	int				done;

	int				flag;
	int				di;
	int				zero;
	int				min;
	int				space;
	int				plus;

	int				h;
	int				hh;
	int				l;
	int				ll;
	int				j;
	int				z;

	int				width;
	int				prec;
	int				type;
}					t_inf;

int					ft_printf(const char *format, ...);
int					pf_print_part(const char *format, char *str);
int					pf_take_color(char **str, const char **format, int *len);
void				pf_do_if(t_inf *inf, long long int nb, int min);
t_inf				pf_take_inf(char **s, va_list ap);
void				take_prec(char **s, t_inf *inf, va_list ap, int cpt);
int					pf_more_flag(char **s, t_inf *inf);
int					pf_wrong_conv(char **str, const char **format, t_inf inf,
								int *len);
int					pf_width_s(char *str, t_inf inf, int len);
int					pf_octlen(unsigned int n, t_inf inf);
int					pf_hexlen(unsigned int n);
int					pf_octulen(long long unsigned int n, t_inf inf);
int					pf_hexulen(long long unsigned int n);
int					pf_putoctal(unsigned int n);
int					pf_puthexm(unsigned int n);
int					pf_puthex(unsigned int n);
int					pf_putuoctal(long long unsigned int n);
int					pf_putuhexm(long long unsigned int n);
int					pf_putuhex(long long unsigned int n);
int					pf_putunbrlong(long long unsigned int n);
int					pf_putunbr(unsigned int n);
int					pf_putstr(const char *str);
int					pf_putnstr(const char *str, int n);
int					pf_percent(va_list ap, t_inf inf);
int					pf_c(va_list ap, t_inf inf);
int					pf_s(va_list ap, t_inf inf);
int					pf_di(va_list ap, t_inf inf);
int					pf_p(va_list ap, t_inf inf);
int					pf_x(va_list ap, t_inf inf);
int					pf_xlong2(int len, t_inf *inf, unsigned long long nb);
int					pf_u(va_list ap, t_inf inf);
int					pf_o(va_list ap, t_inf inf);
int					pf_b(va_list ap, t_inf inf);
int					pf_x_up(va_list ap, t_inf inf);
int					pf_x_uplong2(int len, t_inf *inf, unsigned long long nb);
int					pf_s_up(va_list ap, t_inf inf);
int					pf_d_up(va_list ap, t_inf inf);
int					pf_o_up(va_list ap, t_inf inf);
int					pf_u_up(va_list ap, t_inf inf);
int					pf_c_up(va_list ap, t_inf inf);

#endif
