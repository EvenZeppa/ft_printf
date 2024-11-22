/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:56:32 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 11:56:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	hexa_size(unsigned long long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		nb = 1;
	while (nb > 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}

char	*convert_to_hexa(unsigned long long nb, char *base)
{
	char	*res;
	int		size;

	size = hexa_size(nb);
	res = malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	res[size] = '\0';
	while (size > 0)
	{
		size--;
		res[size] = base[(nb % 16) - 1];
		nb /= 16;
	}
	return (res);
}

static int	int_size(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_recursive(char *s, int n, int i)
{
	if (n < 0)
	{
		s[0] = '-';
		n = -n;
	}
	if (n > 9)
	{
		ft_recursive(s, n / 10, i - 1);
		s[i] = (n % 10) + '0';
	}
	else
		s[i] = n + '0';
}

char	*ft_itoa(int n)
{
	char	*ptr;

	if (n == -2147483648)
	{
		ptr = malloc(sizeof(char) * 12);
		if (!ptr)
			return (ptr);
		ft_strlcpy(ptr, "-2147483648", 12);
		return (ptr);
	}
	ptr = malloc(sizeof(char) * (int_size(n) + 1));
	if (!ptr)
		return (NULL);
	ft_recursive(ptr, n, (int_size(n) - 1));
	ptr[int_size(n)] = '\0';
	return (ptr);
}