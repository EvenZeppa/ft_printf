/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:21:42 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/21 19:34:51 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;

	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += process_arg(&str, &args);
		}
		else
			count += ft_putchar(*str);
		str++;
	}	
	va_end(args);
	return (count);
}
