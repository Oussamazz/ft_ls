/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/05 21:28:19 by oelazzou          #+#    #+#             */
/*   Updated: 2019/12/10 15:50:41 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <stdbool.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <pwd.h>
# include <time.h>
# include <grp.h>
# include <stdio.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "../libft/libft.h"
# define PATH_COUNT_CHECK(X) ((X) == 0 ? (X) = 1 : (X))
# define COLOR_RED "\x1b[31m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_BLUE "\033[1;36m"
# define COLOR_MAG "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_CHAR_DEV "\033[43;36m"
# define COLOR_BLOCK "\033[44;36m"
# define COLOR_LINK "\033[0;35m"

typedef	struct		s_arg
{
	int				no_paths;
	int				no_dirs;
	int				no_newlines;
	char			*flag;
	char			*name;
}					t_arg;

typedef struct		s_file
{
	char			*file_name;
	time_t			mtime;
	int				total;
	struct s_file	*left;
	struct s_file	*right;
}					t_file;

typedef	struct		s_stack
{
	t_file			*files;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_permission
{
	char			st_mode;
	int				st_blocks;
	char			*permission_user;
	char			*permission_grp;
	char			*permission_oth;
	int				st_nlink;
	char			*user_name;
	char			*user_group;
	int				file_size;
	int				r_dev_maj;
	int				r_dev_min;
	char			*time;
	char			*file_name;
	char			*symlink_name;
}					t_permission;

typedef struct		s_sizes
{
	int				total;
	int				size;
	int				size_nlink;
	int				size_groupname;
	int				size_username;
	int				size_major;
	int				size_minor;
}					t_sizes;
void				insert(t_file **node, const char *data,
time_t heure, t_arg **tab);
void				print_asciiorder(t_file *node);
void				print_reverseorder(t_file *node);
void				insert_tflag(t_file **node, const char *data,
time_t heure, t_arg **tab);
t_sizes				*get_sizes(struct stat *sb, t_sizes *size);
t_sizes				*init_values(void);
t_arg				*stock_flags(int ac, char **av);
bool					flag_checker(char *str);
bool				checking_flags(const char *arr, t_arg **tab);
char				**directories(int ac, t_arg **tab);
char				**alloc_current(char **arr);
char				**sort_directories(char **arr, int path_counter);
void				sort_by_type(char **arr, int no_paths);
t_sizes				*stock_files(const char *path, t_file **node, t_arg **tab);
t_permission		*stock_data_stat(const char *path,
struct stat *sb, t_arg **arg, int is_dir);
char				*permissions_user(struct stat sb);
char				*permissions_grp(struct stat sb);
char				*permissions_oth(struct stat sb);
char				*group_name(gid_t gid);
char				*user_name(uid_t uid);
void				st_mode(t_permission *arr, struct stat *sb);
char				*get_time(struct stat *sb);
t_permission		*get_permissions_file(const char *path,
t_arg **tab, int is_dir);
void				print_info(t_permission *tab, t_arg **t, t_sizes *sizes);
void				ft_putstr_align_usr(char *str, t_sizes *sizes);
void				ft_putstr_align_grp(char *str, t_sizes *sizes);
void				ft_print_nlink(int nlink, t_sizes *sizes);
void				print_min_maj(t_permission *tab, t_sizes *size);
void				print_total(const char *path, int total, t_arg **args);
int					is_exist(t_arg **tab, char flag);
char				*create_path(const char *s1, const char *s2);
char				**get_errors(char **arr, int no_paths, t_arg **tab);
void				list_recur(const char *path, t_file *head,
t_arg **flags, t_sizes *size);
char				*error(const char *str, t_arg **args);
void				ls_dir(const char *path, t_file *head,
t_arg **flags, t_sizes *size);
void				free_struct(t_permission *tab);
void				free_tree(t_file *files);
void				free_tree_size(t_file *files, t_sizes *size);
void				free_args_errors(char **arr, char **errors, int no_paths);
void				ft_putnbr_size_align(int n, t_sizes *size);
void				print_symlink_name(char *str);
char				*get_symlink(const char *path);
void				ls_l(char *arr, t_arg **args);
bool				is_reg(const char *arr);
int					check_dir(struct stat *sb);
void				ls_capr(char *arr, t_arg **args);
void				ls_recursive(const char *path_name,
t_file *files, t_arg **args);
void				ls_recursive_r(const char *path_name,
t_file *files, t_arg **args);
int					get_num_of_files(DIR *dir);
void				ls_r(char **arr, t_arg **args);
void				print_four_strings(char *s, char *s1, char *s2, char *s3);
void				print_path(const char *path, t_arg **arg);
void				ft_print_words_tables(char **tab);
void				free_args(t_arg *tab, int no_path);
void				print_normal(const char *path, t_file *files,
t_arg **arg, t_sizes *size);
void				ls_dir_free(const char *path, t_file *files,
t_arg **arg, t_sizes *size);
void				ft_putstr_color(char const *s, t_arg **args,
t_permission *tab);
void				ft_putstr_color_continue(char const *s, t_permission *tab);
void				reset_color(void);
void				stock_reg_files(char **arr, t_file **files, t_arg **args);
void				do_ls_reg(t_file **files, t_arg **args, int flag);
void				do_ls_reg_r(t_file **files, t_arg **args, int flag);
void				stock_dirs(char **arr, t_file **files, t_arg **args);
void				do_ls_dir(t_file **files, t_arg **args);
void				do_ls_dir_r(t_file **files, t_arg **args);
char				*create_path_symlink(const char *str, const char *str2);
void				link_func(char *arr, t_file **files,
struct stat *sb, t_arg **args);
t_file				*pop_stack(t_stack **head);
void				push_stack(t_stack **head, t_file *files);
bool				is_empty(t_stack *stack);
void				in_order(t_file *root);
void				reverse_order(t_file *root);
bool	is_file_exist(char *str);
#endif
