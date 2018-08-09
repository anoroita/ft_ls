/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoroita <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 16:44:33 by anoroita          #+#    #+#             */
/*   Updated: 2018/07/07 16:44:39 by anoroita         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

typedef struct	s_flag
{
	char	c;
	void	(*f)();
}				t_flag;

typedef struct	s_id
{
	char	c;
	void	(*f)();
}				t_id;

typedef struct	s_pf
{
	int		i;
	int		print;
	int		hash;
	int		zero;
	int		minus;
	int		plus;
	int		space;
	int		point;
	int		h;
	int		hh;
	int		l;
	int		ll;
	int		j;
	int		z;
	int		width;
	int		precision;
	int		done;
	int		neg;
	int		index;
	char	buf[4096];
	int		ready;
}				t_pf;

int				ft_printf(const char *format, ...);
void			ft_parser(const char *format, t_pf *ft, va_list *ag);
void			ft_set_flag(t_flag *flag);
void			ft_set_id_next(t_id *id);
void			ft_set_id(t_id *id);
void			ft_clear(t_pf *ft);
void			ft_analyse_str(const char *format, t_flag *flag, t_pf *ft,
				va_list *ag);
int				ft_nbrlen(intmax_t nbr);
void			ft_putstr_pf(t_pf *ft, char *str, int len);
void			ft_set_h(t_pf *ft, const char *format);
void			ft_set_l(t_pf *ft, const char *format);
void			ft_set_j(t_pf *ft, const char *format);
void			ft_set_precision(t_pf *ft, const char *format);
void			ft_set_z(t_pf *ft, const char *format);
void			ft_set_hash(t_pf *ft, const char *format);
void			ft_set_zero(t_pf *ft, const char *format);
void			ft_set_minus(t_pf *ft, const char *format);
void			ft_set_plus(t_pf *ft, const char *format);
void			ft_set_space(t_pf *ft, const char *format);
void			ft_manage_s(t_pf *ft, va_list *ag);
void			ft_manage_us(t_pf *ft, va_list *ag);
void			ft_manage_width_left(t_pf *ft, int len);
void			ft_manage_width_right(t_pf *ft, int len);
int				ft_wcharlen(int c);
int				ft_wstrlen(wchar_t *str);
void			ft_putwstr_pf(t_pf *ft, wchar_t *str, int len);
void			ft_manage_p(t_pf *ft, va_list *ag);
int				ft_baselen(t_pf *ft, uintmax_t nbr, int base);
void			ft_putbase(t_pf *ft, uintmax_t nbr, char *base);
int				ft_baselen_precision(t_pf *ft, uintmax_t nbr, int base);
intmax_t		ft_get_int(t_pf *ft, va_list *ag);
void			ft_manage_d(t_pf *ft, va_list *ag);
void			ft_putnbr_pf(t_pf *ft, intmax_t nbr);
void			ft_manage_precision(t_pf *ft, int len);
void			ft_new_precision(t_pf *ft, int len, intmax_t nbr);
void			ft_manage_ud(t_pf *ft, va_list *ag);
uintmax_t		ft_get_uint(t_pf *ft, va_list *ag);
void			ft_manage_o(t_pf *ft, va_list *ag);
void			ft_manage_uu(t_pf *ft, va_list *ag);
void			ft_manage_u(t_pf *ft, va_list *ag);
void			ft_manage_uo(t_pf *ft, va_list *ag);
void			ft_manage_x(t_pf *ft, va_list *ag);
void			ft_manage_ux(t_pf *ft, va_list *ag);
int				ft_get_xlen(t_pf *ft, uintmax_t nbr);
void			ft_manage_c(t_pf *ft, va_list *ag);
void			ft_manage_uc(t_pf *ft, va_list *ag);
void			ft_manage_zero(t_pf *ft, int len);
void			ft_manage_undefined(t_pf *ft, char c);
void			ft_remove_zero(t_pf *ft);
void			ft_manage_b(t_pf *ft, va_list *ag);
void			ft_manage_star(t_pf *ft, const char *format, va_list *ag,
				int *i);
void			ft_manage_ub(t_pf *ft, va_list *ag);
void			ft_manage_n(t_pf *ft, va_list *ag);
int				ft_check_unicode(wchar_t *str, int len);
void			ft_error_printf(t_pf *ft);
void			ft_check_null_str(t_pf *ft, char **str, int *len);
void			ft_check_null_wstr(t_pf *ft, wchar_t **str, int *len);
void			ft_putbuf(t_pf *ft, char c);
void			ft_printbuf(t_pf *ft);
void			ft_putwchar_pf(t_pf *ft, int c);
int				ft_get_len(int max, wchar_t *str);
void			ft_paint(const char *format, t_pf *ft);
void			ft_paint_next(const char *format, t_pf *ft);
void			ft_paint_last(const char *format, t_pf *ft);

#endif
