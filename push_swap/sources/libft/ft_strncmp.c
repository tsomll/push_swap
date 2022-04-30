/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 13:37:22 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/13 13:37:27 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdlib.h>
#include<stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if ((int)n == 0)
		return (0);
	while ((unsigned char)(*s1) == (unsigned char )(*s2) && \
	n > 1 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char )*s1 - (unsigned char)*s2);
}
