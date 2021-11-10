/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:31:55 by eesta             #+#    #+#             */
/*   Updated: 2021/09/03 19:32:02 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	otpravch(char ch, int ids)
{
	int	i;

	i = 128;
	while (i >= 1)
	{
		if (i & ch)
			kill(ids, SIGUSR1);
		else
			kill(ids, SIGUSR2);
		usleep(150);
		i >>= 1;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	j;

	j = 0;
	if (argc == 3)
	{
		pid = f_atoi(argv[1]);
		while (argv[2][j] != '\0')
		{
			otpravch(argv[2][j], pid);
			j++;
		}
		otpravch('\0', pid);
		write(1, "Poluchil\n", 9);
		return (0);
	}
	write (1, "I need 2 arg: id serv and bukvy\n", 32);
	return (-1);
}
