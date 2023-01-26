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

static int ft_specifier(va_list args, const char specifier)
{
    if(specifier == 'c')
        return(ft_putchar_fd(va_arg(args, int), 1));
    else if(specifier == 'd' || specifier == 'i')
        return(ft_putnbr_fd(va_arg(args, int), 1));
    else if(specifier == 'u')
        return(ft_print_unsigned(va_arg(args, unsigned int)));
    else if(specifier == 's')
        {
            if (!va_arg(args, char *))
                return(ft_putstr_fd("(null)", 1));
            return(ft_putstr_fd(va_arg(args, char *), 1));
        }
        //a revoir
    else if(specifier == 'p')
        return(ft_putchar_fd(va_arg(args, unsigned long long), 1));
        //a revoir
    else if (specifier == 'x' || specifier == 'X')
        return(ft_putchar_fd(va_arg(args, unsigned int), 1));
    else if (specifier == '%')
        return(ft_putchar_fd('%', 1));
    return(0);
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
            len_printed +=ft_specifier(args, s[index + 1]);
        index++;
    }
    va_end(args);
    return (len_printed);
}



    
      