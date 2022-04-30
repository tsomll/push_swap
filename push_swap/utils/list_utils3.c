/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:43:04 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/19 10:14:13 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_min_b(t_stack **a, t_stack **b, t_node *node)
{
	if ((*a)->index == node->min)
		check_min_a(a, b, node);
	else if (stack_size(b) > 0 && (*b)->index == node->min)
		check_min_a(a, b, node);
	else if ((*a)->next->index == node->min && stack_size(b) > 1
		&& (*b)->next->index == node->min)
		check_min_a(a, b, node);
	else if ((*a)->next->index == node->min)
	{
		swap(a, "sa\n");
		(*a)->flag = -1;
		rotate(a, "ra\n");
		node->min++;
		check_min_b(a, b, node);
	}
	else if (stack_size(b) > 2 && find_last(b)->index == node->min)
	{
		reverse(b, "rrb\n");
		push(b, a, "pa\n");
		(*a)->flag = -1;
		rotate(a, "ra\n");
		node->min++;
		check_min_b(a, b, node);
	}
}

void	check_min_a(t_stack **a, t_stack **b, t_node *node)
{
	if ((*a)->index == node->min)
	{
		rotate(a, "ra\n");
		node->min++;
		check_min_b(a, b, node);
	}
	else if (stack_size(b) > 0 && (*b)->index == node->min)
	{
		(*b)->flag = -1;
		push(b, a, "pa\n");
		rotate(a, "ra\n");
		node->min++;
		check_min_b(a, b, node);
	}
	else if ((*a)->next->index == node->min
		&& (*b)->next->index == node->min + 1)
	{
		same(a, b, "ss\n");
		(*a)->flag = -1;
		rotate(a, "ra\n");
		node->min++;
		check_min_b(a, b, node);
	}
}

void	same2(t_stack **stack, t_stack **stack2, char *text)
{
	if ((*stack == NULL && (*stack)->next == NULL)
		&& (*stack2 == NULL && (*stack2)->next == NULL))
		return ;
	if (!ft_strncmp(text, "ss\n", 3))
	{
		swap(stack, NULL);
		swap(stack2, NULL);
	}
	if (!ft_strncmp(text, "rr\n", 3))
	{
		rotate(stack, NULL);
		rotate(stack2, NULL);
	}
	if (!ft_strncmp(text, "rrr\n", 4))
	{
		reverse(stack, NULL);
		reverse(stack2, NULL);
	}
}

void	deallocate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *stack;
	while (tmp)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
	}
	stack = NULL;
}
