/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:07:31 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/22 16:20:03 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char			*this_line;
	char			*buf;
	static size_t	next_from_here;
	size_t			fd;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	fd = read(fd, buf, BUFFER_SIZE);
	if (fd <= 0)
		return (0);
	next_from_here = ft_newline(buf) + 1;
	this_line = (char *)malloc(sizeof(char) * (next_from_here + 1));
	ft_strlcpy(this_line, buf, next_from_here + 1);
	return (this_line);
}
