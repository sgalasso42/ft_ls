/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgalasso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:33:05 by sgalasso          #+#    #+#             */
/*   Updated: 2018/11/14 02:46:53 by sgalasso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft.h"
# include "ft_printf.h"
# include <dirent.h>
# include <limits.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>

typedef struct s_elem		t_elem;
typedef struct s_dir		t_dir;
typedef struct s_data		t_data;

/*
** Protriete d'un element
*/

struct			s_elem
{
	char		*name;
	char		type;
	char		perms[10];
	int			links;
	char		*user;
	char		*grp;
	int			size;
	time_t		m_time;
	char		*date;
	int			blocks;
	t_elem		*next;
};

/*
** Propriete d'un dossier
*/

struct			s_dir
{
	char		*path;
	char		*name;
	t_elem		*elem;
	t_dir		*next;
};

/*
**       flags
**  0  1  2  3  4  5
** [l][R][a][r][t][A]
*/

struct			s_data
{
	char		flags[6];
	t_dir		*temp;
	t_dir		*dir;
};

void			ft_free_dir(t_dir *dir);
void			ft_err_exit(t_data *data);
int				ft_is_lnk(char *path);
void			ft_err_exit(t_data *data);
void			ft_free_dir(t_dir *dir);
int				ft_calc_total(t_dir *dir);
void			ft_srt_dircontent(t_data *data);
void			ft_set_dircontent(t_data *data);
void			ft_rec_dircontent(t_data *data);
void			ft_get_dircontent(char *path, t_data *data);
void			ft_syscall(char *path, t_elem *elem, t_data *data);
void			ft_sort_paths(char **argv, int i, t_data *data);
void			ft_get_usr_perms(t_elem *elem, struct stat *path_stat);
void			ft_get_grp_perms(t_elem *elem, struct stat *path_stat);
void			ft_get_oth_perms(t_elem *elem, struct stat *path_stat);
void			ft_lstnew(int nb_paths, char *arg, t_data *data);
int				ft_lstadd(char *name, t_data *data);
char			**ft_struct_assign(int i, int j, char **argv, t_data *data);
int				ft_parse_flags(char **argv, t_data *data);

#endif
