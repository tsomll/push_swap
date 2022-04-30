/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:31:25 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/20 19:31:29 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*src;
	char	*s1;
	int		l1;

	l1 = 0;
	i = 0;
	if (s == NULL || len == '0')
		return (NULL);
	if ((int)start >= (int)ft_strlen(s))
	{
		return (ft_strdup("\0"));
	}
	while (s[start + l1] && l1 < (int)len)
		l1++;
	src = (char *)malloc(l1 + 1);
	s1 = (char *)(s + start);
	if (src == NULL)
		return (NULL);
	while (i < l1)
		src[i++] = *s1++;
	src[i] = '\0';
	return (src);
}
