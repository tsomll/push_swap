/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:38:20 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/13 13:38:21 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stddef.h>
#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int				k;
	unsigned long	i;

	k = 0;
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		k = 0;
		while (haystack[i] == needle[k] && haystack[i] && i < len)
		{
			i++;
			k++;
		}
		if (!needle[k])
			return ((char *)&haystack[i - k]);
		i = (i - k) + 1;
	}
	return (NULL);
}
