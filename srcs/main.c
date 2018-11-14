/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:55:00 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 01:41:31 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int			ft_is_dir(char *path, t_data *data)
{
	struct stat		path_stat;
	int				ret;

	ret = (data->flags[0] == 'l' ? lstat : stat)(path, &path_stat);
	if (ret == -1)
		return (0);
	if (S_ISDIR(path_stat.st_mode))
		return (1);
	return (0);
}

int			ft_init_data(t_data *data)
{
	ft_bzero(data, sizeof(t_data));
	ft_memset(data->flags, '.', 6);
	return (1);
}

void		ft_start_search(int nb_paths, char *arg, t_data *data)
{
	t_elem		*start_elem;
	int			total;

	ft_lstnew(nb_paths, arg, data);
	ft_get_dircontent(data->dir->name, data);
	ft_srt_dircontent(data);
	start_elem = data->dir->elem;
	if (arg && nb_paths > 1 && ft_is_dir(arg, data))
		ft_printf("%s:\n", arg);
	total = ft_calc_total(data->dir);
	if (data->flags[0] == 'l' && total != -1
	&& ft_is_dir(arg, data))
		ft_printf("total %d\n", total);
	ft_rec_dircontent(data);
	data->dir->elem = start_elem;
	ft_free_dir(data->dir);
}

int			main(int argc, char **argv)
{
	t_data		data;
	int			nb_paths;
	int			i;

	ft_init_data(&data);
	if ((i = ft_parse_flags(argv++, &data)) != -1)
	{
		nb_paths = argc - 1 - i;
		if (nb_paths > 0)
			ft_sort_paths(argv, i, &data);
		while (argv[i] || nb_paths == 0)
		{
			ft_start_search(nb_paths, argv[i], &data);
			if (argv[++i] && nb_paths > 0)
				ft_putchar('\n');
			if (nb_paths == 0)
				break ;
		}
	}
	else
	{
		ft_putendl_fd("ft_ls: illegal option", 2);
		ft_putendl_fd("usage: ./ft_ls [-alrtAR] [file ...]", 2);
	}
	return (0);
}
