/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 01:36:52 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/19 00:55:47 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	free(lst);
}
