/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liba_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eesta <eesta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:30:19 by eesta             #+#    #+#             */
/*   Updated: 2021/09/03 19:32:40 by eesta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int	f_atoi(const char *str)
{
	int	nbr;
	int	s;
	int	sign;

	nbr = 0;
	s = 0;
	sign = 1;
	while ((str[s] == ' ') || (str[s] >= 9 && str[s] <= 13))
		s++;
	if (str[s] == '-' || str[s] == '+')
	{
		if (str[s] == '-')
			sign = -sign;
		s++;
	}
	while (str[s] >= '0' && str[s] <= '9')
	{
		nbr = nbr * 10 + (str[s] - '0');
		s++;
	}
	return (sign * nbr);
}

size_t	f_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != 0)
		i++;
	return (i);
}
