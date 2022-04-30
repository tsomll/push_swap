/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:34:15 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/13 13:34:21 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>

int	ft_memcmp(const void *src1, const void *src2, size_t n)
{
	const unsigned char	*s1 = (const unsigned char	*) src1;
	const unsigned char	*s2 = (const unsigned char	*) src2;

	if (!n)
		return (0);
	while (n-- > 1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
