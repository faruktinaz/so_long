/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:16:04 by ogenc             #+#    #+#             */
/*   Updated: 2023/03/20 20:01:51 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strleng(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strleng(s1) + ft_strleng(s2) + 1));
	len = -1;
	i = 0;
	while (s1[++len])
		str[len] = s1[len];
	while (s2[i])
		str[len++] = s2[i++];
	str[len] = '\0';
	free (s1);
	return (str);
}

int	ft_checknewline(char *buffer)
{
	int	i;

	i = -1;
	if (!buffer)
		return (0);
	while (buffer[++i])
		if (buffer[i] == '\n')
			return (1);
	return (0);
}

char	*ft_newline(char *buffer)
{
	char	*line;
	int		i;
	int		nl;

	nl = ft_checknewline(buffer);
	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + nl + 1));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*new_buffer(char *buffer)
{
	char	*nbuffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free (buffer);
		return (NULL);
	}
	nbuffer = malloc (sizeof(char) * (ft_strleng(buffer) - i + 1));
	if (!nbuffer)
		return (NULL);
	i++;
	while (buffer[i])
		nbuffer[j++] = buffer[i++];
	nbuffer[j] = 0;
	free (buffer);
	return (nbuffer);
}
