/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:27:56 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/03 15:52:10 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	print_error(int fd, char **line)
{
	if (fd < 0)
		printf("Error in file opening\n");
	if (!line)
		printf("Error in line creation (line does not exist)\n");
	if (BUFFER_SIZE < 0)
		printf("Error in BUFFER_SIZE, value smaller than 0\n");
	else
		printf("Error in reading file or a Malloc function\n");
}

int	main()
{
	char	*text;
	int		fd;
	int		count;

	count = 1;
	fd = open("testfile.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Something went wrong with opening the file\n");
		return (-1);
	}
	while (get_next_line(fd, &text) == 1)
	{	
	//	printf("get next line finished successfully, this is the first line of the file:\n");
		printf("%d: %s\n", count, text);
		count++;
	}
	if (get_next_line(fd, &text) == -1)
	{
		print_error(fd, &text);
		return (-1);
	}
	close(fd);
	return (0);
}
