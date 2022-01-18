/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vladislove <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 22:25:47 by vladislov         #+#    #+#             */
/*   Updated: 2021/10/14 00:03:07 by vladislov        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	*allocator(int n, char length[10], int i)
{
	char	*result;
	int		j;

	result = (char *)malloc(sizeof(char) * (i + (n < 0) + 1));
	if (result == NULL)
		return (NULL);
	j = 0;
	if (n < 0)
		result[j++] = '-';
	while (i)
		result[j++] = length[--i];
	result[j] = 0;
	return (result);
}

char	*ft_itoa(int n)
{
	long long	ll;
	char		length[10];
	int			i;

	ll = n;
	i = 0;
	if (ll == 0)
		length[i++] = '0';
	if (ll < 0)
		ll *= -1;
	while (ll)
	{
		length[i++] = ll % 10 + '0';
		ll /= 10;
	}
	return (allocator(n, length, i));
}
