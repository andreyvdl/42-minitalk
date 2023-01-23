/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:06:11 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/23 16:18:19 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

int	g_bit;

void	received(int sig)
{
	if (sig == SIGUSR1)
		g_bit++;
	else if (sig == SIGUSR2)
		g_bit++;
	else
	{
		ft_printf("❗\tError: Signal is invalid.\n");
		exit(22);
	}
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
	while (g_bit < 8)
	{
		if ((128 >> g_bit) & c)
			kill(srv_pid, SIGUSR1);
		else
			kill(srv_pid, SIGUSR2);
		usleep(5000);
		if (g_bit == 8)
		{
			g_bit = 0;
			return ;
		}
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
	g_bit = 0;
	while (av[2][++i])
		send_bit(srv_pid, av[2][i]);
	send_bit(srv_pid, '\n');
	exit(0);
}
