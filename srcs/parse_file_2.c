/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:52:40 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 07:50:03 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	map_error(const char *msg, t_info *info)
{
	int	i;

	i = 0;
	while (info->map[i])
	{
		free(info->map[i]);
		++i;
	}
	free(info->map);
	printf("Error!\n");
	printf("%s", msg);
	exit(1);
}

static void	check_obstacles(char *line, t_info *info)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			map_error("Map error: the map is not surrounded by walls!\n", info);
		++i;
	}
}

void	check_is_surrounded_by_walls(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->heigth)
	{
		if (i == 0 || i == info->heigth - 1)
			check_obstacles(info->map[i], info);
		else if (info->map[i][0] != '1' || info->map[i][info->width - 1] != '1')
			map_error("Map error: the map is not surrounded by walls!\n", info);
		++i;
	}
}
