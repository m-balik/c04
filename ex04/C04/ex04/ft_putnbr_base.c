#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i])
	{
		j = i + 1;
		

		if (base[i] == '+' || base[i] == '-'
			|| base[i] < 32 || base[i] > 126)
			return (0);


		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	// If there is no problem, the return is 1
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	box[32];
	long	n;
	int		size;
	int		i;


	if (!ft_check_base(base))
		return ;
	
	// counts the size of the base
	size = ft_strlen(base);

	// long n avoid the issues with the int min
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
	}
	i = 0;

	while (n > 0)
	{
		// Array Box receives the converted values of 'n' to the base
		// This formula of 'n' module size will find the correct number at the base
		box[i] = base[n % size];
		n = n / size;
		i++;
	}

	// The values stored in box were reversed
	// This repetition will print what is in the box
	// starting from last position to the first
	while (--i >= 0)
		ft_putchar(box[i]);
}
