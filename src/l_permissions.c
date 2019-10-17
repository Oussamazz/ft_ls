/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_permissions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 16:22:05 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/09 15:00:54 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*permissions_user(struct stat sb)
{
	char	*str;

	if (!(str = ft_strnew(3)))
		return (NULL);
	ft_memset(str, '-', 3);
	if (sb.st_mode & S_IRUSR)
		str[0] = 'r';
	if (sb.st_mode & S_IWUSR)
		str[1] = 'w';
	if ((sb.st_mode & S_IXUSR) && (sb.st_mode & S_ISUID))
		str[2] = 's';
	else if (!(sb.st_mode & S_IXUSR) && (sb.st_mode & S_ISUID))
		str[2] = 'S';
	else if (sb.st_mode & S_IXUSR)
		str[2] = 'x';
	return (str);
}

char	*permissions_grp(struct stat sb)
{
	char	*str;

	if (!(str = ft_strnew(3)))
		return (NULL);
	ft_memset(str, '-', 3);
	if (sb.st_mode & S_IRGRP)
		str[0] = 'r';
	if (sb.st_mode & S_IWGRP)
		str[1] = 'w';
	if ((sb.st_mode & S_IXGRP) && (sb.st_mode & S_ISGID))
		str[2] = 's';
	else if (!(sb.st_mode & S_IXGRP) && (sb.st_mode & S_ISGID))
		str[2] = 'S';
	else if (sb.st_mode & S_IXGRP)
		str[2] = 'x';
	return (str);
}

char	*permissions_oth(struct stat sb)
{
	char	*str;

	if (!(str = ft_strnew(3)))
		return (NULL);
	ft_memset(str, '-', 3);
	if (sb.st_mode & S_IROTH)
		str[0] = 'r';
	if (sb.st_mode & S_IWOTH)
		str[1] = 'w';
	if ((sb.st_mode & S_IXOTH) && (sb.st_mode & S_ISVTX))
		str[2] = 't';
	else if (!(sb.st_mode & S_IXOTH) && (sb.st_mode & S_ISVTX))
		str[2] = 'T';
	else if (sb.st_mode & S_IXOTH)
		str[2] = 'x';
	return (str);
}
