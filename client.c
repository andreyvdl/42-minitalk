/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 21:06:11 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/19 21:21:58 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"
#include "libft/ft_printf.h"

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
	static int	bit = 0;

	if (bit != 0)
		bit = 0;
	while (bit < 8)
	{
		if (((1 << 7) >> bit) & c)
			kill(srv_pid, SIGUSR1);
		else if (!(((1 << 7) >> bit) & c))
			kill(srv_pid, SIGUSR2);
		usleep(300);
		bit++;
		if (bit == 8)
		{
			bit = 0;
			return ;
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
		send_bit(srv_pid, av[2][i]);
	send_bit(srv_pid, '\n');
}
