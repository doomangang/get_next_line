/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/24 19:07:03 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_newline(char *s, ssize_t blen)
{
	size_t	idx;

	idx = 0;
	while (idx != blen)
	{
		if (*(s + idx) == '\n')
			break ;
		idx++;
	}
	return (idx);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!len || ft_strlen(s) <= (size_t)start)
		return (ft_strdup(""));
	if (ft_strlen(s + (size_t)start) < len)
		len = ft_strlen(s + (size_t)start);
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!(str))
		return (0);
	ft_strlcpy(str, s + (size_t)start, len + 1);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*ft_strjoin(char *s1, char *s2, size_t len)
{
	char	*new;
	char	*tmp;
	size_t	idx;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (!(new))
		return (0);
	tmp = new;
	idx = 0;
	while (*s1)
	{
		*tmp = *s1;
		s1++;
		tmp++;
	}
	while (*s2 && idx != len)
	{
		*tmp = *s2;
		s2++;
		tmp++;
		idx++;
	}
	*tmp = '\0';
	return (new);
}

char	*ft_strdup(char *src)
{
	size_t	len;
	char	*ptr;

	len = ft_strlen(src);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!(ptr))
		return (0);
	ft_strlcpy(ptr, src, len + 1);
	return (ptr);
}
