/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:21:36 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/08 22:22:14 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

_Bool	checking_flags(const char *arr, t_arg **tab)
{
	if (arr[0] != '.')
		return (1);
	if (is_exist(tab, 'a'))
	{
		if (arr[0] == '.')
			return (1);
		return (0);
	}
	else if (is_exist(tab, 'A'))
	{
		if (!ft_strequ(arr, ".") && !ft_strequ(arr, ".."))
			return (1);
		return (0);
	}
	return (0);
}
