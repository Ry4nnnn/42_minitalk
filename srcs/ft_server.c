#include "../includes/minitalk.h"

void	ft_handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static int	i;
	static char	c;
	int			bit;

	(void)*ucontext;
	if (sig == SIGUSR1)
		bit = 1;
	else
		bit = 0;
	c <<= 1;
	c += bit;
	i++;
	if (i == 8)
	{
		write(1, &c, 1);
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(info->si_pid, SIGUSR1);
		}
		i = 0;
		c = 0;
	}
}


int main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = &ft_handle_sig;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);	
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
