/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:42:54 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/16 18:42:55 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/push_swap.h"

t_stack	*find_min(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *a;
	min = *a;
	while (tmp)
	{
		if (tmp->index < min->index)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*find_max(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *a;
	max = *a;
	while (tmp)
	{
		if (tmp->index > max->index)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	init_node(t_stack **a, t_node *node)
{
	node->min = find_min(a)->index;
	node->max = find_max(a)->index;
	node->mid = node->max / 2 + node->min;
}

int	close_down(t_stack **stack, t_node *node)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = find_last(stack);
	while (tmp->index <= node->mid)
	{
		tmp = tmp->prev;
		i++;
	}
	return (i);
}

int	close_up(t_stack **stack, t_node *node)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp->index <= node->mid)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
