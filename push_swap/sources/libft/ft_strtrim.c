/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:30:23 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/20 19:30:28 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<stddef.h>
#include"libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int	start;
	int	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr((char *)set, s1[start]))
	{
		start++;
	}
	end = ft_strlen((char *)s1);
	while (ft_strchr((char *)set, (int)s1[end - 1]) && end > 0)
		end--;
	if (start >= end)
		return (ft_strdup("\0"));
	else
		return (ft_substr(s1, (unsigned int)start, end - start));
}
