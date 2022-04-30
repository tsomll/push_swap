/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:17:24 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/14 14:17:25 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dst1;
	char	*src1;

	if (dst == NULL && src == NULL)
		return (NULL);
	dst1 = (char *)dst;
	src1 = (char *)src;
	while (n-- > 0)
		*dst1++ = *src1++;
	return (dst);
}
