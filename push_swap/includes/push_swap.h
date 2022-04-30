/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:43:33 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/16 18:43:35 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../sources/libft/libft.h"

typedef struct s_node
{
	int	min;
	int	max;
	int	mid;
	int	flag;
}	t_node;

typedef struct s_stack
{
	int				num;
	int				index;
	int				flag;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void	no_arg(void);
void	error_msg(void);
void	check_sort(t_stack **a);
void	check_double(t_stack **a);
void	change_node(t_node *node);
void	deallocate(t_stack **stack);
void	ft_check(const char *split);
void	begin_sort(t_stack **a, int len);
void	init_stack(int arg, t_stack **a);
void	swap(t_stack **stack, char *text);
void	rotate(t_stack **stack, char *text);
void	init_node(t_stack **a, t_node *node);
void	reverse(t_stack **stack, char *text);
void	prepare_to_sort(char **split, int len);
void	set_index(t_stack **a, int *arg, int len);
void	move_a(t_stack **a, t_stack **b, t_node *node);
void	move_b(t_stack **a, t_stack **b, t_node *node);
void	first_b(t_stack **a, t_stack **b, t_node *node);
void	push(t_stack **stack, t_stack **stack2, char *text);
void	same(t_stack **stack, t_stack **stack2, char *text);
void	check_min_b(t_stack **a, t_stack **b, t_node *node);
void	check_min_a(t_stack **a, t_stack **b, t_node *node);
void	same2(t_stack **stack, t_stack **stack2, char *text);

int		stack_size(t_stack **a);
int		*find_index(int	*arg, int len);
int		check_sort2(t_stack **a, int len);
int		check_sort3(t_stack **a, t_stack **b);
int		close_up(t_stack **stack, t_node *node);
int		close_down(t_stack **stack, t_node *node);

t_stack	*find_last(t_stack **stack);
t_stack	*find_max(t_stack **a);

#endif
