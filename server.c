/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 22:41:51 by adantas-          #+#    #+#             */
/*   Updated: 2023/01/19 22:41:55 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/ft_printf.h"

void	which_signal(int sig, siginfo_t *siginfo, void *context)
{
	static char	letter = 0;
	static int	bit = 0;

	(void)context;
	(void)siginfo;
	if (sig == SIGUSR1)
		letter |= 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", letter);
		letter = 0;
		bit = 0;
	}
	letter <<= 1;
}


int	main(void)
{
	int					pid;
	struct sigaction	s_sa;
	sigset_t			sigset;

	sigemptyset(&sigset);
	sigaddset(&sigset, SIGUSR1);
	sigaddset(&sigset, SIGUSR2);
	s_sa.sa_handler = NULL;
	s_sa.sa_mask = sigset;
	s_sa.sa_flags = SA_SIGINFO;
	s_sa.sa_sigaction = which_signal;
	sigaction(SIGUSR1, &s_sa, NULL);
	sigaction(SIGUSR2, &s_sa, NULL);
	pid = getpid();
	ft_printf("Waiting input for pid: %d\n", pid);
	while (1)
		pause();
}
