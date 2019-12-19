/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysarsar <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:18:38 by ysarsar          #+#    #+#             */
/*   Updated: 2019/12/19 22:33:26 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	insert(t_file **node, const char *data, time_t heure, t_arg **tab)
{
	t_file *tmp;

	tmp = NULL;
	if (!(*node))
	{
		tmp = (t_file*)ft_memalloc(sizeof(t_file));
		tmp->file_name = ft_strdup(data);
		tmp->mtime = heure;
		tmp->left = NULL;
		tmp->right = NULL;
		*node = tmp;
		return ;
	}
	if (is_exist(tab, 't'))
		insert_tflag(node, data, heure, tab);
	else
	{
		if (ft_strcmp(data, (*node)->file_name) < 0)
			insert(&(*node)->left, data, heure, tab);
		else if (ft_strcmp(data, (*node)->file_name) >= 0)
			insert(&(*node)->right, data, heure, tab);
	}
}

void	insert_tflag(t_file **node, const char *data, time_t heure, t_arg **tab)
{
	if (heure > (*node)->mtime)
		insert(&(*node)->left, data, heure, tab);
	else if (heure < (*node)->mtime)
		insert(&(*node)->right, data, heure, tab);
	else
	{
		if (ft_strcmp(data, (*node)->file_name) < 0)
			insert(&(*node)->left, data, heure, tab);
		else if (ft_strcmp(data, (*node)->file_name) >= 0)
			insert(&(*node)->right, data, heure, tab);
	}
}
