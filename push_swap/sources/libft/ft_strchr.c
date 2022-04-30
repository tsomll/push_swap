/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 14:29:57 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/18 14:30:00 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include "libft.h"

char	*ft_strchr(const char *src, int n)
{
	char	*s2;

	s2 = (char *)src;
	if (n == '\0')
		return ((char *)src + ft_strlen(src));
	while (*s2 != '\0' && *s2 != n)
		s2++;
	if (*s2 == '\0')
		return (NULL);
	return (s2);
}
