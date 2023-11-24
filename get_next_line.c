/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/24 21:05:12 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*this_line;
	char		*buf;
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	this_line = read_a_line(fd, remainder, buf);
	return (this_line);
}

char	*read_a_line(int fd, char *rmd, char *buf)
{
	char	*line;
	ssize_t	b_len;
	size_t	wrd_len;

	if (ft_newline(rmd, ft_strlen(rmd)))
	{
	}
	b_len = read(fd, buf, BUFFER_SIZE);
	wrd_len = ft_newline(buf, b_len);
	while (b_len > 0)
	{
		line = join_the_buf(line, buf, b_len, wrd_len);
		if (wrd_len != b_len)
			break ;
		b_len = read(fd, buf, BUFFER_SIZE);
	}
	rmd = ft_substr(buf, wrd_len, b_len - wrd_len);
	free(buf);
	if (b_len < 0)
	{
		free(line);
		return (0);
	}
	return (line);
}

char	*join_the_buf(char *line, char *buf, ssize_t blen, size_t wlen)
{
	char	*new_line;

	if (wlen == BUFFER_SIZE)
		wlen--;
	new_line = ft_strjoin(line, buf, wlen);
	return (new_line);
}
