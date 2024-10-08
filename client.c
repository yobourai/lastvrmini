/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yobourai <yobourai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 21:29:35 by yobourai          #+#    #+#             */
/*   Updated: 2024/09/06 01:34:28 by yobourai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_bin(int a)
{
	static char	bin[9];
	int			i;
	char		flag;

	flag = (char)a;
	i = 7;
	while (i >= 0)
	{
		bin[i] = (a % 2) + '0';
		a = a / 2;
		i--;
	}
	i++;
	bin[8] = '\0';
	while (i > 0)
	{
		bin[i] = '0';
		i++;
	}
	return (bin);
}

void	ft_send_signal(char *pid, char *s)
{
	int	i;

	i = 0;
	while (i <= 7)
	{
		if (s[i] == '0')
			kill(ft_atoi(pid), SIGUSR1);
		else if (s[i] == '1')
			kill(ft_atoi(pid), SIGUSR2);
		usleep(500);
		i++;
	}
}

void	ft_hand(int sig)
{
	if (sig == SIGUSR1)
		exit(1);
}

int	main(int argc, char *argv[])
{
	int	i;

	signal(SIGUSR1, ft_hand);
	if (argc != 3 || !*argv[2])
	{
		ft_putstr("<./client> <PID> <Message> \n");
		exit(1);
	}
	i = 0;
	if (ft_atoi(argv[1]) <= 10 || kill(ft_atoi(argv[1]), SIGUSR1) == -1)
	{
		ft_putstr("pid error\n");
		exit(1);
	}
	while (argv[2][i] != '\0')
	{
		ft_send_signal(argv[1], ft_bin(argv[2][i]));
		i++;
	}
	if (!argv[2][i])
		ft_putstr("message has been saved successfuly\n");
	return (0);
}
