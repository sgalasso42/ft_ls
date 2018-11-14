/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gencat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 19:22:04 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/12 15:34:39 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_ccat_gen(char *str, char c, t_size *tsize)
{
	str[tsize->pos] = c;
	tsize->size++;
	tsize->pos++;
	ft_purge(tsize, str);
}

void	ft_strnaddc_gen(char *str, char c, int len, t_size *tsize)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_ccat_gen(str, c, tsize);
		i++;
	}
}

void	ft_strncat_gen(char *str, char *s2, int len, t_size *tsize)
{
	int i;

	i = 0;
	while (i < len)
	{
		ft_ccat_gen(str, s2[i], tsize);
		i++;
	}
}

void	ft_strcat_gen(char *str, char *s2, t_size *tsize)
{
	int i;

	i = 0;
	while (s2[i])
	{
		ft_ccat_gen(str, s2[i], tsize);
		i++;
	}
}

void	ft_cnull(t_struct *params, t_size *tsize, char *to_print)
{
	int i;

	i = 0;
	if (params->wi != -1 && params->fm != '-')
	{
		ft_strnaddc_gen(to_print, ' ', params->wi - 1, tsize);
		tsize->size++;
		tsize->pos++;
		return ;
	}
	else if (params->wi != -1 && params->fm == '-')
	{
		tsize->size++;
		tsize->pos++;
		ft_strnaddc_gen(to_print, ' ', params->wi - 1, tsize);
		return ;
	}
	tsize->size++;
	tsize->pos++;
	ft_purge(tsize, to_print);
}
