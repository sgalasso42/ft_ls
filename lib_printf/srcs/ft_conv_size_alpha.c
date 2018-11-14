/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_size_alpha.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:55:44 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/12 14:20:43 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_conv_size_alpha(t_struct *params, void *arg)
{
	int		conv_size;

	if (params->ty == 'c' || params->ty == 'C' || params->ty == '%')
		conv_size = 1;
	else
	{
		if (params->ty == 's' && params->pr != -1 &&
				params->pr < ft_strlen_printf((char *)arg))
			conv_size = params->pr;
		else if (params->ty == 'S' || (params->ty == 's' && params->le == 'l'))
			conv_size = ft_nb_bytes((wchar_t *)arg);
		else
			conv_size = ft_strlen_printf((char *)arg);
	}
	return (conv_size);
}
