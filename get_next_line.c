/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/20 22:56:49 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*this_line;
	char		*buf;
	static char	*remainder;
	ssize_t		buf_len;
	ssize_t		nl;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	buf_len = read(fd, buf, BUFFER_SIZE);
	this_line = NULL;
	if (BUFFER_SIZE > 0)
		this_line = read_a_line(fd, this_line, buf, remainder);
	nl = newline_seeker(this_line);
	if (nl >= 0 && (size_t)nl != ft_strlen(this_line) - 1)
	{
		remainder = ft_substr(this_line, nl + 1, ft_strlen(this_line) - nl - 1);
		this_line = ft_substr(this_line, 0, nl + 1);
	}
	free_ptr(buf);
	return (this_line);
}

char	*read_a_line(int fd, char *line, char *buf, char *rmd)
{
	ssize_t	b_len;

	b_len = ft_strlen(buf);
	if (rmd)
	{
		line = ft_substr(rmd, 0, ft_strlen(rmd));
		free_ptr(rmd);
	}
	while (b_len > 0)
	{
		line = ft_strjoin(line, buf, b_len);
		if (newline_seeker(line) >= 0)
			break ;
		if (b_len == BUFFER_SIZE)
			b_len = read(fd, buf, BUFFER_SIZE);
		else
		{
			if (b_len < 0)
				free_ptr(line);
			break ;
		}
	}
	return (line);
}

ssize_t	newline_seeker(char *s)
{
	size_t	idx;

	idx = 0;
	while (*(s + idx))
	{
		if (*(s + idx) == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}
