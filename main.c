/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 13:27:56 by ahorling      #+#    #+#                 */
/*   Updated: 2021/04/27 14:12:04 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	char *text;
	int fd;
	int i;
	int size;

	text = (char *)calloc(size, sizeof(char));
	i = 0;
	size = 100;
	fd = open("testfile.txt", O_RDONLY);
	if (fd < 0 || !fd)
		return(printf("Error occoured during file opening"));
	i = read(fd, text, size);
	printf("read function should have read %d bytes, returned that %d bytes were read.\n", size, i);
	text[i] = '\0';
	printf("those bytes are: %s\n", text);
	return (0);
}