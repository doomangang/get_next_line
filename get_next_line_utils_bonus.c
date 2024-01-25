/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:26:21 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/25 19:50:41 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*fdseeker(int fd, t_fdlist **list)
{
	t_fdlist	*new;

	while ((*list) && (*list)->next)
	{
		if ((*list)->fd == fd)
			return ((*list)->rmd);
		*list = (*list)->next;
	}
	new = (t_fdlist *)malloc(sizeof(t_fdlist));
	if (new)
	{
		new->fd = fd;
		new->rmd = NULL;
		new->next = NULL;
		if (*list)
			(*list)->next = new;
		else
			(*list) = new;
	}
	else
		ft_lstclear((list));
	return ((*list)->rmd);
}

void	ft_lstclear(t_fdlist **lst)
{
	t_fdlist	*tmp;

	if (!(lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->rmd);
		free(*lst);
		*lst = tmp;
	}
}