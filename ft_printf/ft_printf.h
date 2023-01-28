/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khabbout <khabbout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 14:40:21 by khabbout          #+#    #+#             */
/*   Updated: 2023/01/28 14:40:21 by khabbout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
# define FT_PRINTF_H

// POUR AVOIR LES VA_TRUC
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
// int		ft_format_u(unsigned int nb);
// int		ft_format_ptr(uintptr_t ptr);
// int		ft_format_hex(unsigned int nbr, char specifier);
char	*ft_convert_nbr(unsigned long long nbr, int base);

#endif