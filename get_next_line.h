/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyjeon < jihyjeon@student.42seoul.kr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:00:42 by jihyjeon          #+#    #+#             */
/*   Updated: 2023/11/28 21:00:45 by jihyjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
char	*read_a_line(int fd, char *rmd, char *buf, ssize_t b_len);
char	*join_the_buf(char *line, char *buf, char *rmd, ssize_t b_len);
size_t	newline_seeker(char *s, ssize_t blen);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2, size_t len);
char	*ft_strdup(char *src);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
void	*ft_memcpy(void *dst, void *src, size_t n);

#endif