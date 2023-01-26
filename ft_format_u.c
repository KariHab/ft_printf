


#include "ft_printf.h"

static int	get_size(int n)
{
	int	size;

	size = 1;
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
	long int	nb;

	size = get_size(nbr);
	tmp = ft_calloc(size + 1, (sizeof(char)));
	if (tmp == NULL)
		return (NULL);
	nb = nbr;
	if (nb == 0)
		tmp[0] = '0';
	while (nb)
	{
		tmp[size - 1] = nb % 10 + '0';
		nb = (nb / 10);
		size--;
	}
	return (tmp);
}

int ft_print_unsigned(unsigned nb)
{
    char *number;

    if (nb == 0)
        return(ft_putchar_fd("0", 1));
    else
    {
        number = ft_uitoa(nb);
        return(ft_putstr_fd(number,1));
        free(number);
    }
    return(0);
}