/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:51:09 by heahn             #+#    #+#             */
/*   Updated: 2021/11/21 23:49:13 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_init(t_sys *sys)
{
	sys->mlx = mlx_init();
	sys->win = mlx_new_window(sys->mlx, 64 * sys->map_col,
			64 * sys->map_row, "so_long");
	if (sys->mlx == NULL || sys->win == NULL)
		ft_error("=== error : win_init ===\n", 25);
	sys->movement = 0;
	sys->item = 0;
}

void	map_set(t_sys *sys)
{
	int	i;
	int	j;

	i = 0;
	while (i < sys->map_row)
	{
		j = 0;
		while (j < sys->map_col)
		{
			put_img(sys, i, j);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	ft_exit(t_sys *sys)
{
	(void)sys;
	exit(0);
}

void	so_long(char *mapFile)
{
	t_sys	sys;

	map_init(&sys, mapFile);	//map 메모리 할당 , map 구성
	map_error_check(&sys);		//map 에러 체크
	win_init(&sys);				//mlx 연결 초기화 및 윈도우 창 생성 
	img_init(&sys);				//이미지 초기화
	img_check(&sys);			//이미지 에러 체크
	map_set(&sys);				//map 구현
	mlx_hook(sys.win, KEY_PRESS, 0, &deal_key, &sys);
	mlx_hook(sys.win, KEY_EXIT, 0, &ft_exit, &sys);
	mlx_loop(sys.mlx);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		so_long(argv[1]);
	else
		ft_error("=== error : argv ===\n", 21);
	return (0);
}
