/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:42:11 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/16 18:42:13 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	first_b(t_stack **a, t_stack **b, t_node *node)
{
	int	len;
	int	i;

	len = stack_size(a);
	i = -1;
	while (++i < len)
	{
		if ((*a)->index <= node->mid)
			push(a, b, "pb\n");
		else
		{
			if (stack_size(b) > 1 && (*b)->index < (node->mid / 2))
				same(a, b, "rr\n");
			else
				rotate(a, "ra\n");
		}
	}
	change_node(node);
}

void	change_node(t_node *node)
{
	node->max = node->mid;
	node->mid = (node->max - node->min) / 2 + node->min;
	node->flag++;
}

void	move_b_check(t_stack **a, t_stack **b, t_node *node, int max_flag)
{
	while (max_flag == (*a)->flag)
	{
		if ((*a)->index == node->min)
		{
			(*a)->flag = -1;
			rotate(a, "ra\n");
			node->min++;
			check_min_b(a, b, node);
		}
		else
		{
			push(a, b, "pb\n");
			check_min_b(a, b, node);
		}
	}
}

void	move_a(t_stack **a, t_stack **b, t_node *node)
{
	int	len;
	int	i;

	len = stack_size(b);
	i = -1;
	while (++i < len)
	{
		if ((*b)->index == node->min && stack_size(b) > 0)
			check_min_b(a, b, node);
		if (stack_size(b) > 0 && (*b)->index >= node->mid)
		{
			push(b, a, "pa\n");
			(*a)->flag = node->flag;
			check_min_b(a, b, node);
		}
		else if (stack_size(b) > 1 && (*b)->index < node->mid)
		{
			rotate(b, "rb\n");
			check_min_b(a, b, node);
		}
		if (*b == NULL)
			break ;
	}
	change_node(node);
}

void	move_b(t_stack **a, t_stack **b, t_node *node)
{
	int	max_flag;

	max_flag = (*a)->flag;
	if ((*a)->flag != 0)
		move_b_check(a, b, node, max_flag);
	else if ((*a)->flag == 0)
		while ((*a)->flag != -1)
			move_b_check(a, b, node, max_flag);
	if ((*b) != NULL)
	{
		node->max = find_max(b)->index;
		node->mid = (node->max - node->min) / 2 + node->min;
	}
}

//for (t_stack *tmp = *a; tmp != NULL; tmp = tmp->next)
//printf("A: %d\n", tmp->index);
//printf("=============================\n");
//for (t_stack *tmp = *b; tmp != NULL; tmp = tmp->next)
//printf("B: %d\n", tmp->index);
