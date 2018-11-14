/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 21:15:26 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/05 14:07:43 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_unicode_str(wchar_t *arg, char *to_print, t_size *tsize)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (!(ft_unicode_process((wint_t)arg[i], to_print, tsize)))
			return (0);
		i++;
	}
	return (1);
}
