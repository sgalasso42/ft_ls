/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_dircontent.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 12:38:42 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 02:18:42 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_new_element(char *path, char *d_name, t_data *data)
{
	char *new_path;

	if (!(data->dir->elem = (t_elem *)ft_memalloc(sizeof(t_elem))))
		ft_err_exit(data);
	if (!(data->dir->elem->name = ft_strdup(d_name)))
		ft_err_exit(data);
	if (ft_strequ(path, ""))
	{
		if (!(new_path = ft_strjoin(path, "")))
			ft_err_exit(data);
	}
	else
	{
		if (!(new_path = ft_strjoin(path, "/")))
			ft_err_exit(data);
	}
	if (!(new_path = ft_strjoin_free(new_path, d_name)))
		ft_err_exit(data);
	ft_syscall(new_path, data->dir->elem, data);
	free(new_path);
}

void	ft_add_element(char *path, char *d_name, t_data *data)
{
	char *new_path;

	if (!(data->dir->elem->next = (t_elem *)ft_memalloc(sizeof(t_elem))))
		ft_err_exit(data);
	if (!(data->dir->elem->next->name = ft_strdup(d_name)))
		ft_err_exit(data);
	if (!(new_path = ft_strjoin(path, "/")))
		ft_err_exit(data);
	if (!(new_path = ft_strjoin_free(new_path, d_name)))
		ft_err_exit(data);
	ft_syscall(new_path, data->dir->elem->next, data);
	data->dir->elem = data->dir->elem->next;
	free(new_path);
}

void	ft_hidden_dos(t_data *data, char *path)
{
	if (errno == ENOTDIR)
		ft_new_element("", data->dir->name, data);
	else
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
}

int		ft_hidden_elem(struct dirent *de, t_data *data)
{
	return ((de->d_name)[0] != '.' || data->flags[2] == 'a')
	|| (data->flags[5] == 'A' && !ft_strequ(de->d_name, ".")
	&& !ft_strequ(de->d_name, ".."));
}

void	ft_get_dircontent(char *path, t_data *data)
{
	t_elem				*temp;
	struct dirent		*de;
	DIR					*dr;

	temp = 0;
	if (!(dr = opendir(path)))
	{
		ft_hidden_dos(data, path);
		return ;
	}
	while ((de = readdir(dr)))
	{
		if (ft_hidden_elem(de, data))
		{
			if (!data->dir->elem)
			{
				ft_new_element(path, de->d_name, data);
				temp = data->dir->elem;
			}
			else
				ft_add_element(path, de->d_name, data);
		}
	}
	data->dir->elem = (data->dir->elem) ? temp : 0;
	closedir(dr);
}
