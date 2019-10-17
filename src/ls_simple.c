/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_simple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 13:31:34 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/15 10:29:03 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ls_dir(const char *path, t_file *head, t_arg **flags, t_sizes *size)
{
	if (head == NULL)
		return ;
	list_recur(path, head, flags, size);
	if ((*flags)->no_newlines > 1)
	{
		ft_putchar('\n');
		(*flags)->no_newlines -= 1;
	}
}

void	list_recur(const char *path, t_file *head, t_arg **flags, t_sizes *size)
{
	t_permission	*tab;
	char			*tmp;

	tab = NULL;
	tmp = NULL;
	if (is_exist(flags, 'r'))
	{
		ls_dir(path, head->right, flags, size);
		tmp = create_path(path, head->file_name);
		tab = get_permissions_file(tmp, flags, 1);
		print_info(tab, flags, size);
		ft_strdel(&tmp);
		ls_dir(path, head->left, flags, size);
		free_struct(tab);
	}
	else
	{
		ls_dir(path, head->left, flags, size);
		tmp = create_path(path, head->file_name);
		tab = get_permissions_file(tmp, flags, 1);
		print_info(tab, flags, size);
		ft_strdel(&tmp);
		ls_dir(path, head->right, flags, size);
		free_struct(tab);
	}
}

void	print_total(const char *path, int total, t_arg **args)
{
	ft_putstr_wspace("total");
	ft_putnbr(total);
	ft_putchar('\n');
}
