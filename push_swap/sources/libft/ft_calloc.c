/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:37 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/13 13:38:38 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<stddef.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*arr;
	int		i;

	arr = (char *)malloc(count * size);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < (int)(count * size))
		arr[i++] = '\0';
	return ((void *)arr);
}
