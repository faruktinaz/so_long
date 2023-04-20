/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogenc <ogenc@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:31:54 by ogenc             #+#    #+#             */
/*   Updated: 2023/04/15 13:47:39 by ogenc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long_bonus.h"

void	*ft_memset(void *dst, int src, size_t n)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)dst;
	while (i < n)
	{
		str[i] = src;
		i++;
	}
	return (dst);
}

void	ft_bzero(void *dst, size_t len)
{
	ft_memset(dst, 0, len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ret;

	ret = malloc(size * count);
	if (!ret)
		return (NULL);
	ft_bzero(ret, size * count);
	return (ret);
}
