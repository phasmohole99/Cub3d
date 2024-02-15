/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:36:27 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/23 18:48:51 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*str;

	i = -1;
	str = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!str)
		return (0);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
