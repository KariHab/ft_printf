

#include "ft_printf.h"

//modified for base 16
static int	get_size_hexa(int n)
{
	int	size;

	size = 1;
	while (n != 0)
	{
		n = n / 16;
		size++;
	}
	return (size);
}

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

int ft_print_hex(unsigned nb, const char specifier)
{
    char *number;

    number = ft_hexitoa(nb);
    if (specifier == 'X')
        number = ft_toupper(number);
    return(ft_putstr_fd(number,1));
    free(number);
}