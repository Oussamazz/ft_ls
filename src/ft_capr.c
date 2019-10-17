/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_capr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/27 13:06:23 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/16 12:31:12 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_r(char **arr, t_arg **args)
{
	int			i;
	struct stat	sb;

	i = 0;
	while (i < (*args)->no_paths)
	{
		lstat(arr[i], &sb);
		if (check_dir(&sb) == 1)
			ls_capr(arr[i], args);
		i++;
	}
}

void	ls_capr(char *arr, t_arg **args)
{
	char		*path;
	struct stat sb;
	t_file		*files;
	t_sizes		*sizes;

	path = NULL;
	files = NULL;
	if (lstat(arr, &sb) == -1)
		return ;
	sizes = stock_files(arr, &files, args);
	if (is_exist(args, 'l') && sizes != NULL)
		ls_l(arr, args);
	else if (sizes != NULL)
		print_normal((const char*)arr, files, args, sizes);
	if (is_exist(args, 'r'))
		ls_recursive_r(arr, files, args);
	else
		ls_recursive(arr, files, args);
	free_tree_size(files, sizes);
}

void	ls_recursive(const char *path_name, t_file *files, t_arg **args)
{
	char		*path;
	struct stat sb;

	path = NULL;
	if (files == NULL)
		return ;
	ls_recursive(path_name, files->left, args);
	if (!ft_strequ(files->file_name, ".") && !ft_strequ(files->file_name, ".."))
	{
		path = create_path(path_name, files->file_name);
		lstat(path, &sb);
		if (check_dir(&sb) == 1)
		{
			ft_putchar('\n');
			ls_capr(path, args);
		}
		ft_strdel(&path);
	}
	ls_recursive(path_name, files->right, args);
}

void	ls_recursive_r(const char *path_name, t_file *files, t_arg **args)
{
	char		*path;
	struct stat sb;

	path = NULL;
	if (files == NULL)
		return ;
	ls_recursive_r(path_name, files->right, args);
	if (!ft_strequ(files->file_name, ".") && !ft_strequ(files->file_name, ".."))
	{
		path = create_path(path_name, files->file_name);
		lstat(path, &sb);
		if (check_dir(&sb) == 1)
		{
			ft_putchar('\n');
			ls_capr(path, args);
		}
		ft_strdel(&path);
	}
	ls_recursive_r(path_name, files->left, args);
}
