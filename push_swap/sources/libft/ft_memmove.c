/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:07:32 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/14 14:07:33 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dst1;
	char	*src1;

	if (src < dst)
	{
		dst1 = (char *)dst + len - 1;
		src1 = (char *)src + len - 1;
		while (len-- > 0)
			*dst1-- = *src1--;
	}
	if (src > dst)
	{
		src1 = (char *)src;
		dst1 = (char *)dst;
		while (len-- > 0)
			*dst1++ = *src1++;
	}
	return (dst);
}
