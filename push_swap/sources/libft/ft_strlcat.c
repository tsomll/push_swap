/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:39:01 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/13 13:39:04 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include"libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dest);
	slen = 0;
	while (src[slen] && ((int)(slen + dlen) < (int)size - 1))
	{
		dest[slen + dlen] = src[slen];
		slen++;
	}
	if (dlen < size && size != 0)
		dest[dlen + slen] = '\0';
	while (src[slen])
		slen++;
	if (dlen < size)
		return (dlen + slen);
	return (size + slen);
}
