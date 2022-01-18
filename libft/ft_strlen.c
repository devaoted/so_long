/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:17:23 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/10/20 14:35:18 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != 0)
		++count;
	return (count);
}
