/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psmolich <psmolich@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:46:12 by psmolich          #+#    #+#             */
/*   Updated: 2025/11/27 13:52:39 by psmolich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] && ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && ft_isdigit(str[i]))
	{
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	return (nb * sign);
}
