#include "minitalk.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

void	received(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Received: 1\n");
	else if (sig == SIGUSR2)
		ft_printf("Received: 0\n");
}

void	send_bit(int srv_pid, int c)
{
	static int	i = 1;

	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	if (c & i)
	{
		kill(srv_pid, SIGUSR1);
		i <<= 1;
	}
	else
	{
		kill(srv_pid, SIGUSR2);
		i <<= 1;
	}
	if (i < 256)
	{
		// pause();
		usleep(500);
		send_bit(srv_pid, c);
	}
	else
	{
		i = 1;
		return ;
	}
}

void	print_bit(int div)
{
	if (div > 2)
		print_bit(div / 2);
	ft_printf("%d", div % 2);
}

void	validation(int ac, char **av)
{
	size_t	i;

	if (ac != 3)
	{
		ft_printf("⚠️\tError: Wrong number of arguments.\n");
		ft_printf("❗\tUsage: ./client <PID> <string>\n");
		exit(22);
	}
	i = -1;
	while (av[1][++i])
	{
		if (!ft_isdigit(av[1][i]))
		{
			ft_printf("⚠️\tError: PID is invalid.\n");
			ft_printf("🔢\tA PID only has decimal numbers.\n");
			exit(22);
		}
	}
}

int	main(int ac, char **av)
{
	size_t	i;
	int		srv_pid;

	validation(ac, av);
	srv_pid = ft_atoi(av[1]);
	i = -1;
	while (av[2][++i])
	{
		print_bit((int)av[2][i]);
		ft_printf("\n%c\n", av[2][i]);
		send_bit(srv_pid, (int)av[2][i]);
	}
}
