/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 16:03:37 by sgalasso          #+#    #+#             */
/*   Updated: 2018/06/08 12:47:47 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_nb_bytes(wchar_t *str)
{
	wchar_t	*temp;
	int		nb;
	int		c;
	int		i;

	temp = str;
	nb = 0;
	c = 0;
	i = 0;
	while (str[i])
	{
		c = ft_bitlen(str[i]);
		if (c <= 7)
			nb += 1;
		else if (c <= 11)
			nb += 2;
		else if (c <= 16)
			nb += 3;
		else if (c <= 21)
			nb += 4;
		i++;
	}
	str = temp;
	return (nb);
}

void	ft_assign_bit(t_unistuff *ustf, int *c_ij, int nbo, int value)
{
	if (c_ij[0] < value)
	{
		if (ustf->c & 1)
			ustf->res[c_ij[1]] = (ustf->res[c_ij[1]] | 1 << c_ij[0]);
		ustf->c >>= 1;
	}
	else if (ustf->m[nbo] & 1)
		ustf->res[c_ij[1]] = (ustf->res[c_ij[1]] | 1 << c_ij[0]);
	ustf->m[nbo] >>= 1;
}

int		ft_transfert_o(t_unistuff *ustf, int nbo, int nbx)
{
	int		c_ij[2];

	c_ij[0] = 0;
	c_ij[1] = nbo;
	while (c_ij[1] >= 0)
	{
		if (c_ij[1] == 0 && c_ij[0] < 8)
			ft_assign_bit(ustf, c_ij, nbo, nbx);
		else if (c_ij[1] == 0 && c_ij[0] == 8)
			c_ij[1]--;
		else if (c_ij[0] < 8)
			ft_assign_bit(ustf, c_ij, nbo, 6);
		else if (c_ij[0] == 8)
		{
			c_ij[0] = -1;
			c_ij[1]--;
		}
		c_ij[0]++;
	}
	return (nbo + 1);
}

int		ft_unicode(t_unistuff *ustf)
{
	int		size;

	size = ft_bitlen(ustf->c);
	if (size <= 0 || ustf->c < 0 || (ustf->c > 255 && size <= 7) ||
	(ustf->c >= 0xd800 && ustf->c <= 0xdfff) || ustf->c > 0x10ffff)
		return (0);
	if (size <= 7)
		return (ft_transfert_o(ustf, 0, 7));
	else if (size <= 11)
		return (ft_transfert_o(ustf, 1, 5));
	else if (size <= 16)
		return (ft_transfert_o(ustf, 2, 4));
	else if (size <= 21)
		return (ft_transfert_o(ustf, 3, 3));
	else
		return (0);
}

int		ft_unicode_process(wint_t c, char *to_print, t_size *tsize)
{
	t_unistuff	ustf;

	ustf.c = c;
	ft_bzero(ustf.res, 5);
	ustf.m[0] = 0x0;
	ustf.m[1] = 0xc080;
	ustf.m[2] = 0xe08080;
	ustf.m[3] = 0xf0808080;
	if (!(ft_unicode(&ustf)))
		return (0);
	ft_strcat_gen(to_print, ustf.res, tsize);
	return (1);
}
