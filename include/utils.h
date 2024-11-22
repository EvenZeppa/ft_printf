/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:44:28 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/21 19:45:14 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

size_t	ft_strlen(const char *s);
int		ft_putchar(char c);
int		ft_putstr(char *str);
void	*ft_memset(void *s, int c, size_t n);
char	*convert_to_hexa(unsigned long long nb, char *base);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
int		ft_atoi(const char *nptr);
char	*ft_itoa(int n);

#endif
