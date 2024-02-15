/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moamzil <moamzil@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 16:51:31 by moamzil           #+#    #+#             */
/*   Updated: 2022/10/23 17:49:41 by moamzil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	nbr_len(long n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

size_t	which_nbr(long n, size_t d)
{
	size_t	i;

	i = 1;
	while (i < d)
	{
		n /= 10;
		i++;
	}
	return (n);
}

char	*set_nbr(long nb, int i, size_t len, char *result)
{
	while (len > 0)
	{
		result[i] = which_nbr(nb, len) % 10 + 48;
		len--;
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	size_t	len;
	char	*result;

	i = 0;
	nb = n;
	len = nbr_len(nb);
	result = malloc(len * sizeof(char) + 1);
	if (!result)
		return (NULL);
	if (nb < 0)
	{
		result[i] = '-';
		nb *= -1;
		len--;
		i++;
	}
	set_nbr(nb, i, len, result);
	return (result);
}
