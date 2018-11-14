/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:41:18 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 01:05:47 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFF_SIZE 1000

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <locale.h>

typedef struct	s_string
{
	void	*arg;
	char	to_print[BUFF_SIZE];
}				t_string;

typedef struct	s_struct
{
	int		f0;
	int		fm;
	int		fl;
	int		fd;
	int		wi;
	int		pr;
	int		le;
	int		ty;
}				t_struct;

typedef struct	s_unistuff
{
	char	res[5];
	wint_t	m[4];
	wint_t	c;
}				t_unistuff;

typedef struct	s_concstuff
{
	int		conv_size;
	char	filler;
	char	prefix[3];
	int		width;
	int		prec;
}				t_concstuff;

typedef struct	s_size
{
	int		pos;
	int		size;
}				t_size;

int				ft_is_ty(char c);
int				ft_is_signed(char c);
int				ft_is_unsigned(char c);
int				ft_is_nb(char c);
int				ft_strlen_printf(char *s);
int				ft_nbrlen(int n);
int				ft_bitlen(wint_t c);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_purge(t_size *tsize, char *str);
void			ft_ccat_gen(char *str, char c, t_size *tsize);
void			ft_strnaddc_gen(char *str, char c, int len, t_size *tsize);
void			ft_strcat_gen(char *str, char *s2, t_size *tsize);
void			ft_strncat_gen(char *str, char *s2, int len, t_size *tsize);
void			ft_ccat(char *str, char c);
char			*ft_strcat_printf(char *s1, char *s2);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
char			*ft_str_up(char *str);
int				ft_atoi(const char *nptr);
char			*ft_itoa_base(intmax_t value, int base, char *conv_res);
char			*ft_uitoa_base(uintmax_t value, int base, char *conv_res);
int				ft_unicode_process(wint_t c, char *to_print, t_size *tsize);
int				ft_nb_bytes(wchar_t *str);
int				ft_unicode_str(wchar_t *arg, char *to_print, t_size *tsize);
char			*ft_conversion(t_struct *params, void *arg,
				const char *conv_res);
int				ft_parse_ty(t_struct *params, const char *format);
int				ft_parse_fl(t_struct *params, const char *format);
int				ft_parse_le(t_struct *params, const char *format);
int				ft_parse_wi(t_struct *params, const char *format, va_list *ap);
int				ft_parse_pr(t_struct *params, const char *format, va_list *ap);
void			ft_cnull(t_struct *params, t_size *tsize, char *to_print);
char			*ft_prefix(t_struct *params, char *prefix, void *arg);
int				ft_conv_size_alpha(t_struct *params, void *arg);
void			ft_digit_prepa(t_struct *params, void *arg, char *conv_res,
				t_concstuff *cstuff);
int				ft_process(t_struct *params, t_string *result, t_size *tsize);
int				ft_printf(const char *format, ...);

#endif
