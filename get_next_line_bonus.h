/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:26:18 by jihyjeon          #+#    #+#             */
/*   Updated: 2024/01/30 22:40:12 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_fdlist
{
	int				fd;
	char			*rmd;
	struct s_fdlist	*next;
}					t_fdlist;

char		*get_next_line(int fd);
char		*next_line(int fd, t_fdlist *list);
char		*read_a_line(int fd, char **line, char *rmd);
char		*join_the_buf(int fd, char *line, ssize_t *b_len);
ssize_t		newline_seeker(char *s);
size_t		ft_strlen(char *s);
char		*ft_strjoin(char *s1, char *s2, ssize_t blen);
void		*ft_memcpy(void *dst, void *src, size_t n);
t_fdlist	*fdseeker(int fd, t_fdlist *list);
void		ft_lstdelone(int fd, t_fdlist *lst);

#endif