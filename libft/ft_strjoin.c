/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 18:55:51 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/20 14:51:21 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*result;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size && s1[j])
		result[i++] = s1[j++];
	j = 0;
	while (i < size)
		result[i++] = s2[j++];
	result[i] = 0;
	return (result);
}
