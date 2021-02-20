/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 22:17:58 by tcynthia          #+#    #+#             */
/*   Updated: 2021/01/28 19:20:20 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t				ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char				*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		else
			s++;
	}
	if (*s == c && c == '\0')
		return ((char *)s);
	return (NULL);
}

void				ft_memdel(void **am)
{
	if (am != 0 && *am != 0)
	{
		free(*am);
		*am = NULL;
	}
}

static void			next_str_to_buf(char **line, char *buf)
{
	int				len;
	char			*del_ln;

	del_ln = *line;
	*line = ft_strjoin(*line, buf);
	ft_memdel((void **)&del_ln);
	len = BUFFER_SIZE - ft_strlen(buf);
	ft_memmove(buf, buf + ft_strlen(buf) + 1, len);
	ft_memset((void *)(buf + len), 0, BUFFER_SIZE - len);
}

int					get_next_line(int fd, char **line)
{
	static char		buf[BUFFER_SIZE + 1];
	char			*ptr;
	int				rd;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || (read(fd, buf, 0)) < 0)
		return (-1);
	*line = ft_strjoin("", "");
	rd = 1;
	while (rd && rd != -1)
	{
		if ((ptr = ft_strchr(buf, '\n')))
			*ptr = '\0';
		next_str_to_buf(line, buf);
		if (ptr)
			return (1);
		rd = read(fd, buf, BUFFER_SIZE);
	}
	return (rd);
}
