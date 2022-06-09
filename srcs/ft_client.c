#include "../includes/minitalk.h"

static void ft_send_binary(int pid, char c)
{
	
}

static void ft_send_msg(int pid, char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_send_binary(pid, str[i]);
		i++;
	}
	ft_send_binary(pid, 0);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Message has been received.\n", 25);
}

int main(int argc, char **argv)
{
	pid_t	pid;
	char	*str;
	struct	sigaction sa;
	
	if (argc == 3)
	{	
		pid = ft_atoi(argv[1]);
		str = argv[2];
		// ft_putstr_fd("Message received!\n", 1);
		signal(SIGUSR1, success);
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		ft_send_msg(pid, str);
	}
	else
		ft_putstr_fd("Usage: [PID] [\"Message\"]", 1);
	return (0);
}
