/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_le.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:12:30 by sgalasso          #+#    #+#             */
/*   Updated: 2018/05/06 17:05:26 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_le(char c)
{
	return (c == 'h' || c == 'l' || c == 'j' || c == 'z');
}

int		ft_parse_le(t_struct *params, const char *format)
{
	if (ft_is_le(*format))
	{
		if (*format == 'h' && format[1] == 'h')
		{
			params->le = '1';
			return (2);
		}
		else if (*format == 'l' && format[1] == 'l')
		{
			params->le = '2';
			return (2);
		}
		else
		{
			params->le = *format;
			return (1);
		}
	}
	params->le = -1;
	return (0);
}
