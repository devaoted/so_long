/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 04:28:36 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 18:04:16 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	exit_door(t_info *info)
{
	printf("Congratulations, you won by making %d moves!\n", ++info->moves);
	ft_exit(info);
	exit(0);
}

void	move_four_directions(t_info *info, int y, int x)
{
	char	check;

	check = info->map[y][x];
	if (check == 'E' && info->collectibles == -1)
		exit_door(info);
	if (check == '1' || check == 'E')
		return ;
	else if (check == '0')
	{
		put_xpm_image(info->x * SCALE, info->y * SCALE, SAND, info);
		put_xpm_image(x * SCALE, y * SCALE, DINO1, info);
	}
	else if (check == 'C')
	{
		put_xpm_image(info->x * SCALE, info->y * SCALE, SAND, info);
		put_xpm_image(x * SCALE, y * SCALE, DINO1, info);
		info->map[y][x] = '0';
		--info->collectibles;
	}
	info->y = y;
	info->x = x;
	printf("Moves: %d\n", ++info->moves);
}
