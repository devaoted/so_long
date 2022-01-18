/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 01:00:13 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/14 01:23:43 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c);

char	*ft_strrchr(const char *s, int c)
{
	char	*next;
	char	*result;

	next = ft_strchr(s, c);
	if (!next)
		return (0);
	while (*s)
		++s;
	if (c == 0)
		return ((char *)s);
	while (next && *next != *s)
	{
		result = next;
		next = ft_strchr(next + 1, c);
	}
	return (result);
}
