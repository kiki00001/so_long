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
