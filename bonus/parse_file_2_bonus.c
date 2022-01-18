/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file_2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:52:40 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 17:59:15 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

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
	ft_lstclear(&info->enemies, delete_elem);
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

static void	add_enemy(t_info *info, int y, int x)
{
	t_enemy	*enemy;
	t_list	*list;

	enemy = (t_enemy *)malloc(sizeof(t_enemy));
	if (enemy == NULL)
		map_error("Malloc error\n", info);
	if (info->map[y][x] == 'H')
		enemy->type = HORIZONTAL;
	else
		enemy->type = VERTICAL;
	enemy->x = x;
	enemy->y = y;
	enemy->flag = 1;
	list = ft_lstnew(enemy);
	if (list == NULL)
		map_error("Malloc error\n", info);
	ft_lstadd_back(&info->enemies, list);
}

void	check_enemies(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->heigth)
	{
		j = 0;
		while (j < info->width)
		{
			if (info->map[i][j] == 'H' || info->map[i][j] == 'V')
				add_enemy(info, i, j);
			++j;
		}
		++i;
	}
}
