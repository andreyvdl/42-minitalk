#include "minitalk.h"
#include "libft/ft_printf.h"

int	main(void)
{
	// if (ac != 3)
	// {
	// 	ft_printf("Error: %s\nUsage ./client <pid> <message>\n", strerror(22));
	// 	exit(22);
	// }
	int pid = getpid();
	ft_printf("o pid desse programa é %d\n", pid);
	ft_printf("vai entrar no pause\n");
	pause();
	ft_printf("saiu do pause\n");
}
