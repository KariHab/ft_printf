/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:37:59 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/26 12:37:59 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//modified for base 16
static int	get_size_ptr(uintptr_t n)
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
void	ft_get_ptr(uintptr_t nbr)
{
	if (nbr >=16)
	{
		ft_get_ptr(nbr /16);
		ft_get_ptr(nbr % 16);
	}
	else
	{
		if (nbr <=9)
			ft_putchar_fd((nbr + '0'), 1);
		else
			ft_putchar_fd((nbr - 10 + 'a'), 1);
	}
}

int ft_format_ptr(unsigned long long ptr)
{
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
		return(ft_putchar_fd('0', 1));
	else
    {
        ft_get_ptr(ptr);
        return(get_size_ptr(ptr));
    }
	return (0);
}