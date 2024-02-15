/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:41:19 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/24 03:52:55 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_word_cnt(char const *s, char c)
{
	size_t	cnt;
	size_t	i;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if ((i == 0 && s[i] != c)
			|| (s[i] == c && s[i + 1] != '\0' && s[i + 1] != c))
			cnt++;
		i++;
	}
	return (cnt);
}

void	ft_strcpy_split(char *dst, char *from, char const *strcp)
{
	while (from < strcp)
		*(dst++) = *(from++);
	*dst = '\0';
}

char	**ft_split(char const *str, char c)
{
	char			**res;
	unsigned int	i;
	char			*from;

	res = (char **)malloc(sizeof(char *) * (ft_word_cnt(str, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*str)
	{
		if (*str++ == c)
			continue ;
		from = (char *)str - 1;
		while (*str && *str != c)
			str++;
		res[i] = (char *)malloc(sizeof(char) * (str - from + 1));
		if (!(res[i]))
			return (NULL);
		ft_strcpy_split(res[i++], from, str);
	}
	res[i] = NULL;
	return (res);
}
