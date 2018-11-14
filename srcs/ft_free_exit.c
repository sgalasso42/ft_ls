/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:12:21 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 01:16:53 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_err_exit(t_data *data)
{
	t_elem	*temp_elem;
	t_dir	*temp_dir;

	while (data->temp)
	{
		free(data->temp->path);
		free(data->temp->name);
		while (data->temp->elem)
		{
			free(data->temp->elem->name);
			free(data->temp->elem->user);
			free(data->temp->elem->grp);
			free(data->temp->elem->date);
			temp_elem = data->temp->elem;
			data->temp->elem = data->temp->elem->next;
			free(temp_elem);
		}
		temp_dir = data->temp;
		data->temp = data->temp->next;
		free(temp_dir);
	}
	exit(EXIT_FAILURE);
}

void		ft_free_dir(t_dir *dir)
{
	t_elem	*temp;

	free(dir->path);
	free(dir->name);
	while (dir->elem)
	{
		free(dir->elem->name);
		free(dir->elem->user);
		free(dir->elem->grp);
		free(dir->elem->date);
		temp = dir->elem;
		dir->elem = dir->elem->next;
		free(temp);
	}
	free(dir);
}
