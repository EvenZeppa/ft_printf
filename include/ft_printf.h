/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:23:08 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/21 19:46:25 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "structs.h"
#include "defs.h"
#include "utils.h"

#include <stdio.h> // TODO : Remove

int	ft_printf(const char *format, ...);

int	process_arg(const char **str, va_list *args);

s_format	*init_format(const char **ptr);

int	print_c(s_format *format, char c);
int	print_s(s_format *format, char *str);
int	print_p(s_format *format, void *ptr);
int	print_d_i(s_format *format, int nb);
int	print_u(s_format *format, unsigned int nb);
int	print_x(s_format *format, unsigned long nb, int is_upper);

char	*formatted_width_minus_zero(char *str, int width, int has_minus, int has_zero);
char	*formatted_number_precision(char *str, int precision, int has_plus, int has_space);

#endif
