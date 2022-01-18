/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:32:57 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/18 22:26:23 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
