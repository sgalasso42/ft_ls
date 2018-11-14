/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_dircontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 00:08:27 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/13 23:11:43 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_set_dircontent(t_data *data)
{
	t_elem		*temp;

	temp = data->dir->elem;
	while (data->dir->elem)
	{
		if (data->flags[0] == 'l')
			ft_printf("%c%-11s %3d %5s %5s %5d %13.12s %s\n",
			data->dir->elem->type,
			data->dir->elem->perms,
			data->dir->elem->links,
			data->dir->elem->user,
			data->dir->elem->grp,
			data->dir->elem->size,
			data->dir->elem->date,
			data->dir->elem->name);
		else
			ft_putendl(data->dir->elem->name);
		data->dir->elem = data->dir->elem->next;
	}
	data->dir->elem = temp;
}
