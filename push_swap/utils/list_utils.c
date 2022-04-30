/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:42:43 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/16 18:42:44 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*find_index(int	*arg, int len)
{
	int	swap;
	int	i;

	i = 0;
	while (++i != len)
	{
		if (arg[i] < arg[i - 1])
		{
			swap = arg[i];
			arg[i] = arg[i - 1];
			arg[i - 1] = swap;
			i = 0;
		}
	}
	return (arg);
}

t_stack	*find_last(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	set_index(t_stack **a, int *arg, int len)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	while (tmp)
	{
		i = -1;
		while (++i < len)
		{
			if (arg[i] == tmp->num)
			{
				tmp->index = i + 1;
				tmp->flag = 0;
			}
		}
		tmp = tmp->next;
	}
}

int	stack_size(t_stack **a)
{
	int		size;
	t_stack	*tmp;

	tmp = *a;
	size = 0;
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

void	init_stack(int arg, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*curr;

	tmp = malloc(sizeof(t_stack));
	if (!tmp)
		error_msg();
	tmp->num = arg;
	tmp->prev = NULL;
	tmp->next = NULL;
	if (!*a)
	{
		*a = tmp;
		return ;
	}
	curr = *a;
	while (curr->next)
		curr = curr->next;
	curr->next = tmp;
	tmp->prev = curr;
}
