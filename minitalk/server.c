/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 22:31:51 by dabey             #+#    #+#             */
/*   Updated: 2022/01/21 14:38:16 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_joint_char(char *str, char c)
{
	char	*tmp;
	int		i;

	tmp = malloc(ft_strlen(str) + 2);
	if (tmp == NULL)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	if (!str)
	{
		tmp[++i] = c;
		tmp[i + 1] = 0;
	}
	else
	{
		while (str[++i])
			tmp[i] = str[i];
		tmp[i] = c;
		tmp[i + 1] = 0;
		free(str);
	}
	return (tmp);
}

void	sig_handler(int sig, siginfo_t *info, void *context)
{
	static size_t	count;
	static char		c;
	static char		*msg;

	(void) context;
	if (sig == SIGUSR1)
		c |= (1 << count);
	if (sig == SIGUSR2)
		c &= ~(1 << count);
	count++;
	if (count == 8)
	{
		if (c)
			msg = ft_joint_char(msg, c);
		else
		{
			write(1, msg, ft_strlen(msg));
			write(1, "\n", 1);
			free(msg);
			msg = NULL;
			kill(info->si_pid, SIGUSR1);
		}
		count = 0;
		c = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;
	sigset_t			block_mask;

	write(1, "PID: ", 5);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sigemptyset(&block_mask);
	sigaddset(&block_mask, SIGINT);
	sigaddset(&block_mask, SIGQUIT);
	sig.sa_sigaction = sig_handler;
	sig.sa_flags = SA_SIGINFO;
	sig.sa_mask = block_mask;
	if (sigaction(SIGUSR1, &sig, NULL) == -1)
		return (1);
	if (sigaction(SIGUSR2, &sig, NULL) == -1)
		return (1);
	while (1)
		pause();
	return (0);
}
