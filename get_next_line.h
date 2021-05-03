/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:28:52 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/03 12:24:32 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_fill_empty(char *src, size_t length);
void	*ft_memcpy(void *dest, const void *src, size_t size);
char	*ft_buffer_add(char const *s1, char const *s2);

#endif
