/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:37:39 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/26 12:37:39 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

//modified for base 16
static int	get_size_hex(unsigned int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

//fonction pour aller recup la taille d'un pointeur
void	ft_get_hex(unsigned int nbr, const char specifier)
{
	if (nbr >=16)
	{
        ft_get_hex(nbr / 16, specifier);
        ft_get_hex(nbr % 16, specifier);
	}
	else
	{
		if (nbr <=9)
			ft_putchar_fd((nbr + '0'), 1);
		else
        {
            if (specifier == 'x')
			    ft_putchar_fd((nbr - 10 + 'a'), 1);
            else if (specifier == 'X')
                ft_putchar_fd((nbr - 10 + 'A'), 1);
        }

	}
}

int ft_format_hex(unsigned int nbr, const char specifier)
{

	if (nbr == 0)
		return(ft_putchar_fd('0', 1));
	else
        ft_get_hex(nbr, specifier);
    return (get_size_hex(nbr));
}