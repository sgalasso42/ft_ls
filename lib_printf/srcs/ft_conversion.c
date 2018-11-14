/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 13:52:19 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/05 14:56:52 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_sign_assign(void *value, int base, char lenght, char *conv_res)
{
	if (lenght == '1')
		return (ft_itoa_base((char)value, base, conv_res));
	else if (lenght == 'h')
		return (ft_itoa_base((short int)value, base, conv_res));
	else if (lenght == 'j')
		return (ft_itoa_base((intmax_t)value, base, conv_res));
	else if (lenght == 'l')
		return (ft_itoa_base((long int)value, base, conv_res));
	else if (lenght == '2')
		return (ft_itoa_base((long long int)value, base, conv_res));
	else if (lenght == 'z')
		return (ft_itoa_base((size_t)value, base, conv_res));
	else if (lenght == 'D')
		return (ft_itoa_base((long int)value, base, conv_res));
	return (ft_itoa_base((int)value, base, conv_res));
}

char	*ft_unsign_assign(void *value, int base, char lenght, char *conv_res)
{
	if (lenght == '1')
		return (ft_uitoa_base((unsigned char)value, base, conv_res));
	else if (lenght == 'h')
		return (ft_uitoa_base((short unsigned int)value, base, conv_res));
	else if (lenght == 'j')
		return (ft_uitoa_base((uintmax_t)value, base, conv_res));
	else if (lenght == 'l')
		return (ft_uitoa_base((long unsigned int)value, base, conv_res));
	else if (lenght == '2')
		return (ft_uitoa_base((unsigned long long int)value, base, conv_res));
	else if (lenght == 'z')
		return (ft_uitoa_base((size_t)value, base, conv_res));
	else if (lenght == 'p')
		return (ft_uitoa_base((uintmax_t)value, base, conv_res));
	return (ft_uitoa_base((unsigned int)value, base, conv_res));
}

char	*ft_conversion(t_struct *params, void *arg, const char *conv_res)
{
	if (params->ty == 'p')
		ft_unsign_assign(arg, 16, 'p', (char *)conv_res);
	else if (ft_is_signed(params->ty) && params->ty != 'D')
		ft_sign_assign(arg, 10, params->le, (char *)conv_res);
	else if (ft_is_signed(params->ty) && params->ty == 'D')
		ft_sign_assign(arg, 10, 'D', (char *)conv_res);
	else if (params->ty == 'O')
		ft_unsign_assign(arg, 8, 'l', (char *)conv_res);
	else if (params->ty == 'o')
		ft_unsign_assign(arg, 8, params->le, (char *)conv_res);
	else if (params->ty == 'u')
		ft_unsign_assign(arg, 10, params->le, (char *)conv_res);
	else if (params->ty == 'U')
		ft_unsign_assign(arg, 10, 'l', (char *)conv_res);
	else if (params->ty == 'x')
		ft_unsign_assign(arg, 16, params->le, (char *)conv_res);
	else if (params->ty == 'X')
		ft_str_up(ft_unsign_assign(arg, 16, params->le, (char *)conv_res));
	else if (params->ty == 'b')
		return (ft_uitoa_base((uintmax_t)arg, 2, (char *)conv_res));
	return ((char *)conv_res);
}
