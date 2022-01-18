/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 13:19:15 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 18:06:06 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	put_xpm_image(int x, int y, const char *file, t_info *info)
{
	int	w;
	int	h;

	info->img = mlx_xpm_file_to_image(info->mlx, (char *)file, &w, &h);
	mlx_put_image_to_window(info->mlx, info->win, info->img, x, y);
}

static void	put_image(int x, int y, char c, t_info *info)
{
	if (c == '1')
	{
		put_xpm_image(x, y, WALL, info);
	}
	else if (c == '0')
	{
		put_xpm_image(x, y, SAND, info);
	}
	else if (c == 'C')
	{
		put_xpm_image(x, y, DROP1, info);
	}
	else if (c == 'P')
	{
		info->x = x / SCALE;
		info->y = y / SCALE;
		put_xpm_image(x, y, SAND, info);
		put_xpm_image(x, y, DINO1, info);
		info->map[info->y][info->x] = '0';
	}
	else if (c == 'E')
	{
		put_xpm_image(x, y, DRIED_PUDDLE, info);
	}
}

void	draw_map(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->heigth)
	{
		j = 0;
		while (j < info->width)
		{
			put_image(j * SCALE, i * SCALE, info->map[i][j], info);
			++j;
		}
		++i;
	}
}
