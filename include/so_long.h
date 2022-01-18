/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 09:20:40 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 18:05:56 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SCALE 71
# define TITLE "so_long"
# define WALL "./images/cactus.xpm"
# define SAND "./images/sand.xpm"
# define DRIED_PUDDLE "./images/dried_puddle.xpm"
# define PUDDLE "./images/puddle.xpm"
# define DINO1 "./images/dino1.xpm"
# define DINO2 "./images/dino2.xpm"
# define DINO3 "./images/dino3.xpm"
# define DINO4 "./images/dino4.xpm"
# define DINO5 "./images/dino5.xpm"
# define DINO6 "./images/dino6.xpm"
# define DINO7 "./images/dino7.xpm"
# define DROP1 "./images/drop1.xpm"
# define DROP2 "./images/drop2.xpm"
# define DROP3 "./images/drop3.xpm"
# define KEYUP 13
# define KEYDOWN 1
# define KEYRIGHT 2
# define KEYLEFT 0
# define KEYD 124
# define KEYA 123
# define KEYW 126
# define KEYS 125

typedef struct s_info
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			heigth;
	char		**map;
	int			moves;
	int			collectibles;
	int			x;
	int			y;
}	t_info;

int		get_next_line(int fd, char **res);
void	parse_file(char *filename, t_info *map);
void	draw_map(t_info *info);
void	put_xpm_image(int x, int y, const char *file, t_info *info);
int		animation(t_info *info);
int		ft_exit(t_info *vars);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	move_four_directions(t_info *info, int y, int x);

#endif
