/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_to_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:43:14 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/19 14:00:59 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	prepare_to_sort(char **split, int len)
{
	t_stack	*a;
	int		i;
	int		*arg;

	i = -1;
	a = NULL;
	arg = malloc(sizeof(int) * len + 1);
	while (split[++i])
		arg[i] = ft_atoi(split[i]);
	i = -1;
	while (++i <= len)
		free(split[i]);
	free(split);
	i = -1;
	while (++i < len)
		init_stack(arg[i], &a);
	check_double(&a);
	check_sort(&a);
	arg = find_index(arg, len);
	set_index(&a, arg, len);
	free(arg);
	begin_sort(&a, len);
}
