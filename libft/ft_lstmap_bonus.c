/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:45:01 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/19 01:47:04 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*it;

	if (!lst)
		return (NULL);
	new_list = ft_lstnew((*f)(lst->content));
	lst = lst->next;
	if (!new_list)
		return (NULL);
	it = new_list;
	while (lst)
	{
		it->next = ft_lstnew((*f)(lst->content));
		if (it->next == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		lst = lst->next;
		it = it->next;
	}
	return (new_list);
}
