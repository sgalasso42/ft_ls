/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:52:40 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/12 15:35:50 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_prefix(t_struct *params, char *prefix, void *arg)
{
	if ((params->fd == '#' && (unsigned long long int)arg > 0)
	|| params->ty == 'p')
	{
		if (params->ty == 'x' || params->ty == 'p')
			ft_strcat_printf(prefix, "0x");
		if (params->ty == 'X')
			ft_strcat_printf(prefix, "0X");
	}
	if (params->fd == '#' && (unsigned long long int)arg > 0)
	{
		if (params->ty == 'o' || params->ty == 'O')
			ft_strcat_printf(prefix, "0");
	}
	if (params->fl == '+' && ft_is_signed(params->ty) && (int)arg >= 0)
		prefix[0] = '+';
	if (params->fl == ' ' && ft_is_signed(params->ty) && (int)arg >= 0)
		prefix[0] = ' ';
	return (prefix);
}
