/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:26:12 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/26 19:19:04 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_fdlist	*fd_list;
	t_fdlist		*itr;
	t_fdlist		*tmp;
	char			*line;

	line = NULL;
	itr = fdseeker(fd, &fd_list);
	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE < 0)
	{
		if (itr)
		{
			tmp = itr->next;
			free(itr->rmd);
			itr->rmd = NULL;
			free(itr);
			itr = tmp;
		}
	}
	else
		line = next_line(fdseeker(fd, &fd_list));
	return (line);
}

char	*next_line(int fd, char *rmd)
{
	char		*line;
	char		*tmp;
	ssize_t		nl;

	line = NULL;
	nl = newline_seeker(read_a_line(fd, &line, rmd)) + 1;
	free(fdlist->rmd);
	fdlist->rmd = NULL;
	if (nl >= 1 && (size_t)nl <= ft_strlen(line))
	{
		tmp = line;
		fdlist->rmd = ft_strjoin(fdlist->rmd, line + nl, ft_strlen(line) - nl);
		line = ft_strjoin(0, line, nl);
		free(tmp);
	}
	return (line);
}

char	*read_a_line(int fd, char **line, char *rmd)
{
	ssize_t	b_len;

	if (rmd)
	{
		if (ft_strlen(rmd) > 0)
			*line = ft_strjoin(0, rmd, ft_strlen(rmd));
	}
	while (42)
	{
		*line = join_the_buf(fd, *line, &b_len);
		if (newline_seeker(*line) >= 0)
			break ;
		if (b_len == BUFFER_SIZE)
			continue ;
		if (b_len < 0)
			free(*line);
		break ;
	}
	return (*line);
}

char	*join_the_buf(int fd, char *line, ssize_t *b_len)
{
	char	*buf;
	char	*tmp;

	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE);
	if (!buf)
	{
		free(line);
		return (0);
	}
	*b_len = read(fd, buf, BUFFER_SIZE);
	if (*b_len > 0)
	{
		tmp = line;
		line = ft_strjoin(line, buf, *b_len);
		free(tmp);
	}
	free(buf);
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
