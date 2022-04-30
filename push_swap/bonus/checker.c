/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 10:01:54 by                   #+#    #+#             */
/*   Updated: 2022/03/19 14:11:28 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_next_line(char **line)
{
	int		i;
	int		j;
	char	*buf;

	buf = malloc(5);
	i = -1;
	j = read(0, &buf[++i], 1);
	while (j > 0 && buf[i] != '\n' && buf[i] != '\0')
		j = read(0, &buf[++i], 1);
	buf[i] = '\0';
	*line = buf;
	return (j);
}

void	check_command(char *line, t_stack **a, t_stack **b)
{
	if (ft_strncmp("sa", line, 3) == 0)
		swap(a, NULL);
	else if (ft_strncmp("sb", line, 3) == 0)
		swap(b, NULL);
	else if (ft_strncmp("pa", line, 3) == 0)
		push(b, a, NULL);
	else if (ft_strncmp("pb", line, 3) == 0)
		push(a, b, NULL);
	else if (ft_strncmp("ra", line, 3) == 0)
		rotate(a, NULL);
	else if (ft_strncmp("rb", line, 3) == 0)
		rotate(b, NULL);
	else if (ft_strncmp("ss", line, 3) == 0)
		same2(a, b, "ss\n");
	else if (ft_strncmp("rra", line, 4) == 0)
		reverse(a, NULL);
	else if (ft_strncmp("rrb", line, 4) == 0)
		reverse(b, NULL);
	else if (ft_strncmp("rr", line, 3) == 0)
		same2(a, b, "rr\n");
	else if (ft_strncmp("rrr", line, 4) == 0)
		same2(a, b, "rrr\n");
	else
		error_msg();
}

void	begin_check(t_stack **a, int len)
{
	char	*line;
	t_stack	*b;

	b = NULL;
	while (get_next_line(&line))
	{
		check_command(line, a, &b);
		free(line);
	}
	if (len < 6)
	{
		if (check_sort2(a, len) == 0 || len == 1)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	else
	{
		if (check_sort3(a, &b) == 0)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
	free(line);
}

void	prepare_to_check(char **split, int len)
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
	while (++i < len)
		init_stack(arg[i], &a);
	check_double(&a);
	arg = find_index(arg, len);
	set_index(&a, arg, len);
	begin_check(&a, len);
	while (i-- > 0)
		free(split[i]);
	free (split);
	free(arg);
	deallocate(&a);
}

int	main(int argc, char **argv)
{
	char	*line;
	char	**split;
	int		i;

	if (argc == 1)
		no_arg();
	i = 0;
	while (argv[++i])
		ft_check(argv[i]);
	i = 0;
	while (argv[++i])
		line = ft_strjoin(line, argv[i]);
	split = ft_split(line, ' ');
	i = 1;
	while (split[i])
		i++;
	prepare_to_check(split, i);
}
