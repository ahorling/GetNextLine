/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/17 13:32:06 by ahorling      #+#    #+#                 */
/*   Updated: 2021/05/17 14:08:12 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		leng;
	char	*dupe;

	i = 0;
	leng = 0;
	while (str[i] != '\0')
	{
		leng++;
		i++;
	}
	i = 0;
	dupe = (char *)malloc((leng + 1) * sizeof(char));
	if (dupe == NULL)
		return (NULL);
	while (str[i] != '\0')
	{
		dupe[i] = str[i];
		i++;
	}
	dupe[i] = '\0';
	return (dupe);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fullstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	fullstr = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
	fullstr[i + j] = '\0';
	return (fullstr);
}

char	*add_to_buffer(char *buffer, char *filler)
{
	char	*new_buffer;

	if (!buffer && !filler)
		return (NULL);
	if (buffer == NULL)
		return (ft_strdup(filler));
	else
		new_buffer = ft_strjoin(buffer, filler);
	if (new_buffer == NULL)
		return (NULL);
	free(buffer);
	return (new_buffer);
}
