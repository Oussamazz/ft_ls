/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 09:12:05 by oelazzou          #+#    #+#             */
/*   Updated: 2019/12/10 16:12:29 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	reset_color(void)
{
	ft_putstr("\033[0m");
	return ;
}

void	ft_putstr_color(char const *s, t_arg **args, t_permission *tab)
{
	if (is_exist(args, 'G'))
	{
		if (tab->st_mode == 'd')
		{
			ft_putstr(COLOR_BLUE);
			ft_putstr(s);
			reset_color();
		}
		else if (tab->st_mode == 'p')
		{
			ft_putstr(COLOR_YELLOW);
			ft_putstr(s);
			reset_color();
		}
		else if (tab->st_mode == 'c')
		{
			ft_putstr(COLOR_CHAR_DEV);
			ft_putstr(s);
			reset_color();
		}
		ft_putstr_color_continue(s, tab);
	}
	else
		ft_putstr(s);
}

void	ft_putstr_color_continue(char const *s, t_permission *tab)
{
	if (tab->st_mode == 'b')
	{
		ft_putstr(COLOR_BLOCK);
		ft_putstr(s);
		reset_color();
	}
	else if (tab->st_mode == 'l')
	{
		ft_putstr(COLOR_LINK);
		ft_putstr(s);
		reset_color();
	}
	else if (tab->st_mode == '-' && tab->permission_user[2] == 'x')
	{
		ft_putstr("\033[0;31m");
		ft_putstr(s);
		reset_color();
	}
	else if (tab->st_mode == '-')
	{
		ft_putstr("\033[-10;97m");
		ft_putstr(s);
		reset_color();
	}
}
