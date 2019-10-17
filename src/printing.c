/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 09:13:38 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/16 12:31:42 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_four_strings(char *s, char *s1, char *s2, char *s3)
{
	if (s && s1 && s2 && s3)
	{
		ft_putstr(s);
		ft_putstr(s1);
		ft_putstr(s2);
		ft_putstr(s3);
	}
}

void	ft_print_words_tables(char **tab)
{
	int i;

	i = 0;
	while (tab[i] != 0)
	{
		ft_putendl(tab[i]);
		i++;
	}
}

void	ls_dir_free(const char *path,
	t_file *files, t_arg **args, t_sizes *size)
{
	struct stat sb;

	lstat(path, &sb);
	if (is_exist(args, 'R') || (*args)->no_dirs > 1)
		print_four_strings((char*)path, ":\n", "", "");
	if (size->size_username != 1)
		print_total(path, size->total, args);
	ls_dir(path, files, args, size);
}
