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

int	ft_format_hex(unsigned int nbr, char specifier)
{
	char	*number;
	int		len_hex;

	number = ft_convert_nbr(nbr, 16);
	len_hex = ft_strlen(number) + 1;
	if (specifier == 'X')
		while (len_hex--)
			number[len_hex] = ft_toupper(number[len_hex]);
	len_hex = ft_putstr_fd(number, 1);
	free(number);
	return (len_hex);
}

int	ft_format_ptr(uintptr_t ptr)
{
	char	*number;
	int		len;

	len = ft_putstr_fd("0x", 1);
	number = ft_convert_nbr(ptr, 16);
	len += ft_putstr_fd(number, 1);
	if (number)
		free(number);
	return (len);
}

int	ft_format_u(unsigned int nb)
{
	char	*number;
	int		len;

	if (nb == 0)
		return (ft_putchar_fd('0', 1));
	number = ft_convert_nbr(nb, 10);
	len = ft_putstr_fd(number, 1);
	free (number);
	return (len);
}

static	int	ft_specifier(va_list args, char specifier)
{
	int	len_printed;

	len_printed = 0;
	if (specifier == 'c')
		len_printed += ft_putchar_fd(va_arg(args, int), 1);
	else if (specifier == 's')
		len_printed += ft_putstr_fd(va_arg(args, char *), 1);
	else if (specifier == 'd' || specifier == 'i')
		len_printed += ft_putnbr_fd(va_arg(args, int), 1);
	else if (specifier == 'u')
		return (ft_format_u(va_arg(args, unsigned int)));
	else if (specifier == 'p')
		return (ft_format_ptr(va_arg(args, unsigned long long)));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_format_hex(va_arg(args, unsigned int), specifier));
	else if (specifier == '%')
		return (ft_putchar_fd('%', 1));
	return (len_printed);
}

int	ft_printf(const char *s, ...)
{
	int		index;
	int		len_printed;
	va_list	args;

	index = 0;
	len_printed = 0;
	va_start(args, s);
	if (!s)
		return (0);
	while (s[index])
	{
		if (s[index] != '%')
			len_printed += ft_putchar_fd(s[index], 1);
		else if (s[index] == '%')
		{
			index++;
			len_printed += ft_specifier(args, s[index]);
		}
		index++;
	}
	va_end(args);
	return (len_printed);
}
