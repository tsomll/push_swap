/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvioleta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 12:50:40 by vvioleta          #+#    #+#             */
/*   Updated: 2021/10/27 12:50:41 by vvioleta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del) (void *))
{
	t_list	*newlst;
	void	*tmp;

	newlst = NULL;
	while (lst != NULL)
	{
		tmp = (*f)(lst->content);
		if (tmp == NULL)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, ft_lstnew(tmp));
		lst = lst->next;
	}
	return (newlst);
}
