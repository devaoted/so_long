/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:24:33 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/14 01:24:11 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*bits;
	size_t				i;
	unsigned char		a;

	a = c;
	bits = (const unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (bits[i] == a)
		{
			return ((void *)&bits[i]);
		}
		++i;
	}
	return (0);
}
