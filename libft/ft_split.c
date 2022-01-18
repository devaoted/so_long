/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 21:06:56 by pmeredyt          #+#    #+#             */
/*   Updated: 2021/10/20 14:51:40 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

static size_t	ft_count_words(const char *str, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i] && str[i] != c)
		{
			++j;
			++i;
		}
		if (j > 0)
			++count;
		while (str[i] && str[i] == c)
			++i;
	}
	return (count);
}

static int	free_elem(char **result, int m)
{
	int	i;

	i = 0;
	while (i < m)
		free(result[i++]);
	return (0);
}

static int	ft_allocator(char **result, const char *str, char c)
{
	int	i;
	int	j;
	int	m;

	i = 0;
	m = 0;
	while (str[i] != 0)
	{
		j = 0;
		while (str[i + j] && str[i + j] != c)
			++j;
		if (j > 0)
		{
			result[m] = (char *)malloc(sizeof(char) * (j + 1));
			if (result[m] == NULL)
				return (free_elem(result, m));
			ft_strlcpy(result[m++], str + i, j + 1);
			i += j;
		}
		while (str[i] && str[i] == c)
			++i;
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	size_t	k;
	char	**result;

	if (!s)
		return (NULL);
	k = ft_count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (k + 1));
	if (result == NULL)
		return (NULL);
	if (!ft_allocator(result, s, c))
	{
		free(result);
		result = NULL;
		return (NULL);
	}
	result[k] = 0;
	return (result);
}
