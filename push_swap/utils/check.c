/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:42:30 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/16 18:42:32 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_double(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = *a;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->num == tmp2->num)
				error_msg();
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

void	check_sort(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		huge;
	int		less;

	huge = 0;
	less = 0;
	tmp = *a;
	tmp2 = tmp->next;
	while (tmp->next)
	{
		if (tmp->num > tmp2->num)
			huge++;
		else
			less++;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if (huge == 0 && less != 0)
		exit(0);
}

int	check_sort2(t_stack **a, int len)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		huge;
	int		less;

	huge = 0;
	less = 0;
	tmp = *a;
	tmp2 = tmp->next;
	while (tmp->next)
	{
		if (tmp->num > tmp2->num)
			huge++;
		else
			less++;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if (huge == 0 && less != 0)
		if (len == stack_size(a) || len > 2)
			return (0);
	return (1);
}

int	check_sort3(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp2;
	int		huge;
	int		less;

	huge = 0;
	less = 0;
	tmp = *a;
	tmp2 = tmp->next;
	while (tmp->next)
	{
		if (tmp->num > tmp2->num)
			huge++;
		else
			less++;
		tmp = tmp->next;
		tmp2 = tmp2->next;
	}
	if (huge == 0 && less != 0 && (*b) == NULL)
		return (0);
	return (1);
}

void	ft_check(const char *split)
{
	int	i;
	int	count;
	int	minus;

	i = -1;
	count = 0;
	minus = 0;
	while (split[++i])
	{
		if (!((split[i] > 47 && split[i] < 58) || split[i] == 32
				|| (split[i] > 8 && split[i] < 14) || split[i] == 45))
			error_msg();
		if (split[i] > 47 && split[i] < 58)
			count++;
		if (split[i] == 45)
			minus++;
	}
	if (count == 0 || minus > 1)
		error_msg();
}
