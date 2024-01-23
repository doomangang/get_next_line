/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/23 23:38:32 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*this_line;
	char		*tmp;
	static char	*remainder;
	ssize_t		nl;

	if (fd < 0 || read(fd, NULL, 0) == -1)
	{
		free(remainder);
		remainder = NULL;
		return (NULL);
	}
	this_line = NULL;
	if (remainder)
	{
		this_line = ft_substr(remainder, 0, ft_strlen(remainder));
		free(remainder);
		remainder = NULL;
	}
	if (BUFFER_SIZE > 0)
		this_line = read_a_line(fd, this_line);
	nl = newline_seeker(this_line);
	if (nl >= 0 && (size_t)nl <= ft_strlen(this_line) - 1)
	{
		tmp = this_line;
		remainder = ft_substr(this_line, nl + 1, ft_strlen(this_line) - nl - 1);
		this_line = ft_substr(tmp, 0, nl + 1);
		if (!this_line)
		{
			free(remainder);
			remainder = NULL;
		}
		free(tmp);
	}
	return (this_line);
}

char	*read_a_line(int fd, char *line)
{
	char	*buf;
	char	*tmp;
	ssize_t	b_len;

	while (42)
	{
		buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if (!buf)
		{
			free(line);
			return (0);
		}
		b_len = read(fd, buf, BUFFER_SIZE);
		if (b_len > 0)
		{
			tmp = line;
			line = ft_strjoin(line, buf, b_len);
			free(tmp);
		}
		free(buf);
		if (newline_seeker(line) >= 0)
			break ;
		if (b_len == BUFFER_SIZE)
			continue ;
		if (b_len < 0)
			free(line);
		break ;
	}
	return (line);
}

ssize_t	newline_seeker(char *s)
{
	size_t	idx;

	idx = 0;
	if (!s)
		return (-1);
	while (*(s + idx))
	{
		if (*(s + idx) == '\n')
			return (idx);
		idx++;
	}
	return (-1);
}
