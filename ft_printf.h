
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// POUR AVOIR LES VA_TRUC
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"


int         ft_printf(const char *s, ...);
static int  ft_specifier(va_list args, const char specifier)
static int	get_size(int n)
static int	get_size_hexa(int n)
char	    *ft_uitoa(unsigned int nbr)
int         ft_print_unsigned(unsigned nb)
char	    *ft_hexitoa(unsigned long long nbr)
int         ft_print_hex(unsigned nb, const char specifier)

#endif