/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstnew_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 13:31:12 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/18 22:29:20 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_el;

	new_el = (t_list *)malloc(sizeof(t_list));
	if (new_el == NULL)
		return (new_el);
	new_el->next = NULL;
	new_el->content = content;
	return (new_el);
}
