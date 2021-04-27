/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:10:23 by ahorling      #+#    #+#                 */
/*   Updated: 2021/04/27 16:48:39 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int find_newline(*char buffer)		//this function serves to check if the buffer has a newline character in it
{
	size_t i;

	i = 0;
	while (input[i] != '\0')
		if (input == '\n')
			return (1);
		else i++;
	return (0);
}

int clean_buffer(*buffer)
{

}

char	*pull_line(*buffer)
{
	size_t i;
	size_t j;
	char *str;

	i = 0;
	if (!*buffer)
		return (-1);
	while (buffer[i] != '\n' && buffer[i])
			i++
	str = (char *)malloc((i) * sizeof(char));
	if (!str)
	{
		free(buffer);
		return (-1);
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

int fill_buffer(char **buffer, int fd)
{
	int output;
	char filler[BUFFER_SIZE + 1];

	output = 1;
	while(find_newline(*buffer) = 0 && output > 0)
	{
		output = read(fd, filler, BUFFER_SIZE);
		if (output < 0)
		{
			if (*buffer)
				free(buffer);
			return (-1);
		}
		*buffer = ft_buffer_add(*buffer, filler);
		if (!*buffer)
			return (-1);
	}
	if (output > 0)
		output = 1;
	return (output);
}

int	get_next_line(int fd, char **line)
{
	static *char = buffer;

	buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));

}