/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 01:48:52 by marvin            #+#    #+#             */
/*   Updated: 2024/11/22 01:48:52 by marvin           ###   ########.fr       */
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
	(void) format;
	(void) nb;
	(void) is_upper;
	return (0);
}

int	print_p(s_format *format, void *ptr)
{
	(void) format;
	(void) ptr;
	return (0);
}