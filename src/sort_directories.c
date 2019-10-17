/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_directories.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 11:27:02 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/09 15:56:03 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	**sort_directories(char **arr, int path_counter)
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
		if (ft_strcmp(arr[i], arr[i + 1]) > 0 && check_cmp_type(&sb, &sb2) == 1)
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

void	sort_by_type(char **arr, int no_paths)
{
	int			i;
	char		*tmp;
	struct stat sb;
	struct stat sb2;

	tmp = NULL;
	i = 0;
	while (i + 1 < no_paths && arr[i] != NULL)
	{
		lstat(arr[i], &sb);
		lstat(arr[i + 1], &sb2);
		if ((check_dir(&sb) && !check_dir(&sb2)))
		{
			tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}
