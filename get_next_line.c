/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/28 21:00:44 by jihyjeon         ###   ########.fr       */
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
	this_line = read_a_line(fd, remainder, buf, buf_len);
	free(buf);
	return (this_line);
}

char	*read_a_line(int fd, char *rmd, char *buf, ssize_t b_len)
{
	char	*line;

	if (rmd)
	{
		line = ft_strdup(rmd);
		free(rmd);
		rmd = NULL;
	}
	if (b_len < 0)
	{
		free(line);
		return (0);
	}
	line = join_the_buf(line, buf, rmd, b_len);

}

char	*join_the_buf(char *line, char *buf, char *rmd, ssize_t b_len)
{
	char	*new_line;

	new_line = ft_strjoin(line, buf);
	free(line);
	return (new_line);
}

size_t	newline_seeker(char *s)
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
