/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:26:52 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/21 18:47:21 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	check_format(s_format *format)
{
	(void) format;
	return (1);
}

int	process_arg(const char **str, va_list *args)
{
	s_format	*format;
	int			count;

	format = init_format(str);
	if (!format)
		return (1);
	count = 0;
	if (format->specifier == 'c')
		count = print_c(format, (char)va_arg(*args, int));
	else if (format->specifier == 's')
		count = print_s(format, va_arg(*args, char*));
	else if (format->specifier == 'p')
		count = print_p(format, va_arg(*args, void*));
	else if (format->specifier == 'd' || format->specifier == 'i')
		count = print_d_i(format, va_arg(*args, int));
	else if (format->specifier == 'u')
		count = print_u(format, (unsigned int)va_arg(*args, long));
	else if (format->specifier == 'x')
		count = print_x(format, va_arg(*args, int), FALSE);
	else if (format->specifier == 'X')
		count = print_x(format, va_arg(*args, int), TRUE);
	else if (format->specifier == '%')
		count = print_percent(format, va_arg(*args, char));
	return (free(format), count);
}
