/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:47:58 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/23 18:52:42 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;
	size_t	len_src;
	size_t	len_dest;

	len_src = 0;
	len_dest = 0;
	i = 0;
	while (src[len_src])
		len_src++;
	if (dstsize == 0)
		return (len_src);
	while (dst[len_dest])
		len_dest++;
	if (len_dest >= dstsize)
		return (dstsize + len_src);
	len = len_dest;
	while (len < dstsize - 1 && src[i])
	{
		dst[len] = src[i];
		len++;
		i++;
	}
	dst[len] = '\0';
	return (len_src + len_dest);
}
