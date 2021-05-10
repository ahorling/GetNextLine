/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/04 14:22:06 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/10 17:24:18 by ahorling      ########   odam.nl         */
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
 	while (contains_newline(*buffer) == 0 && file > 0)
	{
		file = read(fd, filler, BUFFER_SIZE);
		if (file < 0)
			return (-1);
		filler[file] = '\0';
		*buffer = add_to_buffer(*buffer, filler);
		if (!buffer)
		{
			free(buffer);
			return (-1);
		}
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
	line = (char *)malloc((i + 1) * sizeof(char));
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

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		return (buffer);
	else
		new_buffer = ft_strdup(buffer + i + 1);
	if (!new_buffer)
		return (NULL);
	return (new_buffer);
}

/*Function get_next_line should go through a file and return what is read,
up until a newline. once called again it should remember where it left
off and return another line, so when called in a loop it shold return the entire file
line by line. This is done by using a static string (buffer) which is filled, pulled from
and then adjusted by multiple functions.

First we create the static string 'buffer' and check for a number of errors such as
not having a BUFFER_SIZE to make sure the conditions are correct.

Then we call the fill_buffer function to begin filling our static string
from the file. fill_buffer then calls another function 'contains_newline'
to check if there is a newline among the characters currently in the buffer.
As the buffer is empty currently, there can not be, and fill_buffer reads from the file.
The read text is placed into a 'filler' string, which is the size of the designated BUFFER_SIZE.
The filler and the static buffer are then passed to another function 'add_to_buffer'

add_to_buffer checks to see if the buffer is empty or not. If it is, it
simply duplicates the filler into a new buffer and returns that.
If not, it joins the old buffer and the filler together and returns that.

now that the buffer string has been filled, fill_buffer makes sure
memory allocation was successful, before once again checking if the buffer
contains a newline via 'contains_newline', repeating the process until
either buffer has a newline character, or EOF is reached. fill_buffer
then returns either a 1 on a found newline, or 0 on EOF.

GNL checks the return value of fill_buffer for errors, before calling
the 'pull_line' function. 'pull_line' goes through the buffer until either
a newline is found, or the buffer comes to an end (representing EOF).
it then allocates memory equal to the number of characters before the
newline + 1 for the null-terminator. 'pull_line' then copies the contents
from the buffer to the newly-allocated line, stopping at a newline
and ending the string with a null-terminator.
Once finished, the created line is returned.

Once the line string has been created, the 'edit_buffer' function goes
through the buffer in order to find the location of the newline.
Once it has, it edits the buffer by creating a new one starting
at the position after the newline and copying the rest of the
existing buffer over to the new one.

Finally there is a check to see if the function has reached EOF, and
if so the remaining buffer is freed before returning 0.*/


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