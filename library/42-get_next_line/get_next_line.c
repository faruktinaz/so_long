/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:15:59 by ogenc             #+#    #+#             */
/*   Updated: 2023/03/20 20:28:48 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(int fd, char *buffer)
{
	char	*buf;
	int		rdbyte;

	rdbyte = 1;
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (!ft_checknewline(buffer) && rdbyte != 0)
	{
		rdbyte = read(fd, buf, BUFFER_SIZE);
		if (rdbyte == -1)
		{
			free(buffer);
			free(buf);
			return (NULL);
		}
		buf[rdbyte] = '\0';
		buffer = ft_strjoin(buffer, buf);
	}
	free(buf);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = read_line(fd, buffer);
	if (buffer == NULL)
		return (NULL);
	line = ft_newline(buffer);
	buffer = new_buffer(buffer);
	return (line);
}
