/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_ty.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 11:14:21 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/06 19:31:20 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_ty(char c)
{
	return (c == 'b' || c == 's' || c == 'S' || c == 'p' || c == 'd' ||
			c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' ||
			c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' ||
			c == '%');
}

int		ft_parse_ty(t_struct *params, const char *format)
{
	if (ft_is_ty(*format))
	{
		params->ty = *format;
		return (1);
	}
	params->ty = -1;
	return (0);
}
