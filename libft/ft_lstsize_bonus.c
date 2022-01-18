/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsize_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:31:40 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/18 22:29:13 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		++count;
	}
	return (count);
}
