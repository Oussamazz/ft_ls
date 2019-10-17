/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:50:55 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/09 15:43:59 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	free_struct(t_permission *tab)
{
	if (tab)
	{
		ft_strdel(&(tab)->permission_grp);
		ft_strdel(&(tab)->permission_oth);
		ft_strdel(&(tab)->permission_user);
		ft_strdel(&(tab)->time);
		ft_strdel(&(tab)->user_group);
		ft_strdel(&(tab)->user_name);
		ft_strdel(&(tab)->symlink_name);
		ft_strdel(&(tab)->file_name);
		free(tab);
	}
}

void	free_tree(t_file *files)
{
	if (files == NULL)
		return ;
	free_tree(files->left);
	ft_strdel(&(files->file_name));
	free_tree(files->right);
	free(files);
}

void	free_args(t_arg *tab, int ac)
{
	int i;

	i = 0;
	while (i < ac - 1)
	{
		if (tab[i].flag)
			free(tab[i].flag);
		if (tab[i].name)
			free(tab[i].name);
		i++;
	}
	free(tab);
}

void	free_tree_size(t_file *files, t_sizes *size)
{
	free_tree(files);
	free(size);
}

void	free_args_errors(char **arr, char **errors, int no_paths)
{
	free_two_dim(arr, no_paths);
	free_two_dim(errors, no_paths);
}
