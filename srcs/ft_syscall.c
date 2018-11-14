/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_syscall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:27:14 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 01:22:10 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_type(t_elem *elem, struct stat *path_stat)
{
	if (S_ISDIR(path_stat->st_mode))
		elem->type = 'd';
	else if (S_ISREG(path_stat->st_mode))
		elem->type = '-';
	else if (S_ISCHR(path_stat->st_mode))
		elem->type = 'c';
	else if (S_ISBLK(path_stat->st_mode))
		elem->type = 'b';
	else if (S_ISFIFO(path_stat->st_mode))
		elem->type = 'p';
	else if (S_ISLNK(path_stat->st_mode))
		elem->type = 'l';
	else if (S_ISSOCK(path_stat->st_mode))
		elem->type = 's';
}

void	ft_get_symb_link(char *path, t_elem *elem, t_data *data)
{
	char			link[PATH_MAX];
	ssize_t			link_size;

	if (elem->type == 'l' && data->flags[0] == 'l')
	{
		ft_strncat(link, path, sizeof(link));
		if ((link_size = readlink(link, link, sizeof(link) - 1)) != -1)
		{
			link[link_size] = '\0';
			if (!(elem->name = ft_strjoin_free(elem->name, " -> ")))
				ft_err_exit(data);
			if (!(elem->name = ft_strjoin_free(elem->name, link)))
				ft_err_exit(data);
		}
		else
			ft_err_exit(data);
	}
}

void	ft_get_id(t_elem *elem, struct stat *path_stat, t_data *data)
{
	struct passwd	*pwd;
	struct group	*grp;

	if (!(pwd = getpwuid(path_stat->st_uid)))
	{
		if (!(elem->user = ft_itoa(path_stat->st_uid)))
			ft_err_exit(data);
	}
	else if (!(elem->user = ft_strdup(pwd->pw_name)))
		ft_err_exit(data);
	if (!(grp = getgrgid(path_stat->st_gid)))
	{
		if (!(elem->grp = ft_itoa(path_stat->st_gid)))
			ft_err_exit(data);
	}
	else if (!(elem->grp = ft_strdup(grp->gr_name)))
		ft_err_exit(data);
}

void	ft_get_date(t_elem *elem, struct stat *path_stat, t_data *data)
{
	time_t		m_time;

	m_time = path_stat->st_mtime;
	elem->m_time = m_time;
	if ((time(NULL) - m_time > 15768000) || (m_time - time(NULL) < -15768000))
	{
		if (!(elem->date = ft_strdup(ctime(&m_time) + 4)))
			ft_err_exit(data);
		elem->date[7] = ' ';
		ft_memmove(elem->date + 8, elem->date + 16, 4);
	}
	else
	{
		if (!(elem->date = ft_strdup(ctime(&m_time) + 4)))
			ft_err_exit(data);
	}
}

void	ft_syscall(char *path, t_elem *elem, t_data *data)
{
	struct stat		path_stat;
	int				ret;

	ret = lstat(path, &path_stat);
	if (ret == -1)
		return ;
	ft_get_type(elem, &path_stat);
	ft_get_usr_perms(elem, &path_stat);
	ft_get_grp_perms(elem, &path_stat);
	ft_get_oth_perms(elem, &path_stat);
	ft_get_symb_link(path, elem, data);
	elem->links = path_stat.st_nlink;
	ft_get_id(elem, &path_stat, data);
	elem->size = path_stat.st_size;
	ft_get_date(elem, &path_stat, data);
	elem->blocks = path_stat.st_blocks;
}
