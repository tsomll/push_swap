/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   begin_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:41:59 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/19 14:03:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	little_sort(t_stack **a, int len)
{
	int	first;
	int	second;
	int	third;

	while (check_sort2(a, len) != 0)
	{
		first = (*a)->num;
		second = (*a)->next->num;
		third = (*a)->next->next->num;
		if (first > second && second < third && first < third)
			swap(a, "sa\n");
		else if (first < second && second > third && first > third)
			reverse(a, "rra\n");
		else if (first > second && second > third)
			swap(a, "sa\n");
		else if (first > second && second < third && first > third)
			rotate (a, "ra\n");
		else if (first < second && second > third && first < third)
			reverse (a, "rra\n");
	}
}

void	middle_sort(t_stack **a, t_stack **b, int len)
{
	while (stack_size(a) != 3)
	{
		if ((*a)->index <= 2)
			push(a, b, "pb\n");
		else
			rotate(a, "ra\n");
	}
	little_sort(a, len);
	while (stack_size(b) > 0)
		push(b, a, "pa\n");
	if ((*a)->num > (*a)->next->num)
		swap(a, "sa\n");
}

void	big_sort(t_stack **a, t_stack **b)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		exit(1);
	node->flag = 0;
	node->max = 0;
	node->min = 1;
	node->mid = 0;
	init_node(a, node);
	while (check_sort3(a, b))
	{
		if (*b == NULL && node->flag == 0)
			first_b(a, b, node);
		else if (*b == NULL)
			move_b(a, b, node);
		else
			move_a(a, b, node);
	}
	free(node);
}

void	begin_sort(t_stack **a, int len)
{
	t_stack	*b;

	b = NULL;
	if (len == 1)
		exit(0);
	if (len == 2)
		swap(a, "sa\n");
	else if (len == 3)
		little_sort(a, len);
	else if (len > 3 && len < 6)
		middle_sort(a, &b, len);
	else
		big_sort(a, &b);
	deallocate(a);
	deallocate(&b);
}
