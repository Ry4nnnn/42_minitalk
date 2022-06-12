/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welim <welim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 11:43:40 by welim             #+#    #+#             */
/*   Updated: 2022/06/12 11:45:59 by welim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static void	ft_send_binary(int pid, char c)
{
	int	mask;

	mask = 128;
	while (mask > 0)
	{
		if ((c & mask) > 0)
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		mask >>= 1;
		usleep(69);
	}
}

static void	ft_send_msg(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_send_binary(pid, str[i]);
		i++;
	}
	ft_send_binary(pid, 0);
}

static void	ft_success(int sig)
{
	if (sig == SIGUSR1)
		write(1, "Message has been received.\n", 25);
}

int	main(int argc, char **argv)
{
	pid_t				pid;
	char				*str;
	struct sigaction	sa;

	if (argc == 3)
	{	
		pid = ft_atoi(argv[1]);
		str = argv[2];
		sa.sa_handler = &ft_success;
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		ft_send_msg(pid, str);
	}
	else
		ft_putstr_fd("Usage: [PID] [\"Message\"]", 1);
	return (0);
}
