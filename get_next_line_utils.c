/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/24 22:33:40 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_newline(char *s, ssize_t blen)
{
	size_t	idx;

	idx = 0;
	while (idx != (size_t)blen)
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
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	ft_strlcpy(str, s + (size_t)start, len + 1);
	return (str);
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
	free(s1);
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

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (*(src + len))
		len ++;
	while (*(src + i) && i + 1 < size)
	{
		*(dst + i) = *(src + i);
		i ++;
	}
	if (size > 0)
		*(dst + i) = '\0';
	return (len);
}
