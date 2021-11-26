/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 22:04:20 by heahn             #+#    #+#             */
/*   Updated: 2021/11/25 08:23:51 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_sys *sys, int i, int j)
{
	mlx_put_image_to_window(sys->mlx, sys->win, sys->obj.img_tile,
		i * 64, j * 64);
}

void	put_wall(t_sys *sys, int i, int j)
{
	mlx_put_image_to_window(sys->mlx, sys->win, sys->obj.img_wall,
		i * 64, j * 64);
}

void	put_item(t_sys *sys, int i, int j)
{
	mlx_put_image_to_window(sys->mlx, sys->win, sys->obj.img_item,
		i * 64, j * 64);
}

void	put_exit(t_sys *sys, int i, int j)
{
	mlx_put_image_to_window(sys->mlx, sys->win, sys->obj.img_exit,
		i * 64, j * 64);
}

void	put_player(t_sys *sys, int i, int j)
{
	mlx_put_image_to_window(sys->mlx, sys->win, sys->obj.img_player,
		i * 64, j * 64);
}

void	put_img(t_sys *sys, int i, int j)
{
	if (sys->map[i][j] == '1')
		put_wall(sys, j, i);
	else if (sys->map[i][j] == '0')
		put_tile(sys, j, i);
	else if (sys->map[i][j] == 'P')
	{
		put_tile(sys, j, i);
		put_player(sys, j, i);
		sys->p_row = i;
		sys->p_col = j;
	}
	else if (sys->map[i][j] == 'C')
	{
		put_tile(sys, j, i);
		put_item(sys, j, i);
		(sys->item)++;
	}
	else if (sys->map[i][j] == 'E')
		put_exit(sys, j, i);
}
