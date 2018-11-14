/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_prepa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:00:24 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/12 14:22:14 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_digit_prepa(t_struct *params, void *arg, char *conv_res,
		t_concstuff *cstuff)
{
	ft_prefix(params, cstuff->prefix, arg);
	if ((params->ty == 'o' || params->ty == 'O') &&
			params->pr > cstuff->conv_size)
		ft_bzero(cstuff->prefix, 3);
	if (params->f0 == '0' && params->fm != '-' &&
			(params->pr == -1 || (long int)arg < 0))
		cstuff->filler = '0';
	if ((ft_is_nb(params->ty) || params->ty == 'p') && params->pr >
			cstuff->conv_size)
	{
		if (conv_res[0] == '-')
			cstuff->prec = params->pr + 1 - cstuff->conv_size;
		else
			cstuff->prec = params->pr - cstuff->conv_size;
	}
	if (params->wi != -1 && params->wi > cstuff->prec + cstuff->conv_size +
			ft_strlen_printf(cstuff->prefix))
		cstuff->width = params->wi - (cstuff->prec + cstuff->conv_size +
				ft_strlen_printf(cstuff->prefix));
	if (params->wi != -1 && params->wi > cstuff->prec + cstuff->conv_size +
			ft_strlen_printf(cstuff->prefix))
		cstuff->width = params->wi - (cstuff->prec + cstuff->conv_size +
				ft_strlen_printf(cstuff->prefix));
}
