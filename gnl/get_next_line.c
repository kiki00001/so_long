/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 23:02:58 by heahn             #+#    #+#             */
/*   Updated: 2021/07/03 05:28:26 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		num_column(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != (char)c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}

int		get_line(char *temp, char **line, int i)
{
	int		len;

	*line = ft_substr(temp, 0, i);
	i++;
	len = ft_strlen(temp + i) + 1;
	ft_memmove(temp, temp + i, len);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*temp = NULL;
	int				ret;
	int				i;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || read(fd, buff, 0) < 0)
		return (-1);
	if (temp && (((i = num_column(temp, '\n')) != -1)))
		return (get_line(temp, line, i));
	while (((ret = read(fd, buff, BUFFER_SIZE)) > 0))
	{
		buff[ret] = '\0';
		temp = ft_strjoin(temp, buff);
		if (((i = num_column(temp, '\n')) != -1))
			return (get_line(temp, line, i));
	}
	if (temp)
	{
		*line = ft_strdup(temp);
		free(temp);
		temp = NULL;
		return (ret);
	}
	*line = ft_strdup("");
	return (ret);
}
