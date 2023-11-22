/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/22 17:59:24 by jihyjeon         ###   ########.fr       */
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

size_t	len_cmp(char const *str, size_t len)
{
	size_t	str_l;

	str_l = ft_strlen(str);
	if (str_l <= len)
		return (str_l);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	r_len;

	if (ft_strlen(s) <= (size_t)start)
	{
		str = (char *)ft_calloc(sizeof(char), 1);
		*str = 0;
		return (str);
	}
	r_len = len_cmp(s + (size_t)start, len);
	str = (char *)ft_calloc(sizeof(char), r_len + 1);
	if (!(str))
		return (0);
	ft_strlcpy(str, s + (size_t)start, r_len + 1);
	return (str);
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