/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:06:41 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/28 16:24:58 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_size(unsigned long long n, int base)
{
	int	size;

	size = 0;
	while (n)
	{
		n /= base;
		size++;
	}
	return (size);
}

/*modified itoa for unsigned, hex and ptr*/
char	*ft_convert_nbr(unsigned long long nbr, int base)
{
	char	*tmp;
	int		size;

	size = get_size(nbr, base);
	tmp = ft_calloc(size + 1, (sizeof(char)));
	if (nbr == 0)
		size++;
	if (!tmp)
		return (NULL);
	while (nbr)
	{
		tmp[size - 1] = nbr % base + '0';
		nbr = (nbr / base);
		size--;
	}
	return (tmp);
}
