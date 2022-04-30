/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:36:16 by vvioleta          #+#    #+#             */
/*   Updated: 2022/03/19 13:23:22 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	msg_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	max_int(long res)
{
	if (res > -2147483649 && res < 2147483648)
		return ((int)res);
	else
		msg_error();
	return (0);
}

int	ft_atoi(const char *str)
{
	int		f;
	long	res;
	int		i;

	f = 1;
	i = 0;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			f = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	res *= f;
	return (max_int(res));
}
