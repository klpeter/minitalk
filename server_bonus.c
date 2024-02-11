/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:08:04 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/30 18:24:20 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

//each time signal is received the system runs bit_handler
//ucontext is related to extended signal handler function used with SA_SIGINFO
//SA_SIGINFO is needed to retrieve the clients PID
void	bit_handler(int sig, siginfo_t *info, void *ucontext)
{
	static char	c;
	static int	i;
	pid_t		client_pid;

	ucontext = NULL;
	client_pid = info->si_pid;
	if (sig == SIGUSR2)
		c += (1 << i);
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		if (!c)
		{
			ft_printf("\n");
			kill(client_pid, SIGUSR2);
		}
		c = 0;
		i = 0;
	}
}

//sa.sa_mask is the list of the signal blocked from passing to bit_hander
//sigemptyset is emptying the mask, so nothing is blocked from passing
//sigaction(SIGUSR1, &sa, NULL) - NULL is telling it does not  matter how
//the SIGUSR1 was handled before, it has to be handled according my bit_handler
int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = bit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1 or SIGUSR2 handler");
		return (1);
	}
	ft_printf("Welcome to Minitalk Server!\n");
	ft_printf("My server PID is: %d\n", getpid());
	ft_printf("Server is ready to receive your message, please use");
	ft_printf(" ./client command with PID and your message in quotation!\n");
	while (1)
		pause();
	return (0);
}
