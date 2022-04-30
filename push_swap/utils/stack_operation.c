/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:41:38 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/16 18:41:42 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_stack **stack, char *text)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	tmp2 = (*stack)->next;
	tmp->next = tmp2->next;
	tmp2->prev = NULL;
	tmp->prev = tmp2;
	tmp2->next = tmp;
	if (tmp2->next)
		tmp2->next->prev = tmp;
	*stack = tmp2;
	if (text)
		write(1, text, 3);
}

void	push(t_stack **stack, t_stack **stack2, char *text)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*tmp3;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	tmp2 = *stack2;
	tmp3 = (*stack)->next;
	if (tmp->next)
		tmp->next->prev = NULL;
	tmp->next = tmp2;
	if (tmp2)
		tmp2->prev = tmp;
	*stack2 = tmp;
	*stack = tmp3;
	if (text)
		write(1, text, 3);
}

void	rotate(t_stack **stack, char *text)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	t_stack	*tmp3;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	tmp2 = find_last(stack);
	tmp3 = (*stack)->next;
	tmp->next->prev = NULL;
	tmp2->next = tmp;
	tmp->prev = tmp2;
	tmp->next = NULL;
	*stack = tmp3;
	if (text)
		write(1, text, 3);
}

void	reverse(t_stack **stack, char *text)
{
	t_stack	*tmp;
	t_stack	*lst;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	lst = *stack;
	tmp = find_last(stack);
	while ((*stack)->next->next)
		*stack = (*stack)->next;
	tmp->next = lst;
	lst->prev = tmp;
	tmp->prev = 0;
	(*stack)->next = 0;
	*stack = tmp;
	if (text)
		write(1, text, 4);
}

void	same(t_stack **stack, t_stack **stack2, char *text)
{
	if ((*stack == NULL && (*stack)->next == NULL)
		&& (*stack2 == NULL && (*stack2)->next == NULL))
		return ;
	if (!ft_strncmp(text, "ss\n", 3))
	{
		swap(stack, NULL);
		swap(stack2, text);
	}
	if (!ft_strncmp(text, "rr\n", 3))
	{
		rotate(stack, NULL);
		rotate(stack2, text);
	}
	if (!ft_strncmp(text, "rrr\n", 4))
	{
		reverse(stack, NULL);
		reverse(stack2, text);
	}
}
