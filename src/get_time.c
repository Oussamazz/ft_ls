/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:03:57 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/09 15:04:20 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		*get_time(struct stat *sb)
{
	char *str;
	char *tmp;
	char *year;
	char *myctime;

	if (time(0) - sb->st_mtime > 15778463)
	{
		myctime = ft_strdup(ctime(&sb->st_mtime));
		myctime[ft_strlen(myctime) - 1] = '\0';
		tmp = ft_strsub(myctime, 4, 8);
		tmp[ft_strlen(tmp) - 1] = '\0';
		year = ft_strsub(myctime, 20, 23);
		str = ft_strjoin(tmp, year);
		ft_strdel(&year);
		ft_strdel(&myctime);
		ft_strdel(&tmp);
	}
	else
		str = ft_strsub(ctime(&sb->st_mtime), 4, 12);
	return (str);
}
