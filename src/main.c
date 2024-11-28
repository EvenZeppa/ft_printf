/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ezeppa <ezeppa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:01:25 by ezeppa            #+#    #+#             */
/*   Updated: 2024/11/28 21:07:54 by ezeppa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

#include <limits.h>

int main(void) {
    char c = 'A';
    char *s = "Hello, world!";
    void *p = (void *)0x12345678ABCDEF;
    int d = -42;
    int i = 42;
    unsigned int u = 123456;
    unsigned int x = 0xdeadbeef;
    unsigned int X = 0xDEADBEEF;

    // Test pour chaque format avec différents flags
    printf("Testing ft_printf with various formats and flags:\n\n");

	printf(" %p %p \n", 0, 0);
	ft_printf(" %p %p \n", 0, 0);

    // printf("Character (%%c):\n");
    // ft_printf("Normal: |%c|\n", c);
    // ft_printf("With '-': |%-c|\n", c);
    // printf("\n");

    // printf("String (%%s):\n");
    // ft_printf("Normal: |%s|\n", s);
    // ft_printf("With '-': |%-20s|\n", s);
    // ft_printf("With '.': |%.5s|\n", s);
    // printf("\n");

    // printf("Pointer (%%p):\n");
    // ft_printf("Normal: |%p|\n", p);
    // ft_printf("With '-': |%-20p|\n", p);
    // printf("\n");

    // printf("Integer (%%d):\n");
    // ft_printf("Normal: |%d|\n", d);
    // ft_printf("With '+': |%+d|\n", d);
    // ft_printf("With ' ': |% d|\n", d);
    // ft_printf("With '-': |%-10d|\n", d);
    // ft_printf("With '0': |%010d|\n", d);
    // printf("With '.': |%10.5d|\n", d);
    // ft_printf("With '.': |%10.5d|\n", d);
    // ft_printf("With '.0': |%.0d|\n", -213);
    // printf("\n");

    // printf("Integer (%%i):\n");
    // ft_printf("Normal: |%i|\n", i);
    // ft_printf("With '+': |%+i|\n", i);
    // ft_printf("With ' ': |% i|\n", i);
    // ft_printf("With '-': |%-10i|\n", i);
    // ft_printf("With '0': |%010i|\n", i);
    // printf("\n");

    // printf("Unsigned (%%u):\n");
    // ft_printf("Normal: |%u|\n", u);
    // ft_printf("With '-': |%-10u|\n", u);
    // ft_printf("With '0': |%010u|\n", u);
    // printf("\n");

    // printf("Hexadecimal (%%x):\n");
    // ft_printf("Normal: |%x|\n", x);
    // ft_printf("With '#': |%#x|\n", x);
    // ft_printf("With '-': |%-10x|\n", x);
    // ft_printf("With '0': |%010x|\n", x);
    // printf("\n");

    // printf("Hexadecimal (%%X):\n");
    // ft_printf("Normal: |%X|\n", X);
    // ft_printf("With '#': |%#X|\n", X);
    // ft_printf("With '-': |%-10X|\n", X);
    // ft_printf("With '0': |%010X|\n", X);
    // printf("\n");

    // printf("Percentage (%%%%):\n");
    // ft_printf("Normal: |%%|\n");
    // ft_printf("With '-': |%-10%%|\n");
    // printf("\n");

    return 0;
}

