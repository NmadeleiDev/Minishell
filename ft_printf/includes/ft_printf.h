/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 15:20:22 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include "put_digits.h"
# include <fcntl.h>
# include <stdarg.h>

typedef struct		s_ftprintf
{
	char			fill;
	char			*flag;
	char			sign;
	int				wid;
	int				pres;
	int				out;
	char			mod;
	char			conv;
}					t_ftprintf;

typedef struct		s_floats
{
	char			*whole;
	char			*mass;
	char			*rest;
}					t_floats;

int					ft_printf(const char *restrict format, ...);
void				emergency_exit(void);
int					read_format(va_list args, const char *conv, \
t_ftprintf *specif);
int					add_to_flag(t_ftprintf *specif, char c);
int					add_to_wid(t_ftprintf *specif, int wid, const char *str);
int					add_to_pres(t_ftprintf *specif, int pres, const char *str);
int					add_to_mod(t_ftprintf *specif, char m, char m1);
int					add_to_conv(t_ftprintf *specif, char c);
void				print_order(char *print_it, int wid, int order, char fill);
void				normalize_ptr(t_ftprintf *specif, int ptr_len);
void				normalize_signed(t_ftprintf *specif);
void				normalize_unsigned(t_ftprintf *specif);
void				normalize_x(t_ftprintf *specif, char *num);
int					got_char(char *str, char c);
void				put_digit(va_list args, t_ftprintf *specif);
char				*ft_coolmalloc(char *s, char set_val, size_t n, int	start);
void				sort_calcs(va_list args, t_ftprintf *specif);
void				sort_signed(va_list args, t_ftprintf *specif);
void				sort_unsigned(va_list args, t_ftprintf *specif);
void				add_sign(char *num, t_ftprintf *specif);
void				line_modifier(char *num, t_ftprintf *specif);

void				put_cs(va_list args, t_ftprintf *specif);
void				normalize_cs(t_ftprintf *specif);
void				print_ptr(unsigned long long ptr, t_ftprintf *specif);
void				put_groot(t_ftprintf *specif);

void				put_float(va_list args, t_ftprintf *specif);
void				put_double(double fl, t_ftprintf *specif);
void				put_long_double(long double fl, t_ftprintf *specif);
void				normalize_float(t_ftprintf *specif);

char				*get_unllong_to_str(unsigned long long n, char *str);
void				put_long_double(long double fl, t_ftprintf *specif);
void				print_this_fucking_float\
(t_floats *floa, int exp, t_ftprintf *specif);
void				print_double_struct(t_floats *floa, t_ftprintf *specif);
char				*convert_rest(char *num);
void				convert_good_mass(char *mass, int exp, int size);
int					ft_itoa_2base\
(unsigned long long decim, char *based, int size);
unsigned long long	get_decim_out(char *based, int len);
void				printf_output_extra(char *evv, int dev);
void				double_str(char *num, int num_len);
int					get_power(unsigned long num, int power);
int					plus_rests(char *rest, char *dev, int len);
void				dev_dev_part(char *num, int num_len);
void				print_final_float(char *finfloat, t_ftprintf *specif);
int					append_one(char *num, int num_len, int trig);
void				formate_number(t_floats *floa, t_ftprintf *specif);

#endif
