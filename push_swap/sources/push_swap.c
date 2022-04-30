/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 18:43:25 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/16 18:43:27 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	prepare_to_sort(split, i);
}
