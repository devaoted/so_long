/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_back_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:34:28 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/19 01:41:16 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_el)
{
	t_list	*temp;

	if (!*lst)
	{
		*lst = new_el;
		return ;
	}
	temp = ft_lstlast(*lst);
	temp->next = new_el;
}
