/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmeredyt <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:07:22 by pmeredyt          #+#    #+#             */
/*   Updated: 2022/01/17 18:10:02 by pmeredyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define SCALE 70
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
# define ENEMY1 "./images/enemy1.xpm"
# define ENEMY2 "./images/enemy2.xpm"
# define ENEMY3 "./images/enemy3.xpm"
# define KEYUP 13
# define KEYDOWN 1
# define KEYRIGHT 2
# define KEYLEFT 0
# define KEYD 124
# define KEYA 123
# define KEYW 126
# define KEYS 125

typedef enum e_enemy_type
{
	VERTICAL,
	HORIZONTAL
}	t_enemy_type;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				flag;
	t_enemy_type	type;
}					t_enemy;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_info
{
	void			*mlx;
	void			*win;
	void			*img;
	int				width;
	int				heigth;
	char			**map;
	int				moves;
	int				collectibles;
	int				x;
	int				y;
	t_list			*enemies;
}					t_info;

int		get_next_line(int fd, char **res);
void	parse_file(char *filename, t_info *map);
void	draw_map(t_info *info);
void	move_four_directions(t_info *info, int y, int x);
void	put_xpm_image(int x, int y, const char *file, t_info *info);
int		animation(t_info *info);
int		ft_exit(t_info *vars);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itoa(int n);
void	check_positions(t_info *info);
void	move_enemies(t_info *info);
void	delete_elem(void *content);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new_el);
void	ft_lstclear(t_list **lst, void (*del)(void *));

#endif
