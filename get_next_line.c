/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/23 00:57:25 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlcat(char *dst, char *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	n;
	size_t	dlen;

	d = dst;
	while (n-- && *d != '\0')
		d++;
	dlen = d - dst;
	n = len - dlen;
	if (n == 0)
		return (dlen + ft_strlen(s));
	while (*s) 
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dlen + (s - src));
}

char	*read_a_line(int fd, char *rmd)
{
	char	*line;
	char	*buf;
	ssize_t	b_len;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	b_len = read(fd, buf, BUFFER_SIZE);
	while (b_len)
	{
		line = ft_strlcat(line, buf, ft_strlen(line) + ft_newline(buf) + 1);
		if (ft_newline(buf) == BUFFER_SIZE)
			b_len = read(fd, buf, BUFFER_SIZE);
		else
			break ;
	}
	free(buf);
	if (b_len < 0)
		return (0);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*this_line;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	this_line = read_a_line(fd, remainder);
	return (this_line);
}
