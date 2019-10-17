/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_exist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 22:00:01 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/08 22:02:23 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		is_exist(t_arg **tab, char flag)
{
	int		i;
	t_arg	*n;

	n = *tab;
	i = 0;
	while (n[i].flag != NULL)
	{
		if (ft_is_there(n[i].flag, flag))
			return (1);
		i++;
	}
	return (0);
}
