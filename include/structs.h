/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:23:06 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/29 00:09:17 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_format
{
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_hash;
	int		flag_zero;
	int		width;
	int		precision;
	char	specifier;
}	t_format;

#endif
