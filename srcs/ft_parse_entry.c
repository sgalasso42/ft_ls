/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_entry.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:38:34 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 01:41:06 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**ft_struct_assign(int i, int j, char **argv, t_data *data)
{
	if (argv[i][j] == 'l')
		data->flags[0] = 'l';
	else if (argv[i][j] == 'R')
		data->flags[1] = 'R';
	else if (argv[i][j] == 'a')
		data->flags[2] = 'a';
	else if (argv[i][j] == 'r')
		data->flags[3] = 'r';
	else if (argv[i][j] == 't')
		data->flags[4] = 't';
	else if (argv[i][j] == 'A')
		data->flags[5] = 'A';
	else if (argv[i][j] != '1')
		return (0);
	return (argv);
}

int			ft_parse_flags(char **argv, t_data *data)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (argv[i][j++] != '-')
			return (i - 1);
		while (argv[i][j])
		{
			if (!(argv = ft_struct_assign(i, j, argv, data)))
				return (-1);
			j++;
		}
		i++;
	}
	return (i - 1);
}
