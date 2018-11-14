/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/04 15:41:10 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/12 15:36:09 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_digit_apply(char *conv_res, t_concstuff *cstuff,
		t_string *result, t_size *tsize)
{
	if (conv_res[0] == '-')
	{
		ft_memmove(conv_res, conv_res + 1, ft_strlen_printf(conv_res));
		ft_ccat(cstuff->prefix, '-');
	}
	if (cstuff->filler == '0')
	{
		ft_strcat_gen(result->to_print, cstuff->prefix, tsize);
		ft_strnaddc_gen(result->to_print, cstuff->filler, cstuff->width, tsize);
	}
	else
	{
		ft_strnaddc_gen(result->to_print, cstuff->filler, cstuff->width, tsize);
		ft_strcat_gen(result->to_print, cstuff->prefix, tsize);
	}
	ft_strnaddc_gen(result->to_print, '0', cstuff->prec, tsize);
	ft_strcat_gen(result->to_print, conv_res, tsize);
}

int		ft_process_digit(t_struct *params, t_string *result,
		t_size *tsize, t_concstuff *cstuff)
{
	char	conv_res[66];

	ft_bzero(conv_res, 66);
	if ((params->pr != 0 || (int)result->arg != 0) ||
	((params->ty == 'o' || params->ty == 'O') && params->fd == '#'))
	{
		if (!(ft_conversion(params, result->arg, conv_res)))
			return (0);
	}
	cstuff->conv_size = ft_strlen_printf(conv_res);
	ft_digit_prepa(params, result->arg, conv_res, cstuff);
	if (params->fm != '-')
		ft_digit_apply(conv_res, cstuff, result, tsize);
	else
	{
		ft_strcat_gen(result->to_print, cstuff->prefix, tsize);
		ft_strnaddc_gen(result->to_print, '0', cstuff->prec, tsize);
		ft_strcat_gen(result->to_print, conv_res, tsize);
		ft_strnaddc_gen(result->to_print, cstuff->filler, cstuff->width, tsize);
	}
	return (1);
}

int		ft_alpha_cat(t_struct *params, t_string *result, t_size *tsize,
		int conv_size)
{
	if (params->ty == 'S' || (params->ty == 's' && params->le == 'l'))
	{
		if (!(ft_unicode_str((wchar_t *)result->arg,
		(char *)result->to_print, tsize)))
			return (0);
	}
	else if (params->ty == 'C' || (params->ty == 'c' && params->le == 'l'))
	{
		if (!(ft_unicode_process((wint_t)result->arg,
		(char *)result->to_print, tsize)))
			return (0);
	}
	else if (params->ty == 'c' || params->ty == '%')
		ft_ccat_gen(result->to_print, (char)result->arg, tsize);
	else if (params->ty == 's')
	{
		if (params->ty == 's' && params->pr != -1 &&
		params->pr < ft_strlen_printf((char *)result->arg))
			ft_strncat_gen(result->to_print, (char *)result->arg,
			conv_size, tsize);
		else
			ft_strcat_gen(result->to_print, (char *)result->arg, tsize);
	}
	return (1);
}

int		ft_process_alpha(t_struct *params, t_string *result,
		t_size *tsize, t_concstuff *cstuff)
{
	int		conv_size;
	char	*str;

	str = (char *)result->arg;
	conv_size = ft_conv_size_alpha(params, result->arg);
	ft_prefix(params, cstuff->prefix, result->arg);
	if (params->ty == '%' && params->f0 == '0')
		cstuff->filler = '0';
	if (params->wi != -1 && params->wi > cstuff->prec + conv_size
	+ ft_strlen_printf(cstuff->prefix))
		cstuff->width = params->wi - (cstuff->prec + conv_size
		+ ft_strlen_printf(cstuff->prefix));
	if (params->wi != -1 && params->pr != -1 &&
	params->ty == 's' && conv_size > params->pr)
		cstuff->width = params->wi - conv_size;
	if (params->fm != '-')
		ft_strnaddc_gen(result->to_print, cstuff->filler, cstuff->width, tsize);
	ft_strcat_gen(result->to_print, cstuff->prefix, tsize);
	ft_strnaddc_gen(result->to_print, '0', cstuff->prec, tsize);
	if (!(ft_alpha_cat(params, result, tsize, conv_size)))
		return (0);
	if (params->fm == '-')
		ft_strnaddc_gen(result->to_print, cstuff->filler, cstuff->width, tsize);
	return (1);
}

int		ft_process(t_struct *params, t_string *result, t_size *tsize)
{
	t_concstuff		cstuff;

	cstuff.filler = ' ';
	cstuff.width = 0;
	cstuff.prec = 0;
	ft_bzero(cstuff.prefix, 3);
	if (ft_is_nb(params->ty))
	{
		if (!(ft_process_digit(params, result, tsize, &cstuff)))
			return (0);
	}
	else
	{
		if (!(ft_process_alpha(params, result, tsize, &cstuff)))
			return (0);
	}
	return (1);
}
