/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/28 17:45:27 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*this_line;
	char		*buf;
	static char	*remainder;
	ssize_t		buf_len;
	ssize_t		rmd_nl;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	buf_len = read(fd, buf, BUFFER_SIZE);
	if (buf_len <= 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		return (0);
	}
	rmd_nl = newline_seeker(remainder, ft_strlen(remainder));
	if (rmd_nl >= 0)
	{
		this_line = (char *)malloc(sizeof(char) * (rmd_nl + 1));
		if (!this_line)
			return (0);
		ft_strlcpy(this_line, remainder, rmd_nl + 1);
		free(remainder);
		remainder = ft_substr(remainder, rmd_nl, ft_strlen(remainder) - rmd_nl);
	}
	else
		this_line = read_a_line(fd, remainder, buf, buf_len);
	free(buf);
	return (this_line);
}

char	*read_a_line(int fd, char *rmd, char *buf, ssize_t b_len)
{
	char	*line;
	size_t	wrd_len;

	line = ft_strdup(rmd);
	b_len = read(fd, buf, BUFFER_SIZE);
	wrd_len = newline_seeker(buf, b_len);
	while (b_len > 0)
	{
		line = join_the_buf(line, buf, wrd_len);
		if (wrd_len >= 0)
			break ;
		b_len = read(fd, buf, BUFFER_SIZE);
	}
	rmd = ft_substr(buf, wrd_len, b_len - wrd_len);
	if (b_len < 0)
	{
		free(line);
		return (0);
	}
	return (line);
}

char	*join_the_buf(char *line, char *buf, size_t wlen)
{
	char	*new_line;

	if (wlen == BUFFER_SIZE)
		wlen--;
	new_line = ft_strjoin(line, buf, wlen);
	return (new_line);
}

size_t	newline_seeker(char *s, ssize_t blen)
{
	size_t	idx;

	idx = 0;
	while (idx != (size_t)blen)
	{
		if (*(s + idx) == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (*(s + len))
		len++;
	return (len);
}
