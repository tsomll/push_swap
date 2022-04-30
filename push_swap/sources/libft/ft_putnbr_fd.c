/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:50:27 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/20 18:50:31 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<unistd.h>
#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		src[12];
	int			i;
	int			m;
	long int	n1;

	m = 0;
	if (n == 0)
		write(fd, "0", 1);
	n1 = n;
	if (n < 0)
	{
		n1 *= -1;
		m = 1;
	}
	i = 0;
	while (n1 > 0)
	{
		src[i++] = n1 % 10 + '0';
		n1 /= 10;
	}
	if (m)
		src[i++] = '-';
	while (i > 0)
		write(fd, &src[i-- - 1], 1);
}
