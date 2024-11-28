/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:48:52 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 21:14:14 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_u(s_format *format, unsigned int nb)
{
	char	*res;
	int		count;

	res = ft_itoa(nb);
	res = formatted_number_precision(res, format->precision, 0, 0);
	if (format->width > (int)ft_strlen(res))
		res = formatted_width_minus_zero(res, format->width, format->flag_minus, format->flag_zero);
	count = ft_putstr(res);
	return (free(res), count);
}

int	print_x(s_format *format, unsigned long nb, int is_upper)
{
	char	*res;
	int		count;

	if (is_upper)
		res = convert_to_hexa(nb, "0123456789ABCDEF");
	else
		res = convert_to_hexa(nb, "0123456789abcdef");
	res = formatted_number_precision(res, format->precision, 0, 0);
	if (format->flag_hash && is_upper)
		res = ft_strjoin("0X", res);
	else if (format->flag_hash)
		res = ft_strjoin("0x", res);
	res = formatted_width_minus_zero(res, format->width, format->flag_minus, format->flag_zero);
	count = ft_putstr(res);
	return (free(res) , count);
}

int	print_p(s_format *format, void *ptr)
{
	char				*res;
	unsigned long long	tmp;
	int					count;

	if (!ptr)
		res = ft_strdup("(nil)");
	else
	{
		tmp = (unsigned long long)ptr;
		res = convert_to_hexa(tmp, "0123456789abcdef");
		res = ft_strjoin("0x", res);
	}
	res = formatted_width_minus_zero(res, format->width, format->flag_minus, 0);
	count = ft_putstr(res);
	return (free(res) , count);
}
