/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:10:23 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/03 15:12:20 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Check if the buffer has a newline character in it*/
static int	find_newline(char *buffer)
{
	size_t	i;

	i = 0;
	if (buffer)
	{
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

/* Remove characters from the buffer that have already been read*/
static char	*clean_buffer(char *buffer)
{
	size_t	i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		i++;
	ft_strlcpy(buffer, buffer + i, i + 1);
	return (buffer);
}

/* Pull a line from the buffer and put it in a malloc'ed string*/
static char	*pull_line(char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
		i++;
	str = (char *)malloc((i) * sizeof(char));
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	j = i;
	i = 0;
	while (i < j)
	{
		str[i] = buffer[i];
		i++;
	}
	buffer[i] = '\0';
	return (str);
}

/* This function fills the buffer using BUFFER_SIZE,
to then be used by pull line */
static int	fill_buffer(char **buffer, int fd)
{
	int		output;
	char	filling[BUFFER_SIZE + 1];

	while (!find_newline(*buffer) && output)
	{
 		output = read(fd, filling, BUFFER_SIZE);
		if (output < 0)
		{
			if (*buffer)
				free(buffer);
			return (-1);
		}
		*buffer = ft_buffer_add(*buffer, filling);
		if (!*buffer)
			return (-1);
	}
	if (output > 0)
		output = 1;
	return (output);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer;
	int			output;

	output = 1;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	output = fill_buffer(&buffer, fd);
	if (output == -1)
		return (-1);
	*line = pull_line(buffer);
	if (*line == NULL)
		return (-1);
	buffer = clean_buffer(buffer);
	if (output == 0 && buffer != '\0')
		free (buffer);
	return (output);
}
