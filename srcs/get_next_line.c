/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 20:28:48 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/15 12:38:47 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	concatenation(char **str, char *buff)
{
	char	*temp;

	if (!*str)
	{
		*str = ft_strdup(buff);
	}
	else
	{
		temp = *str;
		*str = ft_strjoin(*str, buff);
		free(temp);
	}
}

static size_t	ft_read(char **str, int fd)
{
	char	*buff;
	int		d;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buff == NULL)
		return (0);
	while (1)
	{
		d = read(fd, buff, BUFFER_SIZE);
		if (d <= 0)
			break ;
		buff[d] = 0;
		concatenation(str, buff);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	free(buff);
	return (!(d < 0 || !*str || !**str));
}

int	get_next_line(int fd, char **res)
{
	static char		*str;
	char			*temp;
	char			*nl;
	unsigned int	nl_pos;

	if (!ft_read(&str, fd))
		return (0);
	temp = str;
	nl = ft_strchr(str, '\n');
	nl_pos = nl - str + 1;
	if (nl)
	{
		*res = ft_substr(str, 0, nl_pos - 1);
		str = ft_substr(str, nl_pos, ft_strlen(str) - nl_pos);
		free(temp);
	}
	else
	{
		*res = str;
		str = NULL;
	}
	return (1);
}
