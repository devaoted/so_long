/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:29:34 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/20 17:09:55 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *s, const char *p, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!(*p))
		return ((char *)(s));
	if (len == 0)
		return (0);
	while (s[i])
	{
		j = 0;
		while (p[j] == s[i + j])
		{
			if (p[j + 1] == '\0' && i < len)
				return ((char *)s + i);
			++j;
			if (i + j == len)
				return (0);
		}
		++i;
	}
	return (0);
}
