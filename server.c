/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:09:50 by eesta             #+#    #+#             */
/*   Updated: 2021/09/21 10:08:28 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_oks;

char	*dobavit_char(char *g_oks, char ch)
{
	char	*src;
	int		i;

	i = f_strlen(g_oks);
	if (ch != '\0')
	{
		src = (char *)malloc(i + 2);
		i = 0;
		while (g_oks[i])
		{
			src[i] = g_oks[i];
			i++;
		}
		src[i] = ch;
		src[++i] = '\0';
		free(g_oks);
		return (src);
	}
	write (1, g_oks, i);
	write (1, "\n", 1);
	free(g_oks);
	return (NULL);
}

void	id_print_proc(int id)
{
	char	c;
	int		j;
	int		i;

	j = 1;
	i = id;
	while (id > 10)
	{
		j *= 10;
		id /= 10;
	}
	while (j != 0)
	{
		id = (i / j);
		c = id % 10 + '0';
		write(1, &c, 1);
		j /= 10;
	}
	write (1, "\n", 1);
}

void	s_handler(int id, siginfo_t *sig, void *s)
{
	static int	ch;
	static int	bt;

	s = NULL;
	if (id == SIGUSR1)
		ch += 128 >> bt;
	bt++;
	if (bt == 8)
	{
		g_oks = dobavit_char(g_oks, ch);
		if (!g_oks)
		{
			g_oks = (char *)malloc(sizeof(char));
			g_oks[0] = '\0';
			write(1, "Poluchil eto message:", 21);
			id_print_proc(sig->si_pid);
		}
		ch = 0;
		bt = 0;
	}
}

int	main(void)
{
	struct sigaction	rr;
	int					pid;

	pid = getpid();
	rr.sa_sigaction = &s_handler;
	write(1, "Yes, this is my ID. Send me everything:", 40);
	id_print_proc(pid);
	g_oks = (char *)malloc(sizeof(char));
	g_oks[0] = '\0';
	rr.sa_flags = SA_RESTART | SA_SIGINFO;
	sigaction(SIGUSR1, &rr, NULL);
	sigaction(SIGUSR2, &rr, NULL);
	while (1)
		pause();
}
