



#include "ft_printf.h"

/*modified itoa for hexadecimal*/
char	*ft_hexitoa(unsigned long long nbr)
{
	char		*tmp;
	int			size;
	long int	nb;

	size = get_size_hexa(nbr);
    if (nbr == 0)
		size++;
	tmp = ft_calloc(size + 1, (sizeof(char)));
	if (!tmp)
		return (NULL);
	while (nbr)
	{
		tmp[size - 1] = nbr % 16 + '0';
		nbr = (nbr / 16);
		size--;
	}
	return (tmp);
}

int ft_print_hex(unsigned long long ptr, const char specifier)
{
	ft_putchar_fd("0x", 1);
	if (ptr == 0)
		return(ft_putchar_fd("0", 1));
	else
	    return (ft_hexitoa(ptr));
}