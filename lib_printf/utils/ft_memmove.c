/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 21:42:19 by sgalasso          #+#    #+#             */
/*   Updated: 2018/05/06 18:52:07 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*src2;
	unsigned char	*dst2;

	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	if (dst2 > src2)
	{
		dst2 = dst2 + len;
		src2 = src2 + len;
		while (len--)
			*--dst2 = *--src2;
	}
	else
		ft_memcpy(dst, src, len);
	return ((void *)dst);
}
