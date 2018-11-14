/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rec_dircontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 00:11:32 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 02:42:39 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		ft_calc_total(t_dir *dir)
{
	t_elem	*temp;
	int		total;

	total = 0;
	if (!dir->elem)
		return (-1);
	temp = dir->elem;
	while (dir->elem)
	{
		total += dir->elem->blocks;
		dir->elem = dir->elem->next;
	}
	dir->elem = temp;
	return (total);
}

char	*ft_make_next_elem(t_data *data)
{
	char	*next_elem;

	if (!(next_elem = ft_strjoin(data->dir->path, data->dir->name)))
		ft_err_exit(data);
	if (!(next_elem = ft_strjoin_free(next_elem, "/")))
		ft_err_exit(data);
	if (!(next_elem = ft_strjoin_free(next_elem, data->dir->elem->name)))
		ft_err_exit(data);
	return (next_elem);
}

void	ft_iter_in_rec(char *next_elem, t_data *data)
{
	t_elem		*start_elem;
	int			total;
	t_dir		*temp;

	temp = data->dir;
	ft_lstadd(data->dir->elem->name, data);
	ft_get_dircontent(next_elem, data);
	ft_srt_dircontent(data);
	total = ft_calc_total(data->dir);
	if (next_elem[0] == '/')
		ft_printf("%s:\n", next_elem + 1);
	else
		ft_printf("%s:\n", next_elem);
	if (data->flags[0] == 'l' && total != -1)
		ft_printf("total %d\n", total);
	start_elem = data->dir->elem;
	ft_rec_dircontent(data);
	data->dir->elem = start_elem;
	ft_free_dir(data->dir);
	data->dir = temp;
}

void	ft_rec_dircontent(t_data *data)
{
	char		*next_elem;

	ft_set_dircontent(data);
	while (data->dir->elem)
	{
		next_elem = ft_make_next_elem(data);
		if (data->flags[1] == 'R'
		&& data->dir->elem->type == 'd'
		&& !ft_strequ(data->dir->elem->name, ".")
		&& !ft_strequ(data->dir->elem->name, ".."))
			ft_iter_in_rec(next_elem, data);
		data->dir->elem = data->dir->elem->next;
		free(next_elem);
	}
}
