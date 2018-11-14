/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_srt_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 23:54:51 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 02:27:13 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

time_t	ft_path_syscall(char *path, t_data *data)
{
	time_t			m_time;
	struct stat		path_stat;
	int				ret;

	ret = (data->flags[0] == 'l' ? lstat : stat)(path, &path_stat);
	if (ret == -1)
		return (0);
	m_time = path_stat.st_mtime;
	return (m_time);
}

void	ft_swap_paths(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int		ft_select_sort(int diff, char **argv, int i, t_data *data)
{
	if (data->flags[4] == 't')
	{
		diff = ft_path_syscall(argv[i + 1], data)
		- ft_path_syscall(argv[i], data);
		if (diff == 0)
			diff = ft_strcmp(argv[i], argv[i + 1]);
	}
	else
		diff = ft_strcmp(argv[i], argv[i + 1]);
	diff = (data->flags[3] == 'r') ? -diff : diff;
	return (diff);
}

void	ft_sort_paths(char **argv, int i, t_data *data)
{
	int		sorted;
	int		temp;
	int		diff;

	diff = 0;
	temp = i;
	sorted = 0;
	while (!sorted)
	{
		sorted = 1;
		i = temp;
		while (argv[i + 1])
		{
			diff = ft_select_sort(diff, argv, i, data);
			if (diff > 0)
			{
				ft_swap_paths(&(argv[i]), &(argv[i + 1]));
				sorted = 0;
				break ;
			}
			i++;
		}
	}
}
