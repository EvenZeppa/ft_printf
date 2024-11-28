/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:23:08 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/29 00:30:50 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "structs.h"
# include "defs.h"
# include "utils.h"

int			ft_printf(const char *format, ...);

t_format	*init_format(const char **ptr);

int			print_c(t_format *format, char c);
int			print_s(t_format *format, char *str);
int			print_p(t_format *format, void *ptr);
int			print_d_i(t_format *format, int nb);
int			print_u(t_format *format, unsigned int nb);
int			print_x(t_format *format, unsigned long nb, int is_upper);

char		*formatted_width_minus_zero(
				char *str, int width, int has_minus, int has_zero);
char		*formatted_number_precision(
				char *str, int precision, int has_plus, int has_space);

#endif
