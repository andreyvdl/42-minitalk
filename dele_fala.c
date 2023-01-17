#include "minitalk.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

void	send_bit(int pid, char c)
{
	if (c & 1)
		kill(pid, SIGUSR1);
	else
		kill(pid, SIGUSR2);
}

void	print_bit(int div)
{
	if (div > 2)
		print_bit(div / 2);
	ft_printf("%d", div % 2);
}

int	main(int ac, char **av)
{
	size_t	i;
	int		pid;
	int		bit;

	if (ac != 3)
	{
		ft_printf("Error\nUsage ./client <pid> <message>\n");
		exit(22);
	}
	pid = ft_atoi(av[1]);
	i = -1;
	while (av[2][++i])
	{
		print_bit((int)av[2][i]);
		bit = 0;
		while (bit < 8)
		{
			send_bit(pid, av[2][i]);
			av[2][i] >>= 1;
			bit++;
			usleep(800);
		}
	}
}
