/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_align.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:50:00 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/09 15:51:34 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	ft_putstr_align_usr(char *str, t_sizes *sizes)
{
	int no_spaces;
	int i;

	no_spaces = sizes->size_username - ft_strlen(str);
	ft_putstr_w2space(str);
	i = 0;
	while (i++ < no_spaces)
		ft_putchar(' ');
}

void	ft_putstr_align_grp(char *str, t_sizes *sizes)
{
	int no_spaces;
	int i;

	no_spaces = sizes->size_groupname - ft_strlen(str);
	ft_putstr_w2space(str);
	i = 0;
	while (i++ < no_spaces)
		ft_putchar(' ');
}

void	ft_putnbr_size_align(int n, t_sizes *size)
{
	int no_spaces;
	int i;

	no_spaces = size->size - ft_numlen(n);
	i = 0;
	while (i++ < no_spaces)
		ft_putchar(' ');
	ft_putnbr_wspace(n);
}
