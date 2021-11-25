/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:32:34 by heahn             #+#    #+#             */
/*   Updated: 2021/11/25 08:21:07 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, int len)
{
	write(1, str, len);
	exit(1);
}

void	obj_check(t_sys *sys)
{
	int	i;
	int	j;

	i = 0;
	while (i < sys->map_row)
	{
		j = 0;
		while (j < sys->map_col)
		{
			if (sys->map[i][j] == 'P')
				sys->obj.cnt_player++;
			else if (sys->map[i][j] == 'C')
				sys->obj.cnt_item++;
			else if (sys->map[i][j] == 'E')
				sys->obj.cnt_exit++;
			j++;
		}
		i++;
	}
	if (sys->obj.cnt_player != 1)
		ft_error("=== error: num of player (P) ===\n", 33);
	if (sys->obj.cnt_item == 0)
		ft_error("=== error: No item (C) ===\n", 27);
	if (sys->obj.cnt_exit == 0)
		ft_error("=== error: No exit (E) ===\n", 27);
}

void	map_check(t_sys *sys)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < sys->map_row)
	{
		j = 0;
		while (j < sys->map_col)
		{
			if (i == 0 || i == sys->map_row - 1 || j == 0 || j == sys->map_col)
			{
				if (sys->map[i][j] != '1')
					ft_error("error : wall not '1'\n", 21);
			}
			c = sys->map[i][j];
			if (!(c == '1' || c == '0' || c == 'C' || c == 'E' || c == 'P'))
				ft_error("error : incorrect char\n", 23);
			j ++;
		}
		i++;
	}
}

void	rectangle_check(t_sys *sys)
{
	int	i;

	i = 0;
	while (i < sys->map_row)
	{
		if (ft_strlen(sys->map[i]) != sys->map_col)
			ft_error("=== error : Not a rectangle map ===\n", 37);
		i++;
	}
}

void	map_error_check(t_sys *sys)
{
	sys->obj.cnt_player = 0;
	sys->obj.cnt_item = 0;
	sys->obj.cnt_exit = 0;
	obj_check(sys);
	map_check(sys);
	rectangle_check(sys);
}
