/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:07:56 by iayni             #+#    #+#             */
/*   Updated: 2022/02/28 19:19:02 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_sender(pid_t Pid)
{
	kill(Pid, SIGUSR1);
	usleep(200);
}

void	ft_client_handler(pid_t Pid, char *s)
{
	int		i;
	int		j;
	char	a;
	char	x;

	i = 0;
	while (s[i])
	{
		a = s[i++];
		j = 0;
		while (j < 8)
		{
			x = a & (1 << j);
			if (x == 0)
				kill(Pid, SIGUSR1);
			else
				kill(Pid, SIGUSR2);
			usleep(200);
			j++;
		}
	}
	i = 0;
	while (i++ < 8)
		ft_sender(Pid);
}

void	ft_error(void)
{
	ft_putstr("Something Went Wrong!! Check your Inputs");
	exit(-1);
}

void	recieved(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	(void)info;
	if (sig == SIGUSR1)
		write(1, "Delivered To Server !!", 22);
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	if (ac != 3 || ft_atoi(av[1]) <= 0 || ft_strlen(av[1]) > 6)
		ft_error();
	pid = ft_atoi(av[1]);
	if (kill(pid, 0) == -1)
		ft_error();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &recieved;
	sigaction(SIGUSR1, &sa, NULL);
	ft_client_handler(pid, av[2]);
	while (1)
		pause();
	return (0);
}
