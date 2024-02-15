/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:11:32 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/03 16:12:35 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	a;
	unsigned char	*str;

	i = 0;
	a = c;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == a)
			return (&((void *)s)[i]);
		i++;
	}
	return (NULL);
}
