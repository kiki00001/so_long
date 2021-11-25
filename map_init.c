/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:34:00 by heahn             #+#    #+#             */
/*   Updated: 2021/11/24 15:34:04 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	row_cnt(char *mapFile)
{
	int		fd;
	int		cnt;
	int		total_byte;
	char	c;

	cnt = 0;
	fd = open(mapFile, O_RDONLY);
	while (1)
	{
		total_byte = read(fd, &c, 1);
		if (total_byte == 0)
			break ;
		if (total_byte < 0)
			ft_error("=== error : mapFile ===\n", 24);
		if (c == '\n')
			cnt++;
	}
	close(fd);
	return (cnt);
}

char	**malloc_row(t_sys *sys, char *mapFile)
{
	char	**map;
	int		y;

	y = row_cnt(mapFile);
	if (y <= 0)
		ft_error("=== error : mapFile ===\n", 24);
	sys->map_row = y;
	map = (char **)malloc(sizeof(char *) * (y + 1));
	if (map == NULL)
		return (0);
	return (map);
}

void	map_init(t_sys *sys, char *mapFile)
{
	int	i;
	int	fd;

	sys->map = malloc_row(sys, mapFile);
	fd = open(mapFile, O_RDONLY);
	i = 0;
	while (get_next_line(fd, &sys->map[i]))
		i++;
	sys->map_col = ft_strlen(sys->map[0]);
	sys->map[i] = 0;
	close(fd);
}
