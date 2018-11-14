/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:18:25 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 01:41:43 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_lstnew(int nb_paths, char *arg, t_data *data)
{
	if (!(data->dir = (t_dir *)ft_memalloc(sizeof(t_dir))))
		ft_err_exit(data);
	if (!(data->dir->path = ft_strdup("")))
		ft_err_exit(data);
	if (nb_paths > 0)
	{
		if (!(data->dir->name = ft_strdup(arg)))
			ft_err_exit(data);
	}
	else
	{
		if (!(data->dir->name = ft_strdup(".")))
			ft_err_exit(data);
	}
	data->dir->elem = 0;
	data->dir->next = 0;
	data->temp = data->dir;
}

int			ft_lstadd(char *name, t_data *data)
{
	if (!(data->dir->next = (t_dir *)ft_memalloc(sizeof(t_dir))))
		return (0);
	if (!(data->dir->next->name = ft_strdup(name)))
		ft_err_exit(data);
	if (!(data->dir->next->path =
	ft_strjoin(data->dir->path, data->dir->name)))
		ft_err_exit(data);
	if (!(data->dir->next->path =
	ft_strjoin_free(data->dir->next->path, "/")))
		ft_err_exit(data);
	data->dir->next->elem = 0;
	data->dir->next->next = 0;
	data->dir = data->dir->next;
	ft_putchar('\n');
	return (1);
}
