/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/17 13:25:40 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/18 10:29:29 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
This code is almost exactly the same as the original.
The only difference is that the static variable 'buffer'
is now an array of arrays, with a value of 1024 arrays.
This is because there is a maximum number of 1024 file descriptors
open at any one time. 
*/

#include "get_next_line_bonus.h"

static int	contains_newline(char *string)
{
	size_t	i;

	i = 0;
	if (string == NULL)
		return (0);
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
	char	*filler;

	filler = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	file = 1;
	while (contains_newline(*buffer) == 0 && file > 0)
	{
		file = read(fd, filler, BUFFER_SIZE);
		if (file < 0)
		{
			free(filler);
			filler = NULL;
			return (-1);
		}
		filler[file] = '\0';
		*buffer = add_to_buffer(*buffer, filler);
		if (*buffer == NULL)
			return (-1);
	}
	free(filler);
	filler = NULL;
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
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
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
	size_t	j;

	i = 0;
	j = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] != '\0')
		i++;
	while (buffer[i] != '\0' && i < ft_strlen(buffer))
	{
		buffer[j] = buffer[i];
		i++;
		j++;
	}
	buffer[j] = '\0';
	return (buffer);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer[1024];
	int			return_value;

	if (BUFFER_SIZE < 1 || fd < 0 || !line || fd > 1024)
		return (-1);
	return_value = fill_buffer(fd, &buffer[fd]);
	if (return_value == -1)
		return (-1);
	*line = pull_line(buffer[fd]);
	if (!line)
		return (-1);
	buffer[fd] = edit_buffer(buffer[fd]);
	if (return_value == 0 && buffer[fd] != NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (return_value);
}
