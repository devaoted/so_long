/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 05:59:53 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 07:53:26 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_is_surrounded_by_walls(t_info *info);
void	map_error(const char *msg, t_info *info);

static int	get_height(char *filename)
{
	int		height;
	char	*line;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\n");
		perror("Open error");
		exit(1);
	}
	height = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		++height;
		free(line);
	}
	close(fd);
	return (height);
}

static void	read_file(char *filename, t_info *info)
{
	int	heigth;
	int	fd;

	info->heigth = get_height(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		printf("Error!\n");
		perror("Open error");
		exit(1);
	}
	info->map = (char **)malloc(sizeof(char *) * (info->heigth + 1));
	if (info->map == NULL)
	{
		perror("Malloc error");
		exit(1);
	}
	heigth = 0;
	while (heigth < info->heigth)
	{
		get_next_line(fd, &info->map[heigth]);
		++heigth;
	}
	info->map[heigth] = 0;
	close(fd);
}

static void	check_is_rectangular(t_info *info)
{
	int	i;

	i = 0;
	info->width = ft_strlen(info->map[0]);
	while (i < info->heigth)
		if ((int)ft_strlen(info->map[i++]) != info->width)
			map_error("Map error: the map is not a recangular!\n", info);
}

static void	check_characters(t_info *info, int *player, int *exit, int *unknown)
{
	int	i;
	int	j;

	i = 0;
	*unknown = 0;
	*player = 0;
	*exit = 0;
	info->collectibles = 0;
	while (i < info->heigth)
	{
		j = 0;
		while (j < info->width)
		{
			if (info->map[i][j] == 'E')
				++*exit;
			else if (info->map[i][j] == 'P')
				++(*player);
			else if (info->map[i][j] == 'C')
				++info->collectibles;
			else if (info->map[i][j] != '1' && info->map[i][j] != '0')
				*unknown = 1;
			++j;
		}
		++i;
	}
}

void	parse_file(char *filename, t_info *info)
{
	int	players;
	int	exits;
	int	unknown;

	read_file(filename, info);
	check_is_rectangular(info);
	check_characters(info, &players, &exits, &unknown);
	if (players != 1)
		map_error("Map error: the player must be the only one!\n", info);
	if (exits == 0)
		map_error("Map error: no exits!\n", info);
	if (info->collectibles == 0)
		map_error("Map error: no collectibles!\n", info);
	if (unknown)
		map_error("Map error: unknown character!\n", info);
	check_is_surrounded_by_walls(info);
}
