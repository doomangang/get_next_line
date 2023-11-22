/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/22 22:22:57 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_findstr(char *buf)
{
	char	*str;
	size_t	len;

	len = ft_newline(buf) + 1;
	str = ft_memmove(str, buf, len);
}

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*s;

	s = str;
	while (len--)
		*(s++) = (unsigned char)c;
	return (str);
}

char	*read_line(size_t *nfh, int fd)
{
	char	*line;
	char	*buf;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	while (42)
	{
		ft_memset()
		if (read(fd, buf, BUFFER_SIZE) < 0)
			return (0);
		line = ft_findstr(buf);
		if (ft_newline(buf) == BUFFER_SIZE)
		{
			*nfh += BUFFER_SIZE;
			continue ;
		}
		else
			break ;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char			*this_line;
	size_t			fd;
	static size_t	next_from_here;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	next_from_here = 0;
	this_line = read_line(&next_from_here, fd);
	return (this_line);
}
