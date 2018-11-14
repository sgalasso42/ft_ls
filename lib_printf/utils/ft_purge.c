/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_purge.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 16:42:02 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/06 16:44:31 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_purge(t_size *tsize, char *str)
{
	if (tsize->pos == BUFF_SIZE)
	{
		write(1, str, BUFF_SIZE);
		ft_bzero(str, BUFF_SIZE);
		tsize->pos = 0;
	}
}
