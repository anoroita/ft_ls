/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbrucker <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 15:01:37 by nbrucker          #+#    #+#             */
/*   Updated: 2017/12/30 15:21:58 by nbrucker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <errno.h>
# include <time.h>
# include <sys/xattr.h>
# include <sys/acl.h>

typedef struct		s_path
{
	char			*name;
	struct stat		stats;
	struct s_path	*next;
	struct s_path	*previous;
}					t_path;

typedef struct		s_option
{
	uint8_t			l:1;
	uint8_t			u:1;
	uint8_t			a:1;
	uint8_t			r:1;
	uint8_t			t:1;
	uint8_t			d:1;
	uint8_t			g:1;
	uint8_t			e:1;
	uint8_t			v:1;
	uint8_t			h:1;
	uint8_t			s:1;
	uint8_t			i:1;
	uint8_t			n:1;
	struct s_path	*path;
	unsigned int	x;
}					t_option;

void				ft_get_opt(int argc, char **argv, t_option *opt);
void				ft_order(t_path *path, t_option *opt);
void				ft_add_path(char *str, t_option *opt);
void				ft_start_print(t_path *path, t_option *call, int x);
void				ft_add_folder(t_option *opt, struct dirent *file,
					t_option *call, char *str);
void				ft_add_file(t_option *opt, struct dirent *file,
					t_option *call, char *str);
void				ft_handle_file(t_path *file, t_path *folder,
					t_option *call, char *path);
char				*ft_getname(char *str, char *path);
int					ft_nbrlen(int nbr);
void				ft_print_type(struct stat stats);
void				ft_print_rights(struct stat stats);
void				ft_print_nbrlnks(t_path *file, int x);
void				ft_print_user(t_path *file, int x, int n);
void				ft_print_group(t_path *file, int x, int n);
void				ft_print_file(t_path *file, t_option *call, char *path);
void				ft_free_path(t_path *path);
void				ft_error_ls(char *str, int x);
int					ft_name(t_path *path, t_option *call, int x);
void				ft_setcolor(struct stat stats);
void				ft_print_user_uid(t_path *file, int x);
void				ft_print_group_gid(t_path *file, int x);
void				ft_print_acl(t_path *file, char *path);
void				ft_print_i(t_path *file, t_option *call);
void				ft_print_e(char *path);
void				ft_print_v(char *path);
void				ft_next_check(char *str, int i, t_option *opt);

#endif
