/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:27:56 by ahorling      #+#    #+#                 */
/*   Updated: 2022/09/23 16:50:16 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static void	print_error(int fd, char **line)
{
	if (fd < 0)
		printf("Error in file opening\n");
	if (!line)
		printf("Error in line creation (line does not exist)\n");
	if (BUFFER_SIZE <= 0)
		printf("Error in BUFFER_SIZE, value smaller than 0\n");
	else
		printf("Error in reading file or a Malloc function\n");
}

int	main()
{
	char	*text;
	int		fd;
	int		count;
	int		return_value;

	return_value = 1;
	count = 1;
	fd = open("Shrek", O_RDONLY);
	if (fd < 0)
	{
		printf("Something went wrong with opening the file\n");
		return (-1);
	}
	while (return_value != 0)
	{
		return_value = get_next_line(fd, &text);
		if (return_value == -1)
		{
			print_error(fd, &text);
			break;
		}
		printf("%i: %s\n", count, text);
		count++;
		free(text);
	}
	close(fd);
	return (0);
}
