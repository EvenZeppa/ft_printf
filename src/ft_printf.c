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
	// int		count;

	va_start(args, str);
	s_format	*format;
	format = init_format(&str);
	printf("PLS = %s", str);
	// count = 0;
	// while (TRUE)
	// {
	// 	if (process_buffer(str, args) == -1)
	// 		break;
	// }
	va_end(args);
	return (0);
}
