/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:59:38 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/23 19:49:33 by jihyjeon         ###   ########.fr       */
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

	if (len <= 0 || ft_strlen(s) <= (size_t)start)
		return (NULL);
	if (ft_strlen(s + (size_t)start) < len)
		len = ft_strlen(s + (size_t)start);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
		return (0);
	ft_memcpy(str, s + (size_t)start, len);
	*(str + len) = 0;
	return (str);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t blen)
{
	char	*new;
	ssize_t	len_s1;

	len_s1 = ft_strlen(s1);
	new = (char *)malloc(sizeof(char) * (len_s1 + blen + 1));
	if (!(new))
		return (0);
	ft_memcpy(new, s1, len_s1);
	ft_memcpy(new + len_s1, s2, blen);
	*(new + len_s1 + blen) = 0;
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
	return (dst);
}
