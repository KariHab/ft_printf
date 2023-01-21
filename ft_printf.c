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


// il faut enregister dans un buffer sur quoi le str tomber 
// il faut checker le % savoir ce que c' est comme type
// il faut printer le buffer temporaire une fois arrivee a la fin de la chaine 
//
//as long as I do not have any % just print the char
#include "ft_printf.h"


int ft_printf(const char *s, ...)
{

    va_list args;
    va_start(args, s);
    char *str_arg;
    int i;


    i = 0;
    while(s[i])
    {
        if (s[i] == '%')
        {
            if (s[i] == 'c')
            {
                str_arg = va_arg(args, char *);
                write (1, 1, 1);
                i++;
            }
            else if (s[i] == 'd')
            {
                //use strlcpy & itoa
                str_arg = va_arg(args, int);
                write (1, 1, 1);
                i++;
            }
                
        }
        else
        {
            write(1, &s[i], 1);
        }
    return(i);
    }
}

int main ()
{
    ft_printf("truc");
    return (0);
}