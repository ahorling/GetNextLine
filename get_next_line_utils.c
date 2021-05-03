/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 15:21:01 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/03 12:21:26 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (str[i] != '\0')
	{
		length++;
		i++;
	}
	return (length);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	srclen;

	if (dest == NULL || src == NULL)
		return (0);
	srclen = ft_strlen(src);
	if (srclen < size)
		ft_memcpy(dest, src, (srclen + 1));
	else if (size != 0)
	{
		ft_memcpy(dest, src, size - 1);
		dest[size - 1] = '\0';
	}
	return (srclen);
}

char	*ft_fill_empty(char *src, size_t length)
{
	char	*str;

	length++;
	str = (char *)malloc(length)(sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, src, length);
	return (str);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	size_t	i;
	char	*output;
	char	*input;

	i = 0;
	output = (char *)dest;
	input = (char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < size)
	{
		output[i] = input[i];
		i++;
	}
	return (dest);
}

char	*ft_buffer_add(char const *s1, char const *s2)
{
	char	*fullstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_fill_empty(s2, ft_strlen(s2)));
	fullstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2));
	if (fullstr == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		fullstr[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		fullstr[i + j] = s2[j];
		j++;
	}
	return (fullstr);
}
