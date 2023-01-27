/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:38:03 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/26 12:38:03 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static int	get_size(unsigned int n)
{
	int	size;

	size = 0;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

/*modified itoa for unsigned*/
char	*ft_uitoa(unsigned int nbr)
{
	char		*tmp;
	int			size;

	size = get_size(nbr);
	tmp = ft_calloc(size + 1, (sizeof(char)));
	if (tmp == NULL)
		return (NULL);
	while (nbr)
	{
		tmp[size - 1] = nbr % 10 + '0';
		nbr = (nbr / 10);
		size--;
	}
	return (tmp);
}

int ft_format_u(unsigned nb)
{
    char *number;

    if (nb == 0)
        return(ft_putchar_fd('0', 1));
    else
    {
		number = ft_uitoa(nb);
		if(!number)
			return (0);
		return(ft_putstr_fd(number,1));
        free(number);
    }
	return (0);
}