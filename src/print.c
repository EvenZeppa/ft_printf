/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:48:56 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 01:48:56 by marvin           ###   ########.fr       */
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

	if (format->precision != -1 && format->precision < (int)ft_strlen(str))
	{
		res = malloc(sizeof(char) * (format->precision));
		ft_strlcpy(res, str, (format->precision + 1));
		str = res;
	}
	res = formatted_width_minus_zero(str, format->width, format->flag_minus, 0);
	count = ft_putstr(res);
	return (free(res), count);
}

int	print_d_i(s_format *format, int nb)
{
	char	*res;
	int		count;

	res = ft_itoa(nb);
	res = formatted_number_precision(res, format->precision, format->flag_plus, format->flag_space);
	if (format->width > (int)ft_strlen(res))
		res = formatted_width_minus_zero(res, format->width, format->flag_minus, format->flag_zero);
	count = ft_putstr(res);
	return (free(res), count);
}
