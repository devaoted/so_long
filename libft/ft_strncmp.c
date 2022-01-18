/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 02:10:30 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/20 17:06:01 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	size_t				i;
	const unsigned char	*c1;
	const unsigned char	*c2;

	c1 = (const unsigned char *)s1;
	c2 = (const unsigned char *)s2;
	i = 0;
	if (len == 0)
		return (0);
	while (c1[i] == c2[i] && i + 1 < len)
	{
		if (c1[i] == 0 && c2[i] == 0)
			break ;
		++i;
	}
	return (c1[i] - c2[i]);
}
