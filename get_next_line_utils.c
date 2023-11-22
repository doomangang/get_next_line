/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon <jihyjeon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/23 00:57:42 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_newline(char *s)
{
	size_t	idx;

	idx = 0;
	while (idx != BUFFER_SIZE)
	{
		if (*(s + idx) == '\n')
			return (idx);
		idx++;
	}
	return (idx);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	len;

	len = ft_strlen(src);
	if (len + 1 < size)
		ft_memcpy(dst, src, len + 1);
	else if (size != 0)
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (len);
}

char	*ft_findstr(int fd, static size_t nfh)
{
	char	*buf;
	size_t	fd;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd = read(fd, buf, BUFFER_SIZE);
	if (fd <= 0)
		return (0);
	nfh = 0;
	nfh += ft_newline(buf) + 1;
	this_line = (char *)malloc(sizeof(char) * (nfh + 1));
	ft_strlcpy(this_line, buf, nfh + 1);
}