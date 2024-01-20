/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/20 22:56:51 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;

	if (!len || ft_strlen(s) <= (size_t)start)
		return (NULL);
	if (ft_strlen(s + (size_t)start) < len)
		len = ft_strlen(s + (size_t)start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	ft_memcpy(str, s + (size_t)start, len);
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t blen)
{
	char	*new;
	char	*tmp;
	ssize_t	idx;

	if (!s1)
		return (ft_memcpy((char *)malloc(ft_strlen(s2) + 1), s2, ft_strlen(s2)));
	new = (char *)malloc(sizeof(char) * (ft_strlen(s1) + blen + 1));
	if (!(new))
		return (0);
	tmp = new;
	idx = 0;
	while (*s1)
	{
		*tmp = *(s1++);
		tmp++;
	}
	while (*s2 && idx != blen)
	{
		*tmp = *(s2++);
		tmp++;
		idx++;
	}
	*tmp = '\0';
	return (new);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;	

	d = dst;
	s = (unsigned char *)src;
	if (!d && !s)
		return (0);
	if (d < s || d >= (s + n))
	{
		while (n--)
			*(d++) = *(s++);
	}
	else
	{
		d += n;
		s += n;
		while (n--)
			*(--d) = *(--s);
	}
	*(char *)(dst + n) = '\0';
	return (dst);
}

void	free_ptr(char *ptr)
{
	free(ptr);
	ptr = NULL;
}