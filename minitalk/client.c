/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:20:36 by dabey             #+#    #+#             */
/*   Updated: 2022/01/06 22:35:16 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	print_resp(int sig)
{
	(void)sig;
	write(1, "Message received!\n", 18);
	exit(1);
}

int	send_mssg(int pid, char *mssg, int len_mssg)
{
	int	count;
	int	bit;

	count = 0;
	bit = 0;
	while (count <= len_mssg)
	{
		while (bit < 8)
		{
			if ((mssg[count] >> bit) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(200);
			bit++;
		}
		bit = 0;
		count++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		write(1, "Please give the PID and message that you want send\n", 51);
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	signal(SIGUSR1, print_resp);
	send_mssg(pid, argv[2], ft_strlen(argv[2]));
	while (1)
		pause();
	return (0);
}
