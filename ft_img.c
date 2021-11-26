/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:36:33 by heahn             #+#    #+#             */
/*   Updated: 2021/11/25 09:02:45 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_sys *sys)
{
	sys->obj.img_width = 50;
	sys->obj.img_height = 50;
	sys->obj.img_tile = mlx_xpm_file_to_image(sys->mlx,
			"./img/64t.xpm", &sys->obj.img_width, &sys->obj.img_height);
	sys->obj.img_wall = mlx_xpm_file_to_image(sys->mlx,
			"./img/64_wall.xpm", &sys->obj.img_width, &sys->obj.img_height);
	sys->obj.img_player = mlx_xpm_file_to_image(sys->mlx,
			"./img/64p.xpm", &sys->obj.img_width, &sys->obj.img_height);
	sys->obj.img_item = mlx_xpm_file_to_image(sys->mlx,
			"./img/64i.xpm", &sys->obj.img_width, &sys->obj.img_height);
	sys->obj.img_exit = mlx_xpm_file_to_image(sys->mlx,
			"./img/64e.xpm", &sys->obj.img_width, &sys->obj.img_height);
}

void	img_check(t_sys *sys)
{
	if (sys->obj.img_tile == NULL)
		ft_error("=== error : tile image ===\n", 27);
	if (sys->obj.img_wall == NULL)
		ft_error("=== error : wall image ===\n", 27);
	if (sys->obj.img_player == NULL)
		ft_error("=== error : player image ===\n", 29);
	if (sys->obj.img_item == NULL)
		ft_error("=== error : item image ===\n", 27);
	if (sys->obj.img_exit == NULL)
		ft_error("=== error : exit image ===\n", 27);
}
