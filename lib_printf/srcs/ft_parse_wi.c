/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_wi.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:14:01 by sgalasso          #+#    #+#             */
/*   Updated: 2018/05/06 17:05:11 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_wi(char c)
{
	return (c == '*' || (c >= '0' && c <= '9'));
}

int		ft_parse_wi(t_struct *params, const char *format, va_list *ap)
{
	if (ft_is_wi(*format))
	{
		if (*format == '*')
		{
			params->wi = (int)va_arg(*ap, void *);
			return (1);
		}
		if (*format >= '0' && *format <= '9')
		{
			params->wi = ft_atoi(format);
			return (ft_nbrlen(params->wi));
		}
	}
	params->wi = -1;
	return (0);
}
