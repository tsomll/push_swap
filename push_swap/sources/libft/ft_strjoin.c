/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:14:14 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/20 19:14:18 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include "libft.h"
#include "../../includes/push_swap.h"

char	*first_join(char const *s2)
{
	int		i;
	char	*str;
	char	*rez;

	i = -1;
	str = (char *)s2;
	rez = malloc(sizeof(char) * ft_strlen((str) + 1));
	if (!rez)
		exit(2);
	while (str[++i])
		rez[i] = str[i];
	rez[i] = '\0';
	return (rez);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*src;
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (s2 == NULL || s2[0] == '\0')
		error_msg();
	if (s1 == NULL)
		src = first_join(s2);
	else
	{
		src = malloc((ft_strlen((char *) s1) + ft_strlen((char *) s2) + 2));
		if (src == NULL)
			return (NULL);
		while (s1[k] != '\0')
			src[i++] = s1[k++];
		k = 0;
		src[i++] = ' ';
		while (s2[k] != '\0')
			src[i++] = s2[k++];
		src[i] = '\0';
	}
	free((char *)s1);
	return (src);
}
