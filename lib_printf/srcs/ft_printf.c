/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 13:45:31 by sgalasso          #+#    #+#             */
/*   Updated: 2018/09/18 00:10:54 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parse_params(t_struct *params, const char **format, va_list *ap)
{
	*format += ft_parse_fl(params, *format);
	*format += ft_parse_wi(params, *format, ap);
	*format += ft_parse_pr(params, *format, ap);
	*format += ft_parse_le(params, *format);
	*format += ft_parse_ty(params, *format);
}

int		ft_format_sample(const char **format, va_list *ap,
		t_string *result, t_size *tsize)
{
	t_struct	params;

	(*format)++;
	ft_parse_params(&params, format, ap);
	if (ft_is_ty(params.ty) || params.ty == '%')
	{
		if (params.ty == '%')
			result->arg = (void *)'%';
		else
			result->arg = va_arg(*ap, void *);
		if ((params.ty == 's' || params.ty == 'S') && result->arg == NULL)
		{
			params.ty = 's';
			result->arg = "(null)";
		}
		if ((params.ty == 'c' || params.ty == 'C') && result->arg == NULL)
			ft_cnull(&params, tsize, result->to_print);
		else if (!(ft_process(&params, result, tsize)))
			return (0);
	}
	else
		return (0);
	return (1);
}

int		ft_format(const char *format, va_list *ap)
{
	t_string	result;
	t_size		tsize;

	tsize.size = 0;
	tsize.pos = 0;
	ft_bzero(result.to_print, BUFF_SIZE);
	while (*format)
	{
		if (*format != '%')
		{
			ft_ccat_gen(result.to_print, *format, &tsize);
			format++;
		}
		if (*format == '%')
		{
			if (!format[1] || !(ft_format_sample(&format, ap, &result, &tsize)))
				return (-1);
		}
	}
	if (tsize.size >= BUFF_SIZE)
		write(1, result.to_print, tsize.size % BUFF_SIZE);
	else
		write(1, result.to_print, tsize.size);
	return (tsize.size);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;

	va_start(ap, format);
	if ((len = ft_format(format, &ap)) == -1)
		return (-1);
	va_end(ap);
	return (len);
}
