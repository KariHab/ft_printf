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

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

int		ft_printf(const char *s, ...);
int		ft_printu(unsigned int nb);
int		ft_printptr(uintptr_t ptr);
int		ft_printhex(unsigned int nbr, char specifier);

#endif