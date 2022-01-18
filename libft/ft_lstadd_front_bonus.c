/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:28:33 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/19 01:42:44 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new_el)
{
	if (!new_el)
		return ;
	new_el->next = *lst;
	*lst = new_el;
}
