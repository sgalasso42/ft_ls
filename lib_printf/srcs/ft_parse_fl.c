/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/06 20:04:23 by sgalasso          #+#    #+#             */
/*   Updated: 2018/05/06 20:10:39 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_fl(char c)
{
	return (c == '#' || c == '+' || c == '-' || c == ' ' || c == '0');
}

int		ft_parse_fl(t_struct *params, const char *format)
{
	char	temp;
	int		c;

	c = 0;
	temp = 0;
	params->fl = -1;
	params->fm = -1;
	params->f0 = -1;
	params->fd = -1;
	if (!ft_is_fl(*format))
		return (0);
	while (ft_is_fl(*format))
	{
		if (*format == '0')
			params->f0 = *format;
		if (*format == '-')
			params->fm = *format;
		if (params->fl != '+' && (*format == '+' || *format == ' '))
			params->fl = *format;
		if (*format == '#')
			params->fd = '#';
		format++;
		c++;
	}
	return (c);
}
