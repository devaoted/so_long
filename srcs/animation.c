/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 06:02:11 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 18:06:21 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

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

int	animation(t_info *info)
{
	if (info->collectibles == 0)
		open_door(info);
	return (0);
}
