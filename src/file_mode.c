/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 14:43:30 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/17 15:20:35 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	st_mode(t_permission *arr, struct stat *sb)
{
	if (S_ISSOCK(sb->st_mode))
		arr[0].st_mode = 's';
	if (S_ISDIR(sb->st_mode))
		arr[0].st_mode = 'd';
	if (S_ISCHR(sb->st_mode))
		arr[0].st_mode = 'c';
	if (S_ISFIFO(sb->st_mode))
		arr[0].st_mode = 'p';
	if (S_ISBLK(sb->st_mode))
		arr[0].st_mode = 'b';
	if (S_ISREG(sb->st_mode))
		arr[0].st_mode = '-';
	if (S_ISLNK(sb->st_mode))
		arr[0].st_mode = 'l';
}

bool	is_reg(const char *arr)
{
	struct stat st;

	lstat(arr, &st);
	if ((st.st_mode & S_IFMT) == S_IFREG)
		return (1);
	return (0);
}

int		check_dir(struct stat *sb)
{
	if (S_ISDIR(sb->st_mode))
		return (1);
	if ((S_ISLNK(sb->st_mode)))
		return (2);
	return (0);
}
