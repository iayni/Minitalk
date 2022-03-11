/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iayni <iayni@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:07:52 by iayni             #+#    #+#             */
/*   Updated: 2022/02/28 19:37:04 by iayni            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int	j;
	static char	b;
	static char	a;

	(void) *ucontext;
	if (sig == SIGUSR1)
		b = 0;
	else
		b = 1;
	a = a | (b << j);
	j++;
	if (j == 8)
	{
		if (a == 0)
			kill(info->si_pid, SIGUSR1);
		else
			write(1, &a, 1);
		a = 0;
		j = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_putstr("Server PID : ");
	ft_putnbr(getpid());
	ft_putstr("\n");
	sa.sa_flags = SA_SIGINFO | SA_NODEFER;
	sa.sa_sigaction = ft_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
