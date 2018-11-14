/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:09:52 by sgalasso          #+#    #+#             */
/*   Updated: 2018/05/09 22:21:54 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_ulen(uintmax_t nb, uintmax_t base)
{
	int c;

	c = 0;
	while (nb >= base)
	{
		nb = nb / base;
		c++;
	}
	return (c);
}

char	*ft_uitoa_base(uintmax_t value, int base, char *conv_res)
{
	char		*tab;
	uintmax_t	temp;
	int			i;

	tab = "0123456789abcdef";
	if (value == 0)
	{
		conv_res[0] = 48;
		return (conv_res);
	}
	temp = value;
	i = ft_ulen(value, base) + 1;
	conv_res[i] = 0;
	i--;
	while (temp > 0)
	{
		conv_res[i] = tab[temp % base];
		temp = temp / base;
		i--;
	}
	return (conv_res);
}
