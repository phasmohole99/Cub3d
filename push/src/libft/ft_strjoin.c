/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:55:45 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/21 20:04:57 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	len;
	size_t	i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	news = malloc(len * sizeof(char) + 1);
	if (!news)
		return (NULL);
	while (i < len && s1[i])
		news[j++] = s1[i++];
	i = 0;
	while (i < len && s2[i])
		news[j++] = s2[i++];
	news[j] = 0;
	return (news);
}
