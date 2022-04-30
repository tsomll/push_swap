/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:04:53 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/20 19:04:58 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long int n)
{
	long int	n1;
	int			l;

	n1 = n;
	l = 0;
	if (n1 < 0)
		n1 = n1 * (-1);
	while (n1 != 0)
	{
		n1 = n1 / 10;
		l++;
	}
	if (n < 0)
		l++;
	return (l);
}

char	*ft_itoa(int n)
{
	char	*src;
	int		i;
	int		l;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	l = ft_len(n);
	i = 0;
	src = (char *)malloc(l + 1);
	if (l <= 0 || src == NULL)
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		src[i] = 45;
	}
	while (n != 0)
	{
		src[l - 1 - i++] = n % 10 + '0';
		n = n / 10;
	}
	src[l] = '\0';
	return (src);
}
