/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 07:34:06 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 18:01:41 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	delete_elem(void *content)
{
	t_enemy	*enemy;

	enemy = (t_enemy *) content;
	free(enemy);
}

int	ft_exit(t_info *vars)
{
	int	i;

	i = 0;
	while (vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	ft_lstclear(&vars->enemies, delete_elem);
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	key_hook(int keycode, t_info *vars)
{
	if (keycode == KEYRIGHT || keycode == KEYD)
		move_four_directions(vars, vars->y, vars->x + 1);
	else if (keycode == KEYLEFT || keycode == KEYA)
		move_four_directions(vars, vars->y, vars->x - 1);
	else if (keycode == KEYUP || keycode == KEYW)
		move_four_directions(vars, vars->y - 1, vars->x);
	else if (keycode == KEYDOWN || keycode == KEYS)
		move_four_directions(vars, vars->y + 1, vars->x);
	else if (keycode == 53)
		ft_exit(vars);
	return (0);
}

static void	init_info(t_info *info)
{
	info->mlx = mlx_init();
	info->collectibles = 0;
	info->heigth = 0;
	info->width = 0;
	info->x = 0;
	info->y = 0;
	info->moves = 0;
	info->enemies = NULL;
}

int	main(int argc, char *argv[])
{
	t_info	i;

	if (argc != 2)
	{
		printf("Error\nIncorrect number of arguments\n");
		exit(1);
	}
	init_info(&i);
	parse_file(argv[1], &i);
	i.win = mlx_new_window(i.mlx, i.width * SCALE, i.heigth * SCALE, TITLE);
	draw_map(&i);
	mlx_hook(i.win, 2, (1L << 0), key_hook, &i);
	mlx_loop_hook(i.mlx, animation, &i);
	mlx_hook(i.win, 17, (1L << 0), ft_exit, &i);
	mlx_loop(i.mlx);
	return (0);
}
