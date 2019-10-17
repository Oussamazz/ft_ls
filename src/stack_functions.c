/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oelazzou <oelazzou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 12:04:10 by oelazzou          #+#    #+#             */
/*   Updated: 2019/10/17 15:04:25 by oelazzou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void		in_order(t_file *root)
{
	t_file		*current;
	t_stack		*s;
	bool		done;

	done = 0;
	current = root;
	s = NULL;
	while (!done)
	{
		if (current != NULL)
		{
			push_stack(&s, current);
			current = current->left;
		}
		else
		{
			if (is_empty(s) == 0)
			{
				current = pop_stack(&s);
				current = current->right;
			}
			else
				done = 1;
		}
	}
}

void		reverse_order(t_file *root)
{
	t_file		*current;
	t_stack		*s;
	bool		done;

	done = 0;
	current = root;
	s = NULL;
	while (!done)
	{
		if (current != NULL)
		{
			push_stack(&s, current);
			current = current->right;
		}
		else
		{
			if (is_empty(s) == 0)
			{
				current = pop_stack(&s);
				current = current->left;
			}
			else
				done = 1;
		}
	}
}

void		push_stack(t_stack **head, t_file *files)
{
	t_stack	*nodes;

	if (!(nodes = (t_stack*)ft_memalloc(sizeof(t_stack))))
		return ;
	nodes->files = files;
	nodes->next = (*head);
	(*head) = nodes;
}

bool		is_empty(t_stack *head)
{
	return (head == NULL) ? 1 : 0;
}

t_file		*pop_stack(t_stack **head)
{
	t_stack	*top;
	t_file	*res;

	if (is_empty(*head))
		return (NULL);
	else
	{
		top = *head;
		res = top->files;
		ft_putendl(res->file_name);
		*head = top->next;
		free(top);
		return (res);
	}
}
