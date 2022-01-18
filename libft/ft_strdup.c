/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 10:05:26 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/10/13 01:21:17 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

unsigned int	ft_strlen(const char *str);

char	*ft_strdup(const char *src)
{
	unsigned int	length;
	unsigned int	i;
	char			*str;

	length = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < length)
	{
		str[i] = src[i];
		++i;
	}
	str[i] = 0;
	return (str);
}
