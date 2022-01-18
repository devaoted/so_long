/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 15:47:25 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 17:50:28 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

static void	game_over(t_info *info)
{
	printf("Game over!\n");
	ft_exit(info);
	exit(0);
}

static void	move_horizontal_enemy(t_info *info, t_enemy *enemy)
{
	if (enemy->flag && info->map[enemy->y][enemy->x + 1] == '0')
	{
		info->map[enemy->y][enemy->x + 1] = 'H';
		info->map[enemy->y][enemy->x] = '0';
		put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, SAND, info);
		put_xpm_image((enemy->x + 1) * SCALE, enemy->y * SCALE, ENEMY1, info);
		++enemy->x;
	}
	else if (enemy->flag)
		enemy->flag = 0;
	else if (!enemy->flag && info->map[enemy->y][enemy->x - 1] == '0')
	{
		info->map[enemy->y][enemy->x - 1] = 'V';
		info->map[enemy->y][enemy->x] = '0';
		put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, SAND, info);
		put_xpm_image((enemy->x - 1) * SCALE, enemy->y * SCALE, ENEMY1, info);
		--enemy->x;
	}
	else
		enemy->flag = 1;
}

static void	move_vertical_enemy(t_info *info, t_enemy *enemy)
{
	if (enemy->flag && info->map[enemy->y + 1][enemy->x] == '0')
	{
		info->map[enemy->y + 1][enemy->x] = 'V';
		info->map[enemy->y][enemy->x] = '0';
		put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, SAND, info);
		put_xpm_image(enemy->x * SCALE, (enemy->y + 1) * SCALE, ENEMY1, info);
		++enemy->y;
	}
	else if (enemy->flag)
		enemy->flag = 0;
	else if (!enemy->flag && info->map[enemy->y - 1][enemy->x] == '0')
	{
		info->map[enemy->y - 1][enemy->x] = 'V';
		info->map[enemy->y][enemy->x] = '0';
		put_xpm_image(enemy->x * SCALE, enemy->y * SCALE, SAND, info);
		put_xpm_image(enemy->x * SCALE, (enemy->y - 1) * SCALE, ENEMY1, info);
		--enemy->y;
	}
	else
		enemy->flag = 1;
}

void	move_enemies(t_info *info)
{
	static int	move_time;
	t_list		*list;
	t_enemy		*enemy;

	++move_time;
	if (move_time != 7000)
		return ;
	list = info->enemies;
	while (list)
	{
		enemy = ((t_enemy *)list->content);
		if (enemy->type == HORIZONTAL)
			move_horizontal_enemy(info, enemy);
		else
			move_vertical_enemy(info, enemy);
		list = list->next;
	}
	move_time = 0;
}

void	check_positions(t_info *info)
{
	t_list	*list;
	t_enemy	*enemy;

	list = info->enemies;
	while (list)
	{
		enemy = (t_enemy *)list->content;
		if (enemy->x == info->x && enemy->y == info->y)
			game_over(info);
		list = list->next;
	}
}
