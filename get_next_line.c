/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:10:23 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/03 11:57:26 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int find_newline(*char buffer)		//this function serves to check if the buffer has a newline character in it
{
	size_t i;

	i = 0;
	if (!buffer)
		return (-1);
	while (buffer[i] != '\0')
		if (buffer == '\n')
			return (1); 
		i++;
	return (0);
}

char	*clean_buffer(*buffer)		//This function serves to remove characters from the buffer that have already been read
{
	size_t i;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\0')
		i++;
	ft_strlcpy(buffer, buffer[i], i + 1);
	return(buffer);
}

char	*pull_line(*buffer)		//this function takes the line from the buffer and puts it in a malloc'ed string
{
	size_t i;
	size_t j;
	char *str;

	i = 0;
	if (!*buffer)
		return (NULL);
	while (buffer[i] != '\n' && buffer[i])
			i++
	str = (char *)malloc((i) * sizeof(char));
	if (!str)
	{
		free(buffer);
		return (NULL);
	}
	j = i;
	i = 0;
	while (i <= j)
	{
		str[i] = buffer[i];
		i++;
	}
	return (str);
}

int fill_buffer(char **buffer, int fd)		//this function fills the buffer using BUFFER_SIZE, to then be used by pull line
{
	int output;
	char filling[BUFFER_SIZE + 1];

	output = 1;
	while(!find_newline(*buffer))
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
	static char *buffer;
	int	output;

	output = 1;
	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1)
	output = fill_buffer(&buffer, fd);
	if (output == - 1)
		return (-1);
	*line = pull_line(buffer);
	if (*line == NULL)
		return (-1);
	buffer = clean_buffer(buffer);
	if (output == 0 && buffer != '\0')
		free (buffer);
	return (output);
}