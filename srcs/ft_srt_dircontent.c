/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srt_dircontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 21:26:48 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/13 23:19:13 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_elem		*ft_lst_swap(t_elem *prev, t_elem *elem, t_elem *next, t_elem *temp)
{
	elem->next = next->next;
	next->next = elem;
	if (prev == 0)
		return (next);
	prev->next = next;
	return (temp);
}

int			ft_choose_swap(t_data *data)
{
	int		diff;

	diff = 0;
	if (data->flags[4] == 't')
	{
		diff = data->dir->elem->next->m_time - data->dir->elem->m_time;
		if (diff == 0)
			diff = ft_strcmp(data->dir->elem->name,
			data->dir->elem->next->name);
	}
	else
		diff = ft_strcmp(data->dir->elem->name,
		data->dir->elem->next->name);
	diff = (data->flags[3] == 'r') ? -diff : diff;
	return (diff);
}

void		ft_sort_ascii(t_data *data)
{
	t_elem	*temp;
	t_elem	*prev;
	int		sorted;

	sorted = 0;
	temp = data->dir->elem;
	while (!sorted)
	{
		prev = 0;
		sorted = 1;
		while (data->dir->elem->next)
		{
			if (ft_choose_swap(data) > 0)
			{
				temp = ft_lst_swap(prev, data->dir->elem,
				data->dir->elem->next, temp);
				sorted = 0;
			}
			prev = data->dir->elem;
			if (data->dir->elem->next)
				data->dir->elem = data->dir->elem->next;
		}
		data->dir->elem = temp;
	}
}

void		ft_srt_dircontent(t_data *data)
{
	if (!(data->dir->elem))
		return ;
	ft_sort_ascii(data);
}
