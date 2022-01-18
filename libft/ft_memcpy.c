/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 18:38:08 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/10/20 14:34:11 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*to;
	unsigned char	*from;

	if (!dst && !src)
		return (NULL);
	to = (unsigned char *)dst;
	from = (unsigned char *)src;
	while (n != 0)
	{
		--n;
		to[n] = from[n];
	}
	return (dst);
}
