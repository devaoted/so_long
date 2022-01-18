/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:13:17 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/18 22:26:17 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len);

static int	check_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		++set;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*result;
	size_t	size;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	start = 0;
	if (!*s1)
		end = 0;
	else
		end = size - 1;
	while (s1[start] && check_set(set, s1[start]))
		++start;
	while (start < end && check_set(set, s1[end]))
		--end;
	if (end < start)
		result = ft_substr(s1, 0, 0);
	else
		result = ft_substr(s1, start, end - start + 1);
	return (result);
}
