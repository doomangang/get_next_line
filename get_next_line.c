/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/22 23:55:41 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t strlcat(char *dst, char *src)
{
	char *d;
	char *s;
	size_t n;
	size_t dlen;

	d= dst;
	
	while (n-- && *d != '\0')
		d++;
	dlen = d - dst;
	n = len - dlen;

	if (n == 0)
		return(dlen + strlen(s));
	while (*s != '\0') {
		if (n != 1) {
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';

	return(dlen + (s - src));	/* count does not include NUL */
}

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*s;

	s = str;
	while (len--)
		*(s++) = (unsigned char)c;
	return (str);
}

char	*read_a_line(int fd)
{
	char	*line;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (42)
	{
		ft_memset(buf, 0, BUFFER_SIZE);
		if (read(fd, buf, BUFFER_SIZE) < 0)
			return (0);
		line = ft_strlcat(line, buf);
		if (ft_newline(buf) == BUFFER_SIZE)
			continue ;
		else
			break ;
	}
	free(buf);
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
