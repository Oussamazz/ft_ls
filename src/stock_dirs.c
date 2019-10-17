/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock_dirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 22:08:03 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/16 12:29:04 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	stock_dirs(char **arr, t_file **files, t_arg **args)
{
	struct stat	sb;
	char		*path;
	int			i;
	int			check;

	i = 0;
	check = 0;
	while (arr[i] != NULL)
	{
		check = lstat(arr[i], &sb);
		if (check != -1 && check_dir(&sb) >= 1)
		{
			if (check_dir(&sb) == 2 && !is_exist(args, 'l'))
				link_func(arr[i], files, &sb, args);
			else
				insert(files, arr[i], sb.st_mtime, args);
			(*args)->no_dirs += 1;
			(*args)->no_newlines += 1;
		}
		i++;
	}
	if (is_exist(args, 'r') && !is_exist(args, 'R'))
		do_ls_dir_r(files, args);
	else if (!is_exist(args, 'R'))
		do_ls_dir(files, args);
}

void	link_func(char *arr, t_file **files, struct stat *sb, t_arg **args)
{
	char *tmp;
	char *path;

	tmp = get_symlink(arr);
	path = create_path_symlink(arr, tmp);
	insert(files, path, sb->st_mtime, args);
	free(arr);
	arr = ft_strdup(tmp);
}

void	do_ls_dir(t_file **files, t_arg **args)
{
	if (!*files)
		return ;
	do_ls_dir(&(*files)->left, args);
	ls_l((*files)->file_name, args);
	do_ls_dir(&(*files)->right, args);
}

void	do_ls_dir_r(t_file **files, t_arg **args)
{
	if (!*files)
		return ;
	do_ls_dir(&(*files)->right, args);
	ls_l((*files)->file_name, args);
	do_ls_dir(&(*files)->left, args);
}
