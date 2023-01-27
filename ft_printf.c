/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 19:09:25 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/18 19:09:25 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

int ft_specifier(va_list args, const char specifier)
{
    int len_printed;

    len_printed = 0;
    if(specifier == 'c')
        len_printed += ft_putchar_fd(va_arg(args, int), 1);
    else if(specifier == 'd' || specifier == 'i')
        len_printed += ft_putnbr_fd(va_arg(args, int), 1);
    else if(specifier == 'u')
        len_printed += ft_format_u(va_arg(args, unsigned int));
    else if(specifier == 's')
        len_printed += ft_putstr_fd(va_arg(args, char *), 1);
    else if(specifier == 'p') //a revoir
       len_printed += ft_format_ptr(va_arg(args, unsigned long long));
    else if (specifier == 'x' || specifier == 'X')
        return(ft_format_hex(va_arg(args, unsigned int), specifier));
    else if (specifier == '%')
        len_printed += ft_putchar_fd('%', 1);
    return(len_printed);
}

int ft_printf(const char *s, ...)
{
    int index;
    int len_printed;
    va_list args;
    va_start(args, s);
    
    index = 0;
    len_printed = 0;
    while(s && s[index])
    {
        if (s[index] != '%')
            ft_putchar_fd(s[index], 1);
        else if (s[index] == '%')
        {
            index++;
            len_printed +=ft_specifier(args, s[index]);
        }
        index++;
    }
    va_end(args);
    return (len_printed);
}

int main()
{
    int a = 1000;
    int b = -13;
    int *ptr = &a;

    printf("Hello\n");
    ft_printf("Hello\n");
    printf("%%\n");
    ft_printf("%%\n");
    printf("%c\n", 65);
    ft_printf("%c\n", 65);
    printf("%d\n", 65);
    ft_printf("%d\n", 65);
    printf("%i\n", 45);
    ft_printf("%i\n", 45);
    printf("%s\n", "HELLO");
    ft_printf("%s\n", "HELLO");
    printf("%u\n", a);
    ft_printf("%u\n", a);
    printf("%u\n", b);
    ft_printf("%u\n", b);
    printf("%p\n", ptr);
    ft_printf("%p\n", ptr);
}