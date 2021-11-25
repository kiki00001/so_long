/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_reset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:26:36 by heahn             #+#    #+#             */
/*   Updated: 2021/11/25 08:05:31 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	next_loc_is_0(t_sys *sys, int i, int j)
{
	put_tile(sys, sys->p_col, sys->p_row);
	sys->map[sys->p_row][sys->p_col] = '0';
	new_location(sys, i, j);
	put_player(sys, sys->p_col, sys->p_row);
	sys->map[sys->p_row][sys->p_col] = 'P';
}

void	next_loc_is_C(t_sys *sys, int i, int j)
{
	put_tile(sys, sys->p_col, sys->p_row);
	sys->map[sys->p_row][sys->p_col] = '0';
	new_location(sys, i, j);
	put_tile(sys, sys->p_col, sys->p_row);
	put_player(sys, sys->p_col, sys->p_row);
	sys->item--;
}

void	next_location(t_sys *sys, int i, int j)
{
	if (sys->map[i][j] == '1')
		write(1, "Can't move to the wall.\n", 24);
	else if (sys->map[i][j] == '0')
		next_loc_is_0(sys, i, j);
	else if (sys->map[i][j] == 'C')
		next_loc_is_C(sys, i, j);
	else if (sys->map[i][j] == 'E')
	{
		if (sys->item == 0)
		{
			write(1, "SUCCESS!\n", 9);
			new_location(sys, i, j);
			put_player(sys, sys->p_row, sys->p_col);
			exit(0);
		}
		else
			write(1, "Collect all the items.\n", 23);
	}
	else
		ft_error("=== erorr ===\n", 14);
}

void	new_location(t_sys *sys, int i, int j)
{
	sys->p_row = i;
	sys->p_col = j;
	sys->movement++;
	ft_write(ft_itoa(sys->movement), ft_len(sys->movement));
}

void	ft_write(char *num, int len)
{
	write(1, "movement_count : ", 18);
	write(1, num, len);
	write(1, "\n", 1);
}
