/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ahorling <ahorling@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/04/27 15:21:01 by ahorling      #+#    #+#                 */
/*   Updated: 2021/04/27 15:46:47 by ahorling      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_buffer_add(char const *s1, char const *s2)
{
	char	*fullstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
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
