/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:21:42 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/28 20:53:26 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	process_arg(const char **str, va_list *args)
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
		count = print_s(format, va_arg(*args, char *));
	else if (format->specifier == 'p')
		count = print_p(format, va_arg(*args, void *));
	else if (format->specifier == 'd' || format->specifier == 'i')
		count = print_d_i(format, va_arg(*args, int));
	else if (format->specifier == 'u')
		count = print_u(format, (unsigned int)va_arg(*args, unsigned int));
	else if (format->specifier == 'x')
		count = print_x(format, va_arg(*args, unsigned int), FALSE);
	else if (format->specifier == 'X')
		count = print_x(format, va_arg(*args, unsigned int), TRUE);
	else if (format->specifier == '%')
		count = ft_putchar('%');

	return (free(format), count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += process_arg(&str, &args);
		}
		else
		{
			count += ft_putchar(*str);
			str++;
		}
	}
	va_end(args);
	return (count);
}
