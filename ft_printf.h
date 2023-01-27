
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// POUR AVOIR LES VA_TRUC
#include <stdarg.h>
#include <stdio.h>
#include "libft/libft.h"
#include <unistd.h>


int         ft_printf(const char *s, ...);
int ft_format_u(unsigned int nb);
int ft_format_ptr(unsigned long long ptr);
int ft_format_hex(unsigned int nbr, const char specifier);

#endif