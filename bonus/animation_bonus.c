/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:02:11 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 18:07:01 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	open_door(t_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->heigth)
	{
		j = 0;
		while (j < info->width)
		{
			if (info->map[i][j] == 'E')
				put_xpm_image(j * SCALE, i * SCALE, PUDDLE, info);
			++j;
		}
		++i;
	}
	info->collectibles = -1;
}

static void	dino_animation(t_info *info)
{
	static int	flag;

	if (flag == 1500)
		put_xpm_image(info->x * SCALE, info->y * SCALE, DINO2, info);
	else if (flag == 3000)
		put_xpm_image(info->x * SCALE, info->y * SCALE, DINO3, info);
	else if (flag == 4500)
		put_xpm_image(info->x * SCALE, info->y * SCALE, DINO4, info);
	else if (flag == 6000)
		put_xpm_image(info->x * SCALE, info->y * SCALE, DINO5, info);
	else if (flag == 7500)
		put_xpm_image(info->x * SCALE, info->y * SCALE, DINO6, info);
	else if (flag == 9000)
	{
		put_xpm_image(info->x * SCALE, info->y * SCALE, DINO7, info);
		flag = 0;
	}
	++flag;
}

static void	drop_animation(t_info *info)
{
	static int	flag;
	int			i;
	int			j;

	i = -1;
	while (++i < info->heigth)
	{
		j = -1;
		while (++j < info->width)
		{
			if (info->map[i][j] == 'C')
			{
				if (flag == 3000)
					put_xpm_image(j * SCALE, i * SCALE, DROP1, info);
				else if (flag == 6000)
					put_xpm_image(j * SCALE, i * SCALE, DROP2, info);
				else if (flag == 9000)
					put_xpm_image(j * SCALE, i * SCALE, DROP3, info);
				else if (flag == 12000)
					put_xpm_image(j * SCALE, i * SCALE, DROP2, info);
			}
		}
	}
	if (flag++ == 12000)
		flag = 0;
}

static void	enemy_animation(t_info *info)
{
	static int	flag;
	t_list		*list;
	t_enemy		*enemy;

	list = info->enemies;
	if (flag == 2000 || flag == 4000 || flag == 6000)
	{
		while (list)
		{
			enemy = (t_enemy *)list->content;
			if (flag == 2000)
				put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, ENEMY1, info);
			else if (flag == 4000)
				put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, ENEMY2, info);
			else if (flag == 6000)
				put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, ENEMY3, info);
			list = list->next;
		}
	}
	if (flag++ == 6000)
		flag = 0;
}

int	animation(t_info *info)
{
	dino_animation(info);
	drop_animation(info);
	enemy_animation(info);
	check_positions(info);
	move_enemies(info);
	if (info->collectibles == 0)
		open_door(info);
	return (0);
}
