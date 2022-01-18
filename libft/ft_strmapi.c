/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 00:07:53 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/14 00:18:59 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*result;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	result = ft_strdup(s);
	if (result == NULL)
		return (NULL);
	while (s[i])
	{
		result[i] = (*f)(i, s[i]);
		++i;
	}
	return (result);
}
