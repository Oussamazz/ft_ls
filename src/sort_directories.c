/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:27:02 by oelazzou          #+#    #+#             */
/*   Updated: 2019/12/10 16:49:47 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		**sort_directories(char **arr, int path_counter)
{
	int			i;
	char		*tmp;
	struct stat sb;
	struct stat sb2;

	tmp = NULL;
	i = 0;
	sort_by_type(arr, path_counter);
	while (i + 1 < path_counter && arr[i] != NULL)
	{
		lstat(arr[i], &sb);
		lstat(arr[i + 1], &sb2);
		if (ft_strcmp(arr[i], arr[i + 1]) > 0)
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
	return (arr);
}

void		sort_by_type(char **arr, int no_paths)
{
	int			i;
	char		*tmp;
	struct stat	sb;
	struct stat	sb2;

	tmp = NULL;
	i = -1;
	while (i + 2 <= no_paths && arr[i] != NULL && arr[i + 1] != NULL)
	{
		lstat(arr[i], &sb);
		lstat(arr[i + 1], &sb2);
		if ((is_file_exist(arr[i]) == 1 && is_file_exist(arr[i + 1]) == 0))
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

bool		is_file_exist(char *str)
{
	DIR *dir;

	if ((dir = opendir(str)) == NULL)
		return (0);
	closedir(dir);
	return (1);
}
