/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:15:57 by moamzil           #+#    #+#             */
/*   Updated: 2023/02/20 14:54:40 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strchr(char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		s = gnl_calloc(1, 1);
	while ((char)c != s[++i])
		if (!s[i])
			return (0);
	return (1);
}

char	*keep_aftr_nw(char *safe)
{
	int		i;
	int		j;
	char	*nsafe;

	i = 0;
	j = -1;
	nsafe = gnl_calloc(1, gnl_strlen(safe, 0));
	if (!gnl_strchr(safe, '\n'))
	{
		free(nsafe);
		free(safe);
		nsafe = 0;
		return (0);
	}
	if (gnl_strchr(safe, '\n'))
	{
		while (safe[i] != '\n' && safe[i])
			i++;
		i++;
	}
	while (safe[i])
		nsafe[++j] = safe[i++];
	free(safe);
	return (nsafe);
}

char	*get_next_line(int fd)
{
	static char	*safe;
	ssize_t		i;
	char		buff[BUFFER_SIZE + 1];
	char		*line;

	i = 1;
	buff[0] = '\0';
	while (i > 0 && !gnl_strchr(buff, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i == -1)
			break ;
		buff[i] = 0;
		safe = gnl_strjoin(buff, safe);
	}
	if (i == -1 || safe[0] == '\0' || fd < 0 || BUFFER_SIZE <= 0)
	{
		free(safe);
		safe = 0;
		return (0);
	}
	line = gnl_substr(safe);
	safe = keep_aftr_nw(safe);
	return (line);
}
