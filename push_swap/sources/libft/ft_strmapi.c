/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:59:19 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/20 18:59:23 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*src;
	int		j;

	if (s == NULL)
		return (NULL);
	j = 0;
	src = (char *)malloc(ft_strlen(s) + 1);
	if (src == NULL)
		return (NULL);
	while (s[j] != '\0' )
	{
		src[j] = (*f)(j, s[j]);
		j++;
	}
	src[ft_strlen(s)] = '\0';
	return (src);
}
