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

#endif
