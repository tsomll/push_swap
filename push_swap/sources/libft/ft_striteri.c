/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 13:07:39 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/26 13:07:45 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include"libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	l;
	unsigned int	i;

	if (s == NULL)
		return ;
	l = (unsigned int)ft_strlen((char *)s);
	i = -1;
	while (++i < l)
		(*f)(i, (char *)s + i);
}
