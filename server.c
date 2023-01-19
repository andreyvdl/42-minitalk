#include "minitalk.h"
#include "libft/ft_printf.h"

void print_bits(char c) {
    for (int i = 7; i >= 0; i--) {
        ft_printf("%d", (c >> i) & 1);
    }
    ft_printf("\n");
}

char	reverse_bits(char c)
{
    char	reversed;
	int		i;

	reversed = 0;
	i = 0;
	while (i < 8)
	{
        reversed = (reversed << 1) | (c & 1);
        c >>= 1;
		i++;
    }
	print_bits(reversed);
    return (reversed);
}
void	which_signal(int sig, siginfo_t *siginfo, void *context)
{
	static char	letter = 0;
	static int	bit = 0;

	(void)context;
	(void)siginfo;
	if (sig == SIGUSR1)
	{
		ft_printf("1");
		letter |= 1;
		letter <<= 1;
		bit++;
		// kill(siginfo->si_pid, SIGUSR1);
	}
	else if (sig == SIGUSR2)
	{
		ft_printf("0");
		letter <<= 1;
		bit++;
		// kill(siginfo->si_pid, SIGUSR2);
	}
	if (bit == 7)
	{
		ft_printf("\nLETTER:\n");
		print_bits(letter);
		ft_printf("\n\nREV BITS:\n");
		reverse_bits(letter);
		ft_printf("\n%c\n", letter);
		letter = 0;
		bit = 0;
	}
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
