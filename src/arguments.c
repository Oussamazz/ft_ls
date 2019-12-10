/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:52:14 by oelazzou          #+#    #+#             */
/*   Updated: 2019/12/10 16:13:07 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_arg		*stock_flags(int ac, char **av)
{
	int		i;
	int		c;
	t_arg	*tab;

	tab = NULL;
	if (!(tab = (t_arg*)ft_memalloc(sizeof(t_arg) * (ac))))
		return (NULL);
	i = -1;
	c = 1;
	while (++i < ac - 1)
	{
		if (av[i + 1][0] == '-' && (!ft_strequ(av[i + 1], "-")) &&
		(!ft_strequ(av[i + 1], "--")) && flag_checker(&av[i + 1][1]) &&
			c == 1)
			tab[i].flag = ft_strdup(&av[i + 1][1]);
		else if (ft_strequ(av[i + 1], "--"))
			tab[i].name = ft_strdup(".");
		else
		{
			tab[i].name = ft_strdup(av[i + 1]);
			tab[0].no_paths += 1;
			c = 0;
		}
	}
	return (tab);
}

char		**directories(int ac, t_arg **args)
{
	char	**arr;
	t_arg	*tab;
	int		i;
	int		j;

	arr = NULL;
	tab = *args;
	if (tab->no_paths == 0)
		return (alloc_current(arr));
	if (!(arr = (char**)ft_memalloc(sizeof(char*) * (tab)->no_paths + 1)))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ac - 1)
	{
		if (tab[i].name)
		{
			arr[j] = ft_strdup(tab[i].name);
			j++;
		}
	}
	arr[j] = (NULL);
	return (sort_directories(arr, tab->no_paths));
}

char		**alloc_current(char **arr)
{
	if (!(arr = (char**)ft_memalloc(sizeof(char*) * 2)))
		return (NULL);
	arr[0] = ft_strdup(".");
	arr[1] = NULL;
	return (arr);
}

bool		flag_checker(char *str)
{
	int		i;
	char	*arr;

	arr = ft_strdup("aAltrRsgdG1");
	if (str != NULL)
	{
		i = 0;
		while (str[i] != '\0')
		{
			if (!ft_is_there(arr, str[i]))
			{
				ft_putstr_fd("ls: illegal option -- ", 2);
				ft_putchar_fd(str[i], 2);
				ft_putstr_fd("\nusage: ls [-aAltrRsgdG1] [file ...]\n", 2);
				exit(1);
			}
			i++;
		}
		ft_strdel(&arr);
		return (1);
	}
	exit(1);
}
