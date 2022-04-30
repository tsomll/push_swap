/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 14:22:33 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/14 14:22:35 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		size;

	size = ft_strlen((char *)s1);
	s2 = (char *)malloc(size + 1);
	if (s2 == NULL)
		return (NULL);
	s2[size] = '\0';
	while (size-- > 0)
		s2[size] = s1[size];
	return (s2);
}
