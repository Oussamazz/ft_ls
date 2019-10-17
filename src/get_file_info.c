/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:44:01 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/16 12:27:24 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_sizes			*stock_files(const char *path, t_file **node, t_arg **tab)
{
	char			*tmp;
	DIR				*dir;
	struct dirent	*dt;
	struct stat		sb;
	t_sizes			*sizes;

	sizes = init_values();
	if ((dir = opendir(path)) == NULL || lstat(path, &sb) == -1)
		return ((t_sizes*)error(path, tab));
	while ((dt = readdir(dir)) != NULL)
	{
		if (checking_flags(dt->d_name, tab))
		{
			tmp = create_path(path, dt->d_name);
			lstat(tmp, &sb);
			sizes = get_sizes(&sb, sizes);
			insert(node, dt->d_name, sb.st_mtime, tab);
			ft_strdel(&tmp);
		}
	}
	closedir(dir);
	return (sizes);
}

t_sizes			*get_sizes(struct stat *sb, t_sizes *sizes)
{
	char		*tmp;

	tmp = NULL;
	sizes->total = sizes->total + sb->st_blocks;
	if (S_ISBLK(sb->st_mode) || S_ISCHR(sb->st_mode))
	{
		if (ft_numlen(major(sb->st_rdev)) > sizes->size_major)
			sizes->size_major = ft_numlen(major(sb->st_rdev));
		if (ft_numlen(minor(sb->st_rdev)) > sizes->size_minor)
			sizes->size_minor = ft_numlen(minor(sb->st_rdev));
		sizes->size = (ft_numlen(major(sb->st_rdev))
		+ (ft_numlen(minor(sb->st_rdev)) + 5));
	}
	else if (ft_numlen(sb->st_size) > sizes->size)
		sizes->size = ft_numlen(sb->st_size);
	if (ft_numlen(sb->st_nlink) > sizes->size_nlink)
		sizes->size_nlink = ft_numlen(sb->st_nlink);
	if (ft_strlen(tmp = user_name(sb->st_uid)) > sizes->size_username)
		sizes->size_username = ft_strlen(tmp);
	ft_strdel(&tmp);
	if (ft_strlen(tmp = group_name(sb->st_gid)) > sizes->size_groupname)
		sizes->size_groupname = ft_strlen(tmp);
	ft_strdel(&tmp);
	return (sizes);
}

t_sizes			*init_values(void)
{
	t_sizes		*sizes;

	sizes = NULL;
	if (!(sizes = ft_memalloc(sizeof(t_sizes))))
		return (sizes);
	sizes->total = 0;
	sizes->size = 1;
	sizes->size_minor = 1;
	sizes->size_major = 1;
	sizes->size_groupname = 1;
	sizes->size_username = 1;
	sizes->size_nlink = 1;
	return (sizes);
}
