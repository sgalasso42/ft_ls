/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_nb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 18:50:55 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/06 18:59:51 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_signed(char c)
{
	return (c == 'd' || c == 'D' || c == 'i');
}

int		ft_is_unsigned(char c)
{
	return (c == 'o' || c == 'O' || c == 'u' ||
		c == 'U' || c == 'x' || c == 'X' || c == 'p');
}

int		ft_is_nb(char c)
{
	return (ft_is_signed(c) || ft_is_unsigned(c));
}
