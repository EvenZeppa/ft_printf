/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:48:56 by marvin            #+#    #+#             */
/*   Updated: 2024/11/28 21:04:35 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	print_c(s_format *format, char c)
{
	int	count;

	count = 0;
	if (format->flag_minus)
		count += ft_putchar(c);
	if (format->width)
		while (count < format->width - (!format->flag_minus))
			count += ft_putchar(' ');
	if (!format->flag_minus)
		count += ft_putchar(c);
	return (count);
}

int	print_s(s_format *format, char *str)
{
	char	*res;
	int		count;
	int		size;

	if (!str && format->precision == -1)
		size = 7;
	else if (format->precision != -1 && format->precision < (int)ft_strlen(str))
		size = format->precision;
	else
		size = ft_strlen(str) + 1;
	res = malloc(sizeof(char) * size);
	if (!str && format->precision == -1)
		ft_strlcpy(res, "(null)", (size + 1));
	else
		ft_strlcpy(res, str, (size + 1));
	res = formatted_width_minus_zero(res, format->width, format->flag_minus, 0);
	count = ft_putstr(res);
	return (free(res), count);
}

int	print_d_i(s_format *format, int nb)
{
	char	*res;
	int		count;

	if (nb == 0 && format->precision == 0)
		return (0);
	res = ft_itoa(nb);
	if (format->flag_zero && format->width > (int)ft_strlen(res))
	{
		res = formatted_number_precision(&res[nb < 0], format->width, 0, 0);
		if (nb < 0)
			res[0] = '-';
	}
	res = formatted_number_precision(res, format->precision, format->flag_plus, format->flag_space);
	if (format->width > (int)ft_strlen(res))
		res = formatted_width_minus_zero(res, format->width, format->flag_minus, format->flag_zero);
	count = ft_putstr(res);
	return (free(res), count);
}
