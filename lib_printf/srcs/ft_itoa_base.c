/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:14:22 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/12 15:35:15 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_len(intmax_t nb, intmax_t base)
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

char	*ft_spe_uitoa(intmax_t value, char *conv_res)
{
	if ((intmax_t)(-value - 1) == (9223372036854775807))
		ft_strcat_printf(conv_res, "-9223372036854775808");
	if (value == 0)
		conv_res[0] = 48;
	return (conv_res);
}

char	*ft_itoa_base(intmax_t value, int base, char *conv_res)
{
	char		*tab;
	intmax_t	temp;
	int			ng;
	int			i;

	ng = 0;
	tab = "0123456789abcdef";
	if (((intmax_t)(-value - 1) == (9223372036854775807)) || value == 0)
		return (ft_spe_uitoa(value, conv_res));
	if (value < 0)
	{
		value = -value;
		ng = 1;
	}
	temp = value;
	i = ft_len(value, base) + ng + 1;
	conv_res[i--] = 0;
	while (temp > 0)
	{
		conv_res[i--] = tab[temp % base];
		temp = temp / base;
	}
	if (ng == 1)
		conv_res[i] = '-';
	return (conv_res);
}
