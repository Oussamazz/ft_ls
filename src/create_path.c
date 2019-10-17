/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:19:42 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/14 13:01:32 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*create_path(const char *s1, const char *s2)
{
	int		strlen_s1;
	char	*s;
	char	*tmp;

	tmp = NULL;
	if (s1 && s2)
	{
		s = ft_strdup(s1);
		tmp = s;
		strlen_s1 = ft_strlen(s1);
		if (s1[strlen_s1 - 1] != '/')
		{
			s = ft_strjoin(s1, "/");
			ft_strdel(&tmp);
			tmp = s;
		}
		s = ft_strjoin(s, s2);
		ft_strdel(&tmp);
		return (s);
	}
	return (NULL);
}

char	*create_path_symlink(const char *str, const char *str2)
{
	char *s;
	char *tmp;

	s = NULL;
	tmp = NULL;
	if (str && str2)
	{
		tmp = ft_strrchr(str, '/');
		if (tmp)
			s = ft_strjoin("/", str2);
		else
			s = ft_strdup(str2);
		return (s);
	}
	return (NULL);
}
