/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_l.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 13:17:57 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/16 12:01:42 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_permission	*get_permissions_file(const char *path, t_arg **arg, int is_dir)
{
	struct stat		sb;
	t_file			*files;
	t_sizes			*size;

	files = NULL;
	if (path != NULL)
	{
		if (lstat(path, &sb) == -1)
			return ((t_permission*)error(path, arg));
		if (check_dir(&sb) == 1 && !is_exist(arg, 'd') && !is_dir)
		{
			size = stock_files(path, &files, arg);
			if (is_exist(arg, 'l') && size != NULL)
				ls_dir_free(path, files, arg, size);
			else if (size != NULL)
				print_normal(path, files, arg, size);
			free_tree_size(files, size);
			return (NULL);
		}
		return (stock_data_stat(path, &sb, arg, is_dir));
	}
	return (NULL);
}

t_permission	*stock_data_stat(const char *path, struct stat *sb,
t_arg **arg, int is_dir)
{
	t_permission *tab;

	if (!(tab = (t_permission*)ft_memalloc(sizeof(t_permission))))
		return (NULL);
	st_mode(tab, sb);
	tab[0].permission_user = permissions_user(*sb);
	tab[0].permission_grp = permissions_grp(*sb);
	tab[0].permission_oth = permissions_oth(*sb);
	tab[0].st_nlink = sb->st_nlink;
	tab[0].user_name = user_name(sb->st_uid);
	tab[0].user_group = group_name(sb->st_gid);
	tab[0].r_dev_maj = major(sb->st_rdev);
	tab[0].r_dev_min = minor(sb->st_rdev);
	tab[0].file_size = sb->st_size;
	tab[0].st_blocks = sb->st_blocks;
	tab[0].time = get_time(sb);
	if (!is_exist(arg, 'd') && tab[0].st_mode != 'l' && is_dir)
		tab[0].file_name = ft_strdup(ft_strrchr_path(path, '/'));
	else
		tab[0].file_name = ft_strdup(path);
	if (tab[0].st_mode == 'l')
		tab[0].symlink_name = get_symlink(path);
	return (tab);
}

void			ls_l(char *arr, t_arg **args)
{
	int				no_path;
	struct stat		sb;
	t_permission	*permissions;
	t_sizes			*size;

	permissions = NULL;
	if (lstat(arr, &sb) == -1)
		return ;
	size = init_values();
	permissions = get_permissions_file(arr, args, 0);
	if (is_exist(args, 'l'))
		print_info(permissions, args, size);
	else if (is_exist(args, 'd'))
		ft_putendl(arr);
	free(size);
	free_struct(permissions);
}
