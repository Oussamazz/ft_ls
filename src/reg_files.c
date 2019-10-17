/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reg_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 18:12:10 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/17 12:47:53 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		stock_reg_files(char **arr, t_file **files, t_arg **args)
{
	struct stat sb;
	int			i;
	int			check;
	int			flag;

	i = 0;
	flag = 0;
	check = 0;
	while (arr[i] != NULL)
	{
		check = lstat(arr[i], &sb);
		if (check_dir(&sb) != 1 && check_dir(&sb) != 2 && check != -1)
			insert(files, arr[i], sb.st_mtime, args);
		if (check_dir(&sb) == 1)
			flag = 1;
		i++;
	}
	if (is_exist(args, 'r'))
		do_ls_reg_r(files, args, flag);
	else
		do_ls_reg(files, args, flag);
	if (is_exist(args, 'l') && flag == 1 && *files != NULL)
		ft_putchar('\n');
	return ;
}

void		do_ls_reg(t_file **files, t_arg **args, int flag)
{
	if (!*files)
		return ;
	if (is_exist(args, 'l'))
	{
		do_ls_reg(&(*files)->left, args, flag);
		ls_l((*files)->file_name, args);
		do_ls_reg(&(*files)->right, args, flag);
		return ;
	}
	if (is_exist(args, 'r'))
	{
		reverse_order(*files);
		if (flag == 1)
			ft_putchar('\n');
	}
	else
	{
		in_order(*files);
		if (flag == 1)
			ft_putchar('\n');
	}
}

void		do_ls_reg_r(t_file **files, t_arg **args, int flag)
{
	if (!*files)
		return ;
	if (is_exist(args, 'l'))
	{
		do_ls_reg(&(*files)->right, args, flag);
		ls_l((*files)->file_name, args);
		do_ls_reg(&(*files)->left, args, flag);
		return ;
	}
	if (is_exist(args, 'r'))
	{
		reverse_order(*files);
		if (flag == 1)
			ft_putchar('\n');
	}
	else
	{
		in_order(*files);
		if (flag == 1)
			ft_putchar('\n');
	}
}
