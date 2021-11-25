/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 03:13:44 by heahn             #+#    #+#             */
/*   Updated: 2021/11/25 08:13:03 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# define KEY_PRESS 2
# define KEY_EXIT 17
# define KEY_ESC 53
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2

typedef struct s_obj
{
	int		cnt_player;
	int		cnt_item;
	int		cnt_exit;	
	void	*img_tile;
	void	*img_wall;
	void	*img_player;
	void	*img_item;
	void	*img_exit;
	int		img_width;
	int		img_height;
}	t_obj;

typedef struct s_sys
{
	void	*mlx;
	void	*win;
	char	**map;
	int		map_row;
	int		map_col;
	t_obj	obj;
	int		movement;
	int		item;
	int		p_row;
	int		p_col;
}	t_sys;

void	img_init(t_sys *sys);
void	img_check(t_sys *sys);
void	put_img(t_sys *sys, int i, int j);

char	*ft_strdup(char *s1);
size_t	ft_len(int n);
char	*ft_itoa(int n);

int		ft_strlen(char *str);
char	*ft_init_molloc(char c, int i);
int		ft_strcat(char **str, char c);
int		get_next_line(int fd, char **line);

void	win_init(t_sys *sys);
void	map_set(t_sys *sys);
int		ft_exit(t_sys *sys);
void	so_long(char *mapFile);
int		main(int argc, char **argv);

void	ft_error(char *str, int len);
void	obj_check(t_sys *sys);
void	map_check(t_sys *sys);
void	rectangle_check(t_sys *sys);
void	map_error_check(t_sys *sys);

int		row_cnt(char *mapFile);
char	**malloc_row(t_sys *sys, char *mapFile);
void	map_init(t_sys *sys, char *mapFile);

void	move_up(t_sys *sys);
void	move_down(t_sys *sys);
void	move_right(t_sys *sys);
void	move_left(t_sys *sys);
int		deal_key(int key_code, t_sys *sys);

void	next_loc_is_0(t_sys *sys, int i, int j);
void	next_loc_is_C(t_sys *sys, int i, int j);
void	next_location(t_sys *sys, int i, int j);
void	new_location(t_sys *sys, int i, int j);
void	ft_write(char *num, int len);

void	put_tile(t_sys *sys, int i, int j);
void	put_wall(t_sys *sys, int i, int j);
void	put_item(t_sys *sys, int i, int j);
void	put_exit(t_sys *sys, int i, int j);
void	put_player(t_sys *sys, int i, int j);

#endif
