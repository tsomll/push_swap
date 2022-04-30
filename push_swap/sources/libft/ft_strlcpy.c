/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 10:12:28 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/06 10:12:39 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	int	k;
	int	i;

	k = 0;
	i = 0;
	if ((int)size == 0)
		return (ft_strlen(src));
	while (src[k] != '\0')
		k++;
	while (i < k && i < (int)size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return ((size_t)k);
}
