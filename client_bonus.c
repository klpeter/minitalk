/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkovacs- <pkovacs-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 19:02:12 by pkovacs-          #+#    #+#             */
/*   Updated: 2024/01/30 18:24:16 by pkovacs-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

// unicode: Café, Über, Niño, Jalapeño, Façade, Fjörður, Łódź, Спасибо, 東京, 대한민국
// 🌍
void	send_bit(pid_t server_pid, char *str, int len)
{
	int	shift;
	int	i;

	i = 0;
	while (i < len)
	{
		shift = 0;
		while (shift < 8)
		{
			if ((str[i] >> shift) & 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			shift++;
			usleep(50);
		}
		i++;
	}
}

void	bit_handler(int sig, siginfo_t *info, void *ucontext)
{
	info = NULL;
	ucontext = NULL;
	if (sig == SIGUSR2)
		ft_printf("%s", "\nThe message is received by the server\n");
}

int	main(int argc, char **argv)
{
	pid_t				server_pid;
	char				*str;
	char				*error_nosignal;
	char				*error_moresignal;
	struct sigaction	sa;

	sa.sa_sigaction = bit_handler;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	error_nosignal = "Error: either no PID or no message was entered!";
	error_moresignal = "For more words use \" \".";
	if (argc != 3 || sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("%s\n%s\n", error_nosignal, error_moresignal);
		return (1);
	}
	else
	{
		server_pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(server_pid, str, ft_strlen(str) + 1);
	}
	return (0);
}
