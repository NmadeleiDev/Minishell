/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_digits.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmadelei <nmadelei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 12:38:04 by nmadelei          #+#    #+#             */
/*   Updated: 2019/11/07 15:43:50 by nmadelei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUT_DIGITS_H
# define PUT_DIGITS_H

# include "../libft/libft.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdarg.h>

int						get_base(char base);
int						increase_num(char *num, int num_len);
int						increase_by_one(char *num, int num_len, int trig);
void					double_str(char *num, int num_len);
unsigned int			jcount_mem_need(uintmax_t n, int del);
char					*get_int(int n);
char					*get_llong(long long n);
char					*get_long(long n);
char					*get_schar(signed char n);
char					*get_short(short n);
char					*get_unchar(unsigned char n);
char					*get_unint(unsigned int n);
char					*get_unllong(unsigned long long n);
char					*get_unlong(unsigned long n);
char					*get_unshort(unsigned short n);
char					*getibase(unsigned int n, char base);
char					*get_lbase_num(unsigned long n, char base);
char					*get_llbase_num(unsigned long long n, char base);
char					*get_hbase_num(unsigned short n, char base);
char					*get_hhbase_num(unsigned char n, char base);
char					*get_jbase_num(uintmax_t n, char base);
char					*get_uintmax_num(uintmax_t n);
char					*get_intmax_num(intmax_t n);
char					*get_size_t_num(size_t n);

#endif
