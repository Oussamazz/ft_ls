/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:50:30 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/17 12:44:59 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	print_info(t_permission *tab, t_arg **t, t_sizes *sizes)
{
	if (tab != NULL)
	{
		if (is_exist(t, 's'))
			ft_putnbr_wspace(tab[0].st_blocks);
		ft_putchar(tab[0].st_mode);
		ft_putstr(tab[0].permission_user);
		ft_putstr(tab[0].permission_grp);
		ft_putstr_w2space(tab[0].permission_oth);
		ft_print_nlink(tab[0].st_nlink, sizes);
		if (!is_exist(t, 'g'))
			ft_putstr_align_usr(tab[0].user_name, sizes);
		ft_putstr_align_grp(tab[0].user_group, sizes);
		if (tab[0].st_mode == 'c' || tab[0].st_mode == 'b')
			print_min_maj(tab, sizes);
		else
			ft_putnbr_size_align(tab[0].file_size, sizes);
		ft_putstr_wspace(tab[0].time);
		ft_putstr_color(tab[0].file_name, t, tab);
		if (tab[0].st_mode == 'l')
			print_symlink_name(tab[0].symlink_name);
		ft_putchar('\n');
	}
}

void	print_min_maj(t_permission *tab, t_sizes *size)
{
	int no_space1;
	int no_space2;
	int i;

	no_space1 = size->size_major - ft_numlen(tab->r_dev_maj);
	ft_putchar(' ');
	while (i++ < no_space1)
		ft_putchar(' ');
	ft_putnbr(tab[0].r_dev_maj);
	ft_putstr(",");
	no_space2 = size->size_minor - ft_numlen(tab->r_dev_min);
	i = 0;
	ft_putchar(' ');
	while (i++ < no_space2)
		ft_putchar(' ');
	ft_putnbr_wspace(tab[0].r_dev_min);
}

void	ft_print_nlink(int nlink, t_sizes *sizes)
{
	int no_spaces;
	int i;

	no_spaces = sizes->size_nlink - ft_numlen(nlink);
	i = 0;
	while (i++ < no_spaces)
		ft_putchar(' ');
	ft_putnbr_wspace(nlink);
}

void	print_symlink_name(char *str)
{
	ft_putchar(' ');
	ft_putstr_wspace("->");
	ft_putstr(str);
}

void	print_normal(const char *path, t_file *files,
t_arg **arg, t_sizes *size)
{
	struct stat sb;

	lstat(path, &sb);
	if (((*arg)->no_paths > 1 && check_dir(&sb) == 1) || is_exist(arg, 'R'))
		print_four_strings((char*)path, ":\n", "", "");
	if (!is_exist(arg, 'r'))
	{
		in_order(files);
		if ((*arg)->no_newlines > 1)
			ft_putchar('\n');
		(*arg)->no_newlines -= 1;
	}
	else
	{
		reverse_order(files);
		if ((*arg)->no_newlines > 1)
			ft_putchar('\n');
		(*arg)->no_newlines -= 1;
	}
}
