/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 09:09:39 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/16 11:58:35 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char	*error(const char *str, t_arg **args)
{
	if ((*args)->no_dirs > 1)
		print_four_strings((char*)str, ":\n", "", "");
	ft_putstr("ft_ls: ");
	perror(str);
	return (NULL);
}
