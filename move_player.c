/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 03:16:33 by heahn             #+#    #+#             */
/*   Updated: 2021/11/25 07:51:44 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_sys *sys)
{
	 next_location(sys, sys->p_row - 1, sys->p_col);
}

void	move_down(t_sys *sys)
{
	next_location(sys, sys->p_row + 1, sys->p_col);
}

void	move_right(t_sys *sys)
{
	next_location(sys, sys->p_row, sys->p_col + 1);
}

void	move_left(t_sys *sys)
{
	next_location(sys, sys->p_row, sys->p_col - 1);
}

int	deal_key(int key_code, t_sys *sys)
{
	if (key_code == KEY_ESC)
		exit(0);
	if (key_code == KEY_W)
		move_up(sys);
	if (key_code == KEY_S)
		move_down(sys);
	if (key_code == KEY_D)
		move_right(sys);
	if (key_code == KEY_A)
		move_left(sys);
	return (0);
}
