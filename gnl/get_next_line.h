/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/27 06:37:14 by heahn             #+#    #+#             */
/*   Updated: 2021/06/29 04:45:12 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

int			get_next_line(int fd, char **line);
int			num_column(const char *s, int c);
int			get_line(char *str, char **line, int i);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_substr(char const *s, int start, int len);
void		*ft_memmove(void *dst, const void *src, size_t len);

#endif
