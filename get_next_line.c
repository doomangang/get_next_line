/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/15 22:37:58 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*this_line;
	char		*buf;
	static char	*remainder;
	ssize_t		buf_len;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	buf_len = read(fd, buf, BUFFER_SIZE);
	if (buf_len <= 0 || BUFFER_SIZE <= 0)
	{
		free(buf);
		return (0);
	}
	if (remainder)
	{
		this_line = ft_substr(remainder, 0, ft_strlen(remainder));
		free(remainder);
		remainder = NULL;
	}
	this_line = read_a_line(fd, remainder, buf, buf_len);
	free(buf);
	buf = NULL;
	return (this_line);
}

char	*read_a_line(int fd, char *rmd, char *buf, ssize_t b_len)
{
	char	*line;

	if (b_len < 0)
	{
		free(line);
		line = NULL;
		return (0);
	}
	while (b_len == BUFFER_SIZE)
	{
	line = join_the_buf(line, buf, rmd, b_len);
	if (b_len == BUFFER_SIZE)
		b_len = read(fd, buf, BUFFER_SIZE);
	else
		break;
	}
	return (line);
}

char	*join_the_buf(char *line, char *buf, char *rmd, ssize_t b_len)
{
	char	*new_line;
	char	*tmp;
	ssize_t	nl;

	new_line = ft_strjoin(line, buf, b_len);
	nl = newline_seeker(new_line);
	if (nl >= 0)
	{
		rmd = ft_substr(new_line, nl + 1, ft_strlen(new_line) - nl - 1);
		tmp = new_line;
		new_line = ft_substr(new_line, 0, nl + 1);
		free(tmp);
		tmp = NULL;
		return (new_line);
	}
	free(line);
	line = NULL;
	return (new_line);
}

ssize_t	newline_seeker(char *s)
{
	size_t	idx;

	idx = 0;
	while (*s)
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
