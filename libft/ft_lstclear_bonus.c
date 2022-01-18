/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:38:52 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/19 01:04:30 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*prev;

	while (*lst != NULL)
	{
		prev = *lst;
		*lst = (*lst)->next;
		(*del)(prev->content);
		free(prev);
	}
}
