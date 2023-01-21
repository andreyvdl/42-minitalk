/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:03:38 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/21 00:18:33 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

static int	g_bit = 0;

void	received(int sig)
{
	if (sig == SIGUSR1)
	{
		g_bit++;
		send_bit(0, 0);
	}
	else
		g_bit = 8;
}

void	validation(int ac, char **av)
{
	size_t	i;
	int		pid;

	if (ac != 3)
	{
		ft_printf("⚠️\tError: Wrong number of arguments.\n");
		ft_printf("❗\tUsage: ./client <PID> <string>\n");
		exit(22);
	}
	i = -1;
	pid = ft_atoi(av[1]);
	while (av[1][++i])
	{
		if (!ft_isdigit(av[1][i]) || pid <= 0)
		{
			ft_printf("⚠️\tError: PID is invalid.\n");
			ft_printf("🔢\tA PID only has positive decimal numbers. ");
			ft_printf("PID 0 is reserved for the kernel.\n");
			exit(22);
		}
	}
}

void	send_bit(int srv_pid, char c)
{
	static int	pid = 0;
	static char	letter = 0;

	if (srv_pid)
		pid = srv_pid;
	if (c)
		letter = c;
	if (g_bit != 0)
		g_bit = 0;
	while (g_bit < 8)
	{
		if (((1 << 7) >> g_bit) & letter)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		pause();
		sleep(1);
	}
}

int	main(int ac, char **av)
{
	size_t	i;
	int		srv_pid;

	signal(SIGUSR1, received);
	signal(SIGUSR2, received);
	validation(ac, av);
	srv_pid = ft_atoi(av[1]);
	i = -1;
	while (av[2][++i])
	{
		send_bit(srv_pid, av[2][i]);
		g_bit = 0;
	}
	send_bit(srv_pid, '\n');
}
