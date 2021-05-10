/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:28:52 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/10 11:10:06 by ahorling      ########   odam.nl         */
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
size_t	ft_strlcpy(char *dest, const char *source, size_t size);
char	*add_to_buffer(char *buffer, char *filler);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
