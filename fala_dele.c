#include "minitalk.h"
#include "libft/ft_printf.h"

char	g_character = 0;

// "sig = 42;" only to avoid warning
void	add_one(int sig)
{
	g_character++;
	g_character = g_character << 1;
	sig = 42;
}

void	add_zero(int sig)
{
	g_character = g_character << 1;
	sig = 42;
}

void	print_bit(int div)
{
	if (div > 2)
		print_bit(div / 2);
	ft_printf("%d", div % 2);
}

int	main(void)
{
	int	i;
	int	pid;

	pid = getpid();
	ft_printf("Waiting input for pid: %d\n", pid);
	signal(SIGUSR1, add_one);
	signal(SIGUSR2, add_zero);
	while (1)
	{
		i = 0;
		while (i < 8)
		{
			pause();
			i++;
		}
		print_bit(g_character);
		ft_printf("\n");
		g_character = 0;
	}
}
