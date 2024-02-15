/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:20:01 by moamzil           #+#    #+#             */
/*   Updated: 2023/02/24 19:16:53 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*gnl_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	i;

	i = -1;
	ptr = malloc(count * size);
	if (!ptr)
		return (0);
	while (++i < size)
		((char *)ptr)[i] = 0;
	return (ptr);
}

char	*gnl_strjoin(char *buff, char *safe)
{
	int		i;
	int		j;
	char	*nsafe;

	i = 0;
	j = 0;
	if (!safe)
		safe = gnl_calloc(1, 1);
	nsafe = gnl_calloc(1, (gnl_strlen(safe, 1) + gnl_strlen(buff, 1) + 1));
	while (safe[i] != '\0')
	{
		nsafe[i] = safe[j];
		j++;
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
	{
		nsafe[i] = buff[j];
		j++;
		i++;
	}
	free(safe);
	return (nsafe);
}

char	*gnl_substr(char *safe)
{
	int		i;
	char	*line;
	int		len_to_nw;

	i = 0;
	len_to_nw = gnl_strlen_v2(safe);
	line = gnl_calloc(1, len_to_nw + 1);
	while (i < len_to_nw)
	{
		line[i] = safe[i];
		i++;
	}
	return (line);
}

size_t	gnl_strlen_v2(char *buff)
{
	int	i;

	i = 0;
	while (buff[i] != '\0')
	{
		if (buff[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	return (i);
}

size_t	gnl_strlen(char *buff, int option)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	if (!buff)
		buff = gnl_calloc(1, 1);
	if (!option)
	{
		if (gnl_strchr(buff, '\n'))
		{
			while (buff[i] && buff[i] != '\n')
				i++;
			i++;
		}
		while (buff[i++] != '\0')
			len++;
		return (len + 1);
	}
	else
		while (buff[i] != '\0')
			i++;
	return (i);
}
