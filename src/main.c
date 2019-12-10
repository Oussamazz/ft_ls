/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 19:22:57 by oelazzou          #+#    #+#             */
/*   Updated: 2019/12/10 16:04:26 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		main(int ac, char **av)
{
	t_arg	*args;
	char	**arr;
	char	**errors;
	t_file	*files;
	t_file	*files_dir;

	args = stock_flags(ac, av);
	arr = directories(ac, &args);
	errors = get_errors(arr, args->no_paths, &args);
	ft_print_words_tables(errors);
	stock_reg_files(arr, &files, &args);
	stock_dirs(arr, &files_dir, &args);
	PATH_COUNT_CHECK((args->no_paths));
	if (is_exist(&args, 'R') && !is_exist(&args, 'd'))
		ls_r(arr, &args);
	free_tree(files);
	free_tree(files_dir);
	free_args_errors(arr, errors, args->no_paths);
	free_args(args, ac);
	return (0);
}
