/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_perms.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 01:04:24 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 01:07:07 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_get_usr_perms(t_elem *elem, struct stat *path_stat)
{
	elem->perms[0] = (path_stat->st_mode & S_IRUSR) ? 'r' : '-';
	elem->perms[1] = (path_stat->st_mode & S_IWUSR) ? 'w' : '-';
	if (path_stat->st_mode & S_IXUSR)
		elem->perms[2] = (path_stat->st_mode & S_ISUID) ? 's' : 'x';
	else
		elem->perms[2] = (path_stat->st_mode & S_ISUID) ? 'S' : '-';
}

void	ft_get_grp_perms(t_elem *elem, struct stat *path_stat)
{
	elem->perms[3] = (path_stat->st_mode & S_IRGRP) ? 'r' : '-';
	elem->perms[4] = (path_stat->st_mode & S_IWGRP) ? 'w' : '-';
	if (path_stat->st_mode & S_IXGRP)
		elem->perms[5] = (path_stat->st_mode & S_ISGID) ? 's' : 'x';
	else
		elem->perms[5] = (path_stat->st_mode & S_ISGID) ? 'S' : '-';
}

void	ft_get_oth_perms(t_elem *elem, struct stat *path_stat)
{
	elem->perms[6] = (path_stat->st_mode & S_IROTH) ? 'r' : '-';
	elem->perms[7] = (path_stat->st_mode & S_IWOTH) ? 'w' : '-';
	if (path_stat->st_mode & S_IXOTH)
		elem->perms[8] = (path_stat->st_mode & S_ISVTX) ? 't' : 'x';
	else
		elem->perms[8] = (path_stat->st_mode & S_ISVTX) ? 'T' : '-';
}
