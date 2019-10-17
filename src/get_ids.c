/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ids.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 17:06:53 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/09 15:00:11 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*group_name(gid_t gid)
{
	struct group	*gr;
	char			*group_name;

	gr = getgrgid(gid);
	group_name = ft_strdup(gr->gr_name);
	return (group_name);
}

char	*user_name(uid_t uid)
{
	struct passwd	*pw;
	char			*user_name;

	pw = getpwuid(uid);
	user_name = ft_strdup(pw->pw_name);
	return (user_name);
}

char	*get_symlink(const char *path)
{
	char	*str;
	int		len;

	str = ft_strnew(1024);
	if ((len = readlink(path, str, 1024)) != -1)
		str[len] = '\0';
	return (str);
}
