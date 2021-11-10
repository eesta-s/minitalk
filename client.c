/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:09:31 by eesta             #+#    #+#             */
/*   Updated: 2021/09/21 10:03:31 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		usleep(50);
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
		write(1, "Poluchil\n", 9);
		otpravch('\0', pid);
		return (0);
	}
	write (1, "I need 2 arg: id serv and bukvy\n", 32);
	return (-1);
}
