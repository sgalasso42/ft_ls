/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_pr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:12:06 by sgalasso          #+#    #+#             */
/*   Updated: 2018/05/06 18:02:17 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_parse_pr(t_struct *params, const char *format, va_list *ap)
{
	if (*format == '.')
	{
		format++;
		if (*format == '*')
		{
			params->pr = (int)va_arg(*ap, void *);
			return (2);
		}
		else if (*format >= '0' && *format <= '9')
		{
			params->pr = ft_atoi(format);
			return (ft_nbrlen(params->pr) + 1);
		}
		params->pr = 0;
		return (1);
	}
	params->pr = -1;
	return (0);
}
