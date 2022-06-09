#include "../includes/minitalk.h"


// void ft_sig_handler(); 

int main(void)
{
	// struct sigaction	sa;

	// sa.sa_flags = SA_SIGINFO;
	// sa.sa_sigaction = 
	ft_putstr_fd("Server PID : ", 1);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	while (1)
		pause();

	return (0);
}
