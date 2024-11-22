/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:39:22 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/21 20:02:23 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static int	add_flags(s_format *format, const char *ptr)
{
	int	i;

	i = 0;
	while(TRUE)
	{
		if (ptr[i] == FLAG_MINUS)
			format->flag_minus = TRUE;
		else if (ptr[i] == FLAG_PLUS)
			format->flag_plus = TRUE;
		else if (ptr[i] == FLAG_SPACE)
			format->flag_space = TRUE;
		else if (ptr[i] == FLAG_HASH)
			format->flag_hash = TRUE;
		else if (ptr[i] == FLAG_ZERO)
			format->flag_zero = TRUE;
		else
			return (i);
		i++;
	}
	return (i);
}

static int	add_width(s_format *format, const char *ptr)
{
	int	nb;
	int count;

	nb = ft_atoi(ptr);
	if (!nb && *ptr != '0')
		return (0);
	format->width = nb;
	count = 0;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	add_precision(s_format *format, const char *ptr)
{
	int	nb;
	int count;

	if (*ptr != '.')
		return (0);
	ptr++;
	nb = ft_atoi(ptr);
	format->precision = nb;
	count = 1;
	if (nb == 0)
		count++;
	while (nb > 0)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static int	add_specifier(s_format *format, const char *ptr)
{
	if (*ptr != 'c'
		&& *ptr != 's'
		&& *ptr != 'p'
		&& *ptr != 'd'
		&& *ptr != 'i'
		&& *ptr != 'u'
		&& *ptr != 'x'
		&& *ptr != 'X'
		&& *ptr != '%')
		return (0);
	format->specifier = *ptr;
	return (1);
}

s_format	*init_format(const char **ptr)
{
	s_format	*format;

	format = malloc(sizeof(s_format));
	if (!format)
		return (NULL);
	format->flag_minus = FALSE;
	format->flag_plus = FALSE;
	format->flag_space = FALSE;
	format->flag_hash = FALSE;
	format->flag_zero = FALSE;
	format->width = FALSE;
	format->precision = -1;
	format->specifier = 0;
	*ptr += add_flags(format, *ptr);
	*ptr += add_width(format, *ptr);
	*ptr += add_precision(format, *ptr);
	*ptr += add_specifier(format, *ptr);

	// printf(
	// 	"Flag minus = %d\n"
	// 	"Flag plus = %d\n"
	// 	"Flag space = %d\n"
	// 	"Flag hash = %d\n"
	// 	"Flag zero = %d\n"
	// 	"Width = %d\n"
	// 	"Precision = %d\n"
	// 	"Specifier = %c\n",
	// 	format->flag_minus,
	// 	format->flag_plus,
	// 	format->flag_space,
	// 	format->flag_hash,
	// 	format->flag_zero,
	// 	format->width,
	// 	format->precision,
	// 	format->specifier
	// );
	return (format);
}
