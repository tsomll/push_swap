/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:39:22 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/13 13:39:26 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include"libft.h"

char	*ft_strrchr(const char *s, int n)
{
	int		i;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	if (n == '\0')
		return ((char *)s + ft_strlen(s));
	while (s[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (s2[i] == n)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
