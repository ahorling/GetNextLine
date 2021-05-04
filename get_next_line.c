/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line3.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 14:22:06 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/04 17:37:33 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	contains_newline(char *string)
{
	size_t	i;

	i = 0;
	if (!string)
		return ('\0');
	while (string[i] != '\0')
	{
		if (string[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static int	fill_buffer(int fd, char **buffer)
{
	int		file;
	char	filler[BUFFER_SIZE + 1];

	file = 1;
 	while (contains_newline(*buffer) == 0 && file != 0)
	{
		file = read(fd, filler, BUFFER_SIZE);
		if (file < 0)
			return (-1);
		*buffer = add_to_buffer(*buffer, filler, file);
		if (!buffer)
			return (-1);
	}
	if (file > 0)
		file = 1;
	return (file);
}

static char	*pull_line(char *buffer)
{
	size_t	i;
	char	*line;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	line = (char *)malloc((i) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*edit_buffer(char *buffer)
{
	size_t	i;
	char	*new_buffer;

	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	i++;
	new_buffer = ft_strdup(buffer + i);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer;
	int			return_value;

	if (BUFFER_SIZE < 0 || fd < 0 || !line)
		return (-1);
	return_value = fill_buffer(fd, &buffer);
 	if (return_value == -1)
		return (-1);
	*line = pull_line(buffer);
	if (!line)
		return (-1);
	buffer = edit_buffer(buffer);
	if (buffer == '\0' && return_value == 0)
	{
		free(buffer);
		return (0);
	}
	return (1);
}