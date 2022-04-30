/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 18:54:30 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/20 18:54:35 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sum(char const *s, char c)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (s[i] != '\0')
	{
		if (i == 0 && s[i] != c)
			sum++;
		else if (s[i] != c && s[i - 1] == c)
			sum++;
		i++;
	}
	return (sum);
}

int	check_res(char **res)
{
	if (res == NULL )
		exit(1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		k;
	int		wc;

	if (s == NULL)
		return (NULL);
	i = -1;
	wc = 0;
	res = (char **)malloc((ft_sum(s, c) + 1) * sizeof(char *));
	check_res(res);
	while (s[++i])
	{
		if ((s[i] != c && i == 0) || (s[i] != c && s[i - 1] == c))
		{
			k = 0;
			while (s[i + k] && s[i + k] != c)
				k++;
			res[wc++] = ft_substr(s, i, k);
			i = i + k - 1;
		}
	}
	res[wc] = NULL;
	free((char *)s);
	return (res);
}
