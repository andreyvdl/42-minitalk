#include "minitalk.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

void print_bit(int c) {
    for (int i = 7; i >= 0; i--) {
        ft_printf("%d", (c >> i) & 1);
    }
    ft_printf("\n");
}

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
	print_bit(c);
	ft_printf("\n");
	if ((c & 1) && i != 8)
	{
		ft_printf("ENTROU NO 1\n");
		kill(srv_pid, SIGUSR1);
	}
	if (!(c & 1) && i != 8)
	{
		ft_printf("ENTROU NO 0\n");
		kill(srv_pid, SIGUSR2);
	}
	if (i == 8)
	{
		ft_printf("I = 8: ");
		print_bit(c);
		return ;
	}
	c >>= 1;
	i++;
	send_bit(srv_pid, c);
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
		send_bit(srv_pid, (int)av[2][i]);
	}
}
