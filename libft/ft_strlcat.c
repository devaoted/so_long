/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 21:49:56 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/20 17:05:44 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_min(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			dstsize;

	i = ft_strlen(dest);
	dstsize = i;
	j = 0;
	if (size < i)
		return (size + ft_strlen(src));
	if (!src || !dest)
		return (ft_strlen(dest) + ft_strlen(src));
	while (size != 0 && i < size - 1 && src[j])
	{
		dest[i] = src[j];
		++i;
		++j;
	}
	dest[i] = '\0';
	while (src[j])
		++j;
	return (ft_min(dstsize, size) + ft_strlen(src));
}
